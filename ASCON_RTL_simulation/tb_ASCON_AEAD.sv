`timescale 1ns/10ps

module tb_ASCON_AEAD();

    localparam CLK_PERIOD = 1;
    localparam A = 12;
    localparam B = 6;

    logic clk, rst;
    logic tb_start, tb_startAD, tb_startT, tb_enc;
    logic [127:0] tb_key, tb_nonce;
    logic [63:0] tb_ADblock, tb_PTblock;
    logic [3:0] tb_PTlen, tb_ADlen;
    
    logic [127:0] tb_T;
    logic [63:0] tb_CTblock;
    logic tb_CTv, tb_Tv, tb_read;

    logic [127:0] randin;
    logic [6:0] sample_out;
    logic sample_good;

    integer fd_in, status, i, PT_blocks, AD_blocks, check_flag, error_flag;
    logic [127:0] read_128;
    logic [63:0] read_64;
    logic [3:0] PT_len, AD_len;
    logic [7:0] check_byte_ct, check_byte_gold;


    ASCON_AEAD DUT(
        .clk(clk),
        .rst(rst),
        .start(tb_start),
        .startAD(tb_startAD),
        .startT(tb_startT),
        .enc(tb_enc),
        .key(tb_key),
        .nonce(tb_nonce),
        .ADblock(tb_ADblock),
        .PTblock(tb_PTblock),
        .PTlen(tb_PTlen),
        .ADlen(tb_ADlen),

        .T(tb_T),
        .CTblock(tb_CTblock),
        .CTv(tb_CTv),
        .Tv(tb_Tv),
        .read(tb_read)
    );

    task reset_dut;
    begin
        // Activate the reset
        rst = 1'b1;

        // Maintain the reset for more than one cycle
        @(posedge clk);
        @(posedge clk);

        // Wait until safely away from rising edge of the clock before releasing
        @(negedge clk);
        rst = 1'b0;

        // Leave out of reset for a couple cycles before allowing other stimulus
        // Wait for negative clock edges, 
        // since inputs to DUT should normally be applied away from rising clock edges
        @(negedge clk);
        @(negedge clk);
    end
    endtask

    task test_encryption;
        input int fd_in;
    begin
        @(negedge clk);
        tb_start = 1;
        @(negedge clk);
        tb_start = 0;
        status = $fscanf(fd_in, "%h", read_128);
        tb_key = read_128;
        status = $fscanf(fd_in, "%h", read_128);
        tb_nonce = read_128;
        //initialization
        repeat(A)
            @(negedge clk);

        //Associated Data
        for(int j = 0; j < AD_blocks; j++) begin
            tb_startAD = (j == 0) ? 1'b1 : 1'b0; //assert startAD for first block (may be able to do this for all blocks but only necessary for block 1)
            tb_ADlen = (j == (AD_blocks - 1)) ? AD_len : 4'd8; //if more than 1 AD block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read block data from file
            tb_ADblock = read_64; //assign block data to tb_ADblock
            repeat(B) //do permutations
                @(negedge clk);
        end
        if(AD_len == 4'd8 && AD_blocks > 0) begin //if AD is a perfect multiple of 64 bits, need to run one padding block
            tb_ADlen = '0;
            repeat(B)
                @(negedge clk);
        end


        //Plaintext
        for(int j = 0; j < PT_blocks; j++) begin
            tb_startT = 1'b1; //tb_startT along with enc needs to be asserted for all PT blocks
            tb_enc = 1;
            tb_PTlen = (j == (PT_blocks - 1)) ? PT_len : 4'd8; //if more than 1 PT block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read PT blovk from file
            tb_PTblock = read_64;
            #0.1; //give sim time for data to propogate
            status = $fscanf(fd_in, "%h", read_64); //read expected CT block from file
            
            if(tb_CTv == '0) begin //make sure CTv is correctly asserted
                $info("CTv not correctly asserted for test input %d", i);
                error_flag = 1;
            end

            check_flag = 0;
            for(int k = 0; k < PT_len; k++)begin //check as many ciphertect bytes as there are plaintext bytes
                check_byte_ct = tb_CTblock >> (56 - (8 * k));
                check_byte_gold = read_64 >> (56 - (8 * k));
                if(check_byte_ct != check_byte_gold)
                    check_flag = 1;
            end

            if(check_flag == 0) //if all checked ciphertexts bytes match expected value then no error
                $info("Correct Ciphertext Block %d for test input %d", j, i);
            else begin
                $info("Incorrect Ciphertext Block %d for test input %d. Expecting %h Actual %h", j, i, read_128, tb_T);
                error_flag = 1;
            end


            if(tb_PTlen == 8 && PT_blocks > 0) begin //if this is not the last PT block it nust go through the permutations
                repeat(B)
                    @(negedge clk);
            end
        end

        if(PT_len == 8) begin //if PT length is a multiple of 64 bits need to set tb_PTlen to zero so module recognizes padding block (no CT block is generated according to pyascon?)
            tb_PTlen = '0;
            tb_startT = '0;
        end

        //tag Generation
        repeat(A) begin
            @(negedge clk);
            tb_enc = 0;
        end
        status = $fscanf(fd_in, "%h", read_128); //read expected tag from input file

        if(tb_Tv == '0) begin //mag sure Tv is asserted correctly
            $info("Tv not correctly asserted for test input %d", i);
            error_flag = 1;
        end

        if(tb_T == read_128) //make sure correct tag is output
            $info("Correct tag for test input %d", i);
        else begin
            $info("Incorrect tag for test input %d. Expecting %h Actual %h", i, read_128, tb_T);
            error_flag = 1;
        end

        repeat(3) //give some space between encryptions (would probably also work without this)
            @(negedge clk);
    end
    endtask

    always
    begin
        // Start with clock low to avoid false rising edge events at t=0
        clk = 1'b0;
        // Wait half of the clock period before toggling clock value (maintain 50% duty cycle)
        #(CLK_PERIOD/2.0);
        clk = 1'b1;
        // Wait half of the clock period before toggling clock value via rerunning the block (maintain 50% duty cycle)
        #(CLK_PERIOD/2.0);
    end

    initial begin
        rst = '0;
        tb_start = '0;
        tb_startAD = '0;
        tb_startT = '0;
        tb_enc = '0;
        tb_key = '0;
        tb_nonce = '0;
        tb_ADblock = '0;
        tb_PTblock = '0;
        tb_PTlen = '0;
        tb_ADlen = '0;
        check_flag = 0;

        i = 1;
        error_flag = 0;

        reset_dut();
        #1;

        fd_in = $fopen("translated_blocks.txt", "r"); //open input vector file
        while($fscanf(fd_in, "%d %d %d %d", PT_blocks, PT_len, AD_blocks, AD_len) != -1) begin //run until reach EOF
            test_encryption(fd_in); //test encryption on given test vecotor
            i++;
            if(error_flag == 1) //stop simulation if any error is detected
                break;
        end

        $fclose(fd_in);

        if(error_flag == 0)
            $info("Congrats! All Tests Pass");

        $stop(); //allows "run -all" in modelsim
        
    end

endmodule
`timescale 1ns/10ps

module tb_ASCON_AEAD_DOM();

    localparam CLK_PERIOD = 1;
    localparam A = 12;
    localparam B = 6;

    logic clk, nRST;
    logic tb_start;
    logic tb_DOM_en;
    logic [1:0] tb_mode;
    logic [127:0] tb_key, tb_nonce;
    logic [319:0] tb_randbits;
    logic [63:0] tb_blockin;
    logic [3:0] tb_datalen;
    
    logic [127:0] tb_Tag;
    logic [63:0] tb_CTblock;
    logic tb_CTv, tb_Tv;

    logic [127:0] randin;
    logic [6:0] sample_out;
    logic sample_good;

    integer fd_in, status, i, k, CT_blocks, PT_blocks, AD_blocks, check_flag, error_flag;
    logic [127:0] read_128;
    logic [63:0] read_64, read_64_CT;
    logic [3:0] CT_len, PT_len, AD_len;
    logic [7:0] check_byte_ct, check_byte_gold;
    string dummyline;
    int last_read, actual_index;

    int max_vectors = 1000000;


    ASCON_AEAD_DOM DUT(
        .clk(clk),
        .nRST(nRST),
        .start(tb_start),
        .DOM_en(tb_DOM_en),
        .mode(tb_mode),
        .key(tb_key),
        .nonce(tb_nonce),
        .randbits(tb_randbits),
        .blockin(tb_blockin),
        .datalen(tb_datalen),

        .Tag(tb_Tag),
        .CTblock(tb_CTblock),
        .CTv(tb_CTv),
        .Tv(tb_Tv)
    );

    task reset_dut;
    begin
        // Activate the reset
        nRST = 1'b0;

        // Maintain the reset for more than one cycle
        @(posedge clk);
        @(posedge clk);

        // Wait until safely away from rising edge of the clock before releasing
        @(negedge clk);
        nRST = 1'b1;

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
        int j;
        tb_blockin = '0;
        tb_datalen = '0;

        tb_mode = 2'd1;
        if(AD_blocks > 0) begin
            tb_mode[1] = 1'b1;
            tb_datalen = (AD_blocks < 2) ? AD_len : 4'd8;
        end
        else if(PT_blocks > 0) begin
            tb_datalen = (PT_blocks < 2) ? PT_len : 4'd8;
        end
        status = $fscanf(fd_in, "%h", read_128);
        tb_key = read_128;
        status = $fscanf(fd_in, "%h", read_128);
        tb_nonce = read_128;
        @(negedge clk);
        tb_start = 1;
        if(tb_DOM_en)
            @(negedge clk);
        //initialization
        repeat(A)
            @(negedge clk);
            tb_start = 0;

        //Associated Data
        for(j = 0; j < AD_blocks; j++) begin
            tb_datalen = (j == (AD_blocks - 1)) ? AD_len : 4'd8; //if more than 1 AD block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read block data from file
            tb_blockin = read_64; //assign block data to tb_blockin
            repeat(B) begin //do permutations
                @(negedge clk);
                tb_datalen = (PT_blocks < 2) ? PT_len : 4'd8;
                //tb_datalen = '0;
            end
        end
        if(AD_len == 4'd8 && AD_blocks > 0) begin //if AD is a perfect multiple of 64 bits, need to run one padding block
            tb_datalen = '0;
            repeat(B) begin
                @(negedge clk);
                tb_datalen = (PT_blocks < 2) ? PT_len : 4'd8;
            end
        end


        //Plaintext
        for(j = 0; j < PT_blocks; j++) begin
            tb_datalen = (j == (PT_blocks - 1)) ? PT_len : 4'd8; //if more than 1 PT block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read PT blovk from file
            tb_blockin = read_64;
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
                $info("Incorrect Ciphertext Block %d for test input %d. Expecting %h Actual %h", j, i, read_128, tb_Tag);
                error_flag = 1;
            end


            if(tb_datalen == 8 && PT_blocks > 0) begin //if this is not the last PT block it nust go through the permutations
                repeat(B) begin
                    @(negedge clk);
                    tb_datalen = ((j+1) == (PT_blocks - 1)) ? PT_len : 4'd8;
                    if(PT_len == 8 && (j == (PT_blocks - 1)))
                        tb_datalen = '0;
                end
            end
        end

        /*if(PT_len == 8) begin //if PT length is a multiple of 64 bits need to set tb_datalen to zero so module recognizes padding block (no CT block is generated according to pyascon?)
            tb_datalen = '0;
        end*/

        //tag Generation
        repeat(A) begin
            @(negedge clk);
        end
        status = $fscanf(fd_in, "%h", read_128); //read expected tag from input file

        if(tb_Tv == '0) begin //mag sure Tv is asserted correctly
            $info("Tv not correctly asserted for test input %d", i);
            error_flag = 1;
        end

        if(tb_Tag== read_128) //make sure correct tag is output
            $info("Correct tag for test input %d", i);
        else begin
            $info("Incorrect tag for test input %d. Expecting %h Actual %h", i, read_128, tb_Tag);
            error_flag = 1;
        end

        repeat(3) //give some space between encryptions (would probably also work without this)
            @(negedge clk);
    end
    endtask

    task test_decryption;
        input int fd_in;
    begin
        int j;
        tb_blockin = '0;
        tb_datalen = '0;

        tb_mode = 2'd0;
        if(AD_blocks > 0) begin
            tb_mode[1] = 1'b1;
            tb_datalen = (AD_blocks < 2) ? AD_len : 4'd8;
        end
        else if(CT_blocks > 0) begin
            tb_datalen = (CT_blocks < 2) ? CT_len : 4'd8;
        end
        status = $fscanf(fd_in, "%h", read_128);
        tb_key = read_128;
        status = $fscanf(fd_in, "%h", read_128);
        tb_nonce = read_128;
        @(negedge clk);
        tb_start = 1;
        if(tb_DOM_en)
            @(negedge clk);
        //initialization
        repeat(A)
            @(negedge clk);
            tb_start = 0;

        //Associated Data
        for(j = 0; j < AD_blocks; j++) begin
            tb_datalen = (j == (AD_blocks - 1)) ? AD_len : 4'd8; //if more than 1 AD block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read block data from file
            tb_blockin = read_64; //assign block data to tb_blockin
            repeat(B) begin //do permutations
                @(negedge clk);
                tb_datalen = (CT_blocks < 2) ? CT_len : 4'd8;
                //tb_datalen = '0;
            end
        end
        if(AD_len == 4'd8 && AD_blocks > 0) begin //if AD is a perfect multiple of 64 bits, need to run one padding block
            tb_datalen = '0;
            repeat(B) begin
                @(negedge clk);
                tb_datalen = (CT_blocks < 2) ? CT_len : 4'd8;
            end
        end

        //Ciphertext
        for(int j = 0; j < CT_blocks; j++) begin
            tb_datalen = (j == (CT_blocks - 1)) ? CT_len : 4'd8; //if more than 1 CT block, all blocks except last block are guarunteed length = 8
            status = $fscanf(fd_in, "%h", read_64); //read PT block from file
            status = $fscanf(fd_in, "%h", read_64_CT); //read expected CT block from file
            tb_blockin = read_64_CT;
            #0.1; //give sim time for data to propogate
            
            if(tb_CTv == '0) begin //make sure CTv is correctly asserted
                $info("CTv not correctly asserted for test input %d", i);
                error_flag = 1;
            end

            check_flag = 0;
            for(int k = 0; k < CT_len; k++)begin //check as many plaintext bytes as there are ciphertext bytes
                check_byte_ct = tb_CTblock >> (56 - (8 * k));
                check_byte_gold = read_64 >> (56 - (8 * k));
                if(check_byte_ct != check_byte_gold)
                    check_flag = 1;
            end

            if(check_flag == 0) //if all checked ciphertexts bytes match expected value then no error
                $info("Correct Plaintexttext Block %d for test input %d", j, i);
            else begin
                $info("Incorrect Plainttext Block %d for test input %d. Expecting %h Actual %h", j, i, read_64, tb_CTblock);
                error_flag = 1;
            end


            if(tb_datalen == 8 && CT_blocks > 0) begin //if this is not the last PT block it nust go through the permutations
                repeat(B) begin
                    @(negedge clk);
                    tb_datalen = ((j+1) == (CT_blocks - 1)) ? CT_len : 4'd8;
                    if(CT_len == 8 && (j == (CT_blocks - 1)))
                        tb_datalen = '0;
                end
            end
        end

        /*if(CT_len == 8) begin //if PT length is a multiple of 64 bits need to set tb_PTlen to zero so module recognizes padding block (no CT block is generated according to pyascon?)
            tb_datalen = '0;
        end*/

        //tag Generation
        repeat(A) begin
            @(negedge clk);
        end
        status = $fscanf(fd_in, "%h", read_128); //read expected tag from input file

        if(tb_Tv == '0) begin //mag sure Tv is asserted correctly
            $info("Tv not correctly asserted for test input %d", i);
            error_flag = 1;
        end

        if(tb_Tag== read_128) //make sure correct tag is output
            $info("Correct tag for test input %d", i);
        else begin
            $info("Incorrect tag for test input %d. Expecting %h Actual %h", i, read_128, tb_Tag);
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
        if(tb_DOM_en)
            tb_randbits = {$urandom(), $urandom(), $urandom(), $urandom(), $urandom(), $urandom(), $urandom(), $urandom(), $urandom(), $urandom()};
        else
            tb_randbits = '0;
        // Wait half of the clock period before toggling clock value via rerunning the block (maintain 50% duty cycle)
        #(CLK_PERIOD/2.0);
    end

    initial begin
        nRST = '1;
        tb_start = '0;
        tb_DOM_en = 1'b1;
        tb_mode = '0;
        tb_key = '0;
        tb_nonce = '0;
        tb_blockin = '0;
        tb_blockin = '0;
        tb_datalen = '0;
        check_flag = 0;

        i = 1;
        error_flag = 0;

        last_read = 0;
        actual_index = 1;

        reset_dut();
        #1;

        fd_in = $fopen("source/translated_blocks.txt", "r"); //open input vector file
        while($fscanf(fd_in, "%d %d %d %d", PT_blocks, PT_len, AD_blocks, AD_len) != -1) begin //run until reach EOF
            if(i > max_vectors)
                break;
            test_encryption(fd_in); //test encryption on given test vecotor
            i++;
            if(error_flag == 1) //stop simulation if any error is detected
                break;
        end
        $fclose(fd_in);

        i = 1;
        k = 0;
        fd_in = $fopen("source/translated_blocks.txt", "r"); //open input vector file
        while($fscanf(fd_in, "%d %d %d %d", CT_blocks, CT_len, AD_blocks, AD_len) != -1) begin //run until reach EOF
            if(error_flag == 1) begin//stop simulation if any error is detected
                $info("%s", dummyline);
                break;
            end
            if(i > max_vectors)
                break;
            if(CT_blocks > 0) begin
                test_decryption(fd_in); //test encryption on given test vecotor
                i++;
            end
            else begin
                //$info("%d %d", actual_index, last_read);
                if(actual_index != last_read) begin
                    #(0.1);
                    status = $fgets(dummyline, fd_in); //random blank line
                end
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in key
                //$info("%s", dummyline);
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in nonce
                //$info("%s", dummyline);
                for(int j = 0; j < AD_blocks; j++) begin
                    #(0.1);
                    status = $fgets(dummyline, fd_in); //read in AD blocks
                    //$info("%s", dummyline);
                end
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in tag
                //$info("%s end", dummyline);
                last_read = actual_index;
            end
            actual_index += 1;
        end
        $fclose(fd_in);

        i = 1;

        tb_DOM_en = 1'b0;
        @(negedge clk);
        @(negedge clk);
        @(negedge clk);
        $info("Turning protection off");

        fd_in = $fopen("source/translated_blocks.txt", "r"); //open input vector file
        while($fscanf(fd_in, "%d %d %d %d", PT_blocks, PT_len, AD_blocks, AD_len) != -1) begin //run until reach EOF
            if(error_flag == 1) //stop simulation if any error is detected
                    break;
            if(i > max_vectors)
                break;
            test_encryption(fd_in); //test encryption on given test vecotor
            i++;
        end
        $fclose(fd_in);

        i = 1;
        k = 0;
        last_read = 0;
        actual_index = 1;

        fd_in = $fopen("source/translated_blocks.txt", "r"); //open input vector file
        while($fscanf(fd_in, "%d %d %d %d", CT_blocks, CT_len, AD_blocks, AD_len) != -1) begin //run until reach EOF
            if(error_flag == 1) begin//stop simulation if any error is detected
                $info("%s", dummyline);
                break;
            end
            if(i > max_vectors)
                break;
            if(CT_blocks > 0) begin
                test_decryption(fd_in); //test encryption on given test vecotor
                i++;
            end
            else begin
                //$info("%d %d", actual_index, last_read);
                if(actual_index != last_read) begin
                    #(0.1);
                    status = $fgets(dummyline, fd_in); //random blank line
                end
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in key
                //$info("%s", dummyline);
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in nonce
                //$info("%s", dummyline);
                for(int j = 0; j < AD_blocks; j++) begin
                    #(0.1);
                    status = $fgets(dummyline, fd_in); //read in AD blocks
                    //$info("%s", dummyline);
                end
                #(0.1);
                status = $fgets(dummyline, fd_in); //read in tag
                //$info("%s end", dummyline);
                last_read = actual_index;
            end
            actual_index += 1;
        end

        $fclose(fd_in);

        if(error_flag == 0)
            $info("Congrats! All Tests Pass");

        $stop(); //allows "run -all" in modelsim
        
    end

endmodule
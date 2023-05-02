module ASCON_CONTROLER_DOM #(
    parameter A = 12,
    parameter B = 6
)
(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic DOM_en,
    input logic [1:0] mode,
    input logic [127:0] key,
    input logic [127:0] nonce,
    input logic [319:0] randbits,
    input logic [3:0] datalen,
    input logic [63:0] blockin,
    input logic [63:0] Xo0_sh0,
    input logic [63:0] Xo1_sh0,
    input logic [63:0] Xo2_sh0,
    input logic [63:0] Xo3_sh0,
    input logic [63:0] Xo4_sh0,
    input logic [63:0] Xo0_sh1,
    input logic [63:0] Xo1_sh1,
    input logic [63:0] Xo2_sh1,
    input logic [63:0] Xo3_sh1,
    input logic [63:0] Xo4_sh1,
    output logic [127:0] Tag,
    output logic [63:0] CTblock,
    output logic CTv,
    output logic Tv,
    output logic read,
    output logic passthrough_en,
    output logic [1:0] rcmode,
    output logic [3:0] rcinit,
    output logic [2:0] state_out,
    output logic [63:0] Xi0_sh0,
    output logic [63:0] Xi1_sh0,
    output logic [63:0] Xi2_sh0,
    output logic [63:0] Xi3_sh0,
    output logic [63:0] Xi4_sh0,
    output logic [63:0] Xi0_sh1,
    output logic [63:0] Xi1_sh1,
    output logic [63:0] Xi2_sh1,
    output logic [63:0] Xi3_sh1,
    output logic [63:0] Xi4_sh1,
    output logic state_update
);
    
    typedef enum logic [2:0] {
        idle,
        load_share,
        intialize,
        AD,
        PT,
        CT,
        finalize
    } state_t;

    state_t state, next_state;
    logic [3:0] count, next_count;
    logic [3:0] last_len, nlast_len;
    logic [63:0] CT_sh0, pado, pado2;

    assign state_out = state;

    assign Tag = {Xo3_sh0,Xo4_sh0} ^ {Xo3_sh1,Xo4_sh1} ^ key;
    assign CT_sh0 = Xo0_sh0 ^ pado;
    assign CTblock = CT_sh0 ^ Xo0_sh1; 
    ASCONpadding asconpad1 (blockin,datalen,pado);
    ASCONpadding asconpad2 (CTblock,datalen,pado2);

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 0) begin
            state <= idle;
            count <= '0;
            last_len <= '0;
        end
        else begin
            state <= next_state;
            count <= next_count;
            last_len <= nlast_len;
        end
    end

    always_comb begin
        next_state = state;
        next_count = count + 1;
        nlast_len = last_len;

        CTv = '0;
        Tv = '0;
        read = '0;
        rcmode = '0;
        rcinit = '0;
        Xi0_sh0 = Xo0_sh0;
        Xi1_sh0 = Xo1_sh0;
        Xi2_sh0 = Xo2_sh0;
        Xi3_sh0 = Xo3_sh0;
        Xi4_sh0 = Xo4_sh0;

        Xi0_sh1 = Xo0_sh1;
        Xi1_sh1 = Xo1_sh1;
        Xi2_sh1 = Xo2_sh1;
        Xi3_sh1 = Xo3_sh1;
        Xi4_sh1 = Xo4_sh1;
        passthrough_en = '0;

        state_update = '0;

        case(state)
            idle: begin
                Xi0_sh0 = 64'h80400c0600000000;
                Xi1_sh0 = key[127:64];
                Xi2_sh0 = key[63:0];
                Xi3_sh0 = nonce[127:64];
                Xi4_sh0 = nonce[63:0];
                if(start == 1) begin
                    if(DOM_en == 1'b1) begin
                        passthrough_en = 1'b1;
                        next_state = load_share;
                        Xi0_sh1 = randbits[319:256];
                        Xi1_sh1 = randbits[255:192];
                        Xi2_sh1 = randbits[191:128];
                        Xi3_sh1 = randbits[127:64];
                        Xi4_sh1 = randbits[63:0];
                    end
                    else begin
                        rcmode = 2'd3;
                        rcinit = 4'd1;
                        next_state = intialize;
                        next_count = 1;
                        Xi0_sh1 = '0;
                        Xi1_sh1 = '0;
                        Xi2_sh1 = '0;
                        Xi3_sh1 = '0;
                        Xi4_sh1 = '0;
                    end
                end
            end
            load_share: begin
                Xi0_sh0 = 64'h80400c0600000000 ^ Xo0_sh1;
                Xi1_sh0 = key[127:64] ^ Xo1_sh1;
                Xi2_sh0 = key[63:0] ^ Xo2_sh1;
                Xi3_sh0 = nonce[127:64] ^ Xo3_sh1;
                Xi4_sh0 = nonce[63:0] ^ Xo4_sh1;
                rcmode = 2'd3;
                rcinit = 4'd1;
                next_state = intialize;
                next_count = 1;
            end
            intialize: begin
                if(count == 1)
                    state_update = 1'b1;
                if(mode[1] || datalen == 4'd8)
                    rcmode = 2'd2;
                else
                    rcmode = 2'd1;
                Xi0_sh0 = Xo0_sh0;
                Xi1_sh0 = Xo1_sh0;
                Xi2_sh0 = Xo2_sh0;
                Xi3_sh0 = Xo3_sh0;
                Xi4_sh0 = Xo4_sh0;
                if(count == A) begin
                    next_count = 1;
                    rcmode = 2'd3;
                    Xi3_sh0 = Xo3_sh0 ^ key[127:64];
                    case(mode)
                        2'd0: begin
                            Xi4_sh0 = Xo4_sh0 ^ key[63:0]^1;
                            CTv = (datalen == '0) ? 1'b0 : 1'b1;
                            read = 1'b1;
                            if(datalen == 4'd8) begin
                                Xi0_sh0 = blockin ^ Xo0_sh1;
                                //Xi0_sh1 = blockin ^ Xo0_sh0;
                                next_state = CT;
                                rcinit = 4'b0111;
                            end
                            else begin
                                Xi0_sh0 = pado2 ^ Xo0_sh0;
                                rcinit = 4'b0001;
                                next_state = finalize;
                                Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                                Xi2_sh0 = Xo2_sh0 ^ key[63:0];
                            end
                        end
                        2'd1: begin
                            Xi0_sh0 = CT_sh0;
                            Xi4_sh0 = Xo4_sh0 ^ key[63:0]^1;
                            CTv = (datalen == '0) ? 1'b0 : 1'b1;
                            read = 1'b1;
                            if(datalen == 4'd8) begin
                                next_state = PT;
                                rcinit = 4'b0111;
                            end
                            else begin
                                next_state = finalize;
                                rcinit = 4'b0001;
                                Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                                Xi2_sh0 = Xo2_sh0 ^ key[63:0];
                            end
                        end
                        2'd2: begin
                            next_state = AD;
                            read = 1'b1;
                            nlast_len = datalen;
                            rcinit = 4'b0111;
                            Xi0_sh0 = CT_sh0;//CTblock;
                            Xi4_sh0 = Xo4_sh0 ^ key[63:0];
                        end
                        2'd3: begin
                            next_state = AD;
                            read = 1'b1;
                            nlast_len = datalen;
                            rcinit = 4'b0111;
                            Xi0_sh0 = CT_sh0;//CTblock;
                            Xi4_sh0 = Xo4_sh0 ^ key[63:0];
                        end
                    endcase
                end
            end
            AD: begin
                if(last_len == 4'd8 || datalen == 4'd8)
                    rcmode = 2'd2;
                else
                    rcmode = 2'd1;
                Xi0_sh0 = Xo0_sh0;
                Xi1_sh0 = Xo1_sh0;
                Xi2_sh0 = Xo2_sh0;
                Xi3_sh0 = Xo3_sh0;
                Xi4_sh0 = Xo4_sh0;
                if(count == B) begin
                    next_count = 1;
                    rcmode = 2'd3;
                    read = 1'b1;
                    if(last_len == 4'd8) begin //this needs to change to last_len (registered)
                        nlast_len = datalen;
                        rcinit = 4'b0111;
                        Xi0_sh0 = CT_sh0;//CTblock;
                    end
                    else if(mode[0] == 1) begin
                        CTv = (datalen == '0) ? 1'b0 : 1'b1;
                        Xi0_sh0 = CT_sh0;//CTblock;
                        Xi4_sh0 = Xo4_sh0 ^ 1;
                        if(datalen == 4'd8) begin
                            rcinit = 4'b0111;
                            next_state = PT;
                        end
                        else begin
                            rcinit = 4'b0001;
                            Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                            Xi2_sh0 = Xo2_sh0 ^ key[63:0] ;
                            next_state = finalize;
                        end
                    end
                    else begin
                        CTv = (datalen == '0) ? 1'b0 : 1'b1;
                        Xi4_sh0 = Xo4_sh0 ^ 1;
                        if(datalen == 4'd8) begin
                            Xi0_sh0 = blockin ^ Xo0_sh1;
                            rcinit = 4'b0111;
                            next_state = CT;
                        end
                        else begin
                            rcinit = 4'b0001;
                            Xi0_sh0 = pado2 ^ Xo0_sh0;;
                            Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                            Xi2_sh0 = Xo2_sh0 ^ key[63:0];
                            next_state = finalize;
                        end
                    end
                end
            end
            PT: begin
                if(datalen == 4'd8)
                    rcmode = 2'd2;
                else
                    rcmode = 2'd1;
                Xi0_sh0 = Xo0_sh0;
                Xi1_sh0 = Xo1_sh0;
                Xi2_sh0 = Xo2_sh0;
                Xi3_sh0 = Xo3_sh0;
                Xi4_sh0 = Xo4_sh0;
                if(count == B) begin
                    next_count = 1;
                    rcmode = 2'd3;
                    Xi0_sh0 = CT_sh0;//CTblock;
                    CTv = (datalen == '0) ? 1'b0 : 1'b1;
                    read = 1'b1;
                    if(datalen == 4'd8) begin
                        rcinit = 4'b0111;
                    end
                    else begin
                        rcinit = 4'b0001;
                        Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                        Xi2_sh0 = Xo2_sh0 ^ key[63:0];
                        next_state = finalize;
                    end
                end
            end
            CT: begin
                if(datalen == 4'd8)
                    rcmode = 2'd2;
                else
                    rcmode = 2'd1;
                Xi0_sh0 = Xo0_sh0;
                Xi1_sh0 = Xo1_sh0;
                Xi2_sh0 = Xo2_sh0;
                Xi3_sh0 = Xo3_sh0;
                Xi4_sh0 = Xo4_sh0;
                if(count == B) begin
                    next_count = 1;
                    rcmode = 2'd3;
                    CTv = (datalen == '0) ? 1'b0 : 1'b1;
                    read = 1'b1;
                    if(datalen == 4'd8) begin
                        Xi0_sh0 = blockin ^ Xo0_sh1;
                        rcinit = 4'b0111;
                    end
                    else begin
                        rcinit = 4'b0001;
                        Xi0_sh0 = pado2 ^ Xo0_sh0;
                        Xi1_sh0 = Xo1_sh0 ^ key[127:64];
                        Xi2_sh0 = Xo2_sh0 ^ key[63:0];
                        next_state = finalize;
                    end
                end
            end
            finalize: begin
                rcmode = 2'd1;
                Xi0_sh0 = Xo0_sh0;
                Xi1_sh0 = Xo1_sh0;
                Xi2_sh0 = Xo2_sh0;
                Xi3_sh0 = Xo3_sh0;
                Xi4_sh0 = Xo4_sh0;
                if(count == A) begin
                    Tv = 1;
                    next_state = idle;
                end
            end
        endcase
    end

endmodule
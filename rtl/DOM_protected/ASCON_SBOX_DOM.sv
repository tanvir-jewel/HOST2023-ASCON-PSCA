module ASCON_SBOX_DOM(
    input logic clk,
    input logic nRST,
    input logic passthrough_en,
    input logic [319:0] randbits,
    input logic [63:0] xrc0,
    input logic [63:0] xrc1,
    input logic [63:0] xrc2,
    input logic [63:0] xrc3,
    input logic [63:0] xrc4,
    input logic [63:0] xi0_sh1,
    input logic [63:0] xi1_sh1,
    input logic [63:0] xi2_sh1,
    input logic [63:0] xi3_sh1,
    input logic [63:0] xi4_sh1,
    output logic [63:0] Xsb0_sh0,
    output logic [63:0] Xsb1_sh0,
    output logic [63:0] Xsb2_sh0,
    output logic [63:0] Xsb3_sh0,
    output logic [63:0] Xsb4_sh0,
    output logic [63:0] Xsb0_sh1,
    output logic [63:0] Xsb1_sh1,
    output logic [63:0] Xsb2_sh1,
    output logic [63:0] Xsb3_sh1,
    output logic [63:0] Xsb4_sh1,
    output logic [63:0] passthrough_0,
    output logic [63:0] passthrough_1,
    output logic [63:0] passthrough_2,
    output logic [63:0] passthrough_3,
    output logic [63:0] passthrough_4
);

    logic [63:0] Xa0_sh0, Xa1_sh0, Xa2_sh0, Xa3_sh0, Xa4_sh0;
    logic [63:0] Xa0_sh1, Xa1_sh1, Xa2_sh1, Xa3_sh1, Xa4_sh1;

    logic [63:0] Xb0_sh0, Xb1_sh0, Xb2_sh0, Xb3_sh0, Xb4_sh0;
    logic [63:0] Xb0_sh1, Xb1_sh1, Xb2_sh1, Xb3_sh1, Xb4_sh1;

    logic [63:0] Xc0_sh0, Xc1_sh0, Xc2_sh0, Xc3_sh0, Xc4_sh0;
    logic [63:0] Xc0_sh1, Xc1_sh1, Xc2_sh1, Xc3_sh1, Xc4_sh1;

    logic [63:0] Xa0_sh0_reg, Xa1_sh0_reg, Xa2_sh0_reg, Xa3_sh0_reg, Xa4_sh0_reg;
    logic [63:0] Xa0_sh1_reg, Xa1_sh1_reg, Xa2_sh1_reg, Xa3_sh1_reg, Xa4_sh1_reg;
    
    assign passthrough_0 = Xa0_sh1_reg;
    assign passthrough_1 = Xa1_sh1_reg;
    assign passthrough_2 = Xa2_sh1_reg;
    assign passthrough_3 = Xa3_sh1_reg;
    assign passthrough_4 = Xa4_sh1_reg;

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            Xa0_sh0_reg <= '0;
            Xa1_sh0_reg <= '0;
            Xa2_sh0_reg <= '0;
            Xa3_sh0_reg <= '0;
            Xa4_sh0_reg <= '0;
        end
        else begin
            Xa0_sh0_reg <= Xa0_sh0;
            Xa1_sh0_reg <= Xa1_sh0;
            Xa2_sh0_reg <= Xa2_sh0;
            Xa3_sh0_reg <= Xa3_sh0;
            Xa4_sh0_reg <= Xa4_sh0;
        end
    end

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            Xa0_sh1_reg <= '0;
            Xa1_sh1_reg <= '0;
            Xa2_sh1_reg <= '0;
            Xa3_sh1_reg <= '0;
            Xa4_sh1_reg <= '0;
        end
        else if(passthrough_en == 1'b1) begin
            Xa0_sh1_reg <= xi0_sh1;
            Xa1_sh1_reg <= xi1_sh1;
            Xa2_sh1_reg <= xi2_sh1;
            Xa3_sh1_reg <= xi3_sh1;
            Xa4_sh1_reg <= xi4_sh1;
        end
        else begin
            Xa0_sh1_reg <= Xa0_sh1;
            Xa1_sh1_reg <= Xa1_sh1;
            Xa2_sh1_reg <= Xa2_sh1;
            Xa3_sh1_reg <= Xa3_sh1;
            Xa4_sh1_reg <= Xa4_sh1;
        end
    end

    assign Xa0_sh0 = xrc0 ^ xrc4;
    assign Xa1_sh0 = xrc1;
    assign Xa2_sh0 = xrc2 ^ xrc1;
    assign Xa3_sh0 = xrc3;
    assign Xa4_sh0 = xrc4 ^ xrc3;

    assign Xa0_sh1 = xi0_sh1 ^ xi4_sh1;
    assign Xa1_sh1 = xi1_sh1;
    assign Xa2_sh1 = xi2_sh1 ^ xi1_sh1;
    assign Xa3_sh1 = xi3_sh1;
    assign Xa4_sh1 = xi4_sh1 ^ xi3_sh1;

    genvar i;
    generate
        for(i = 0; i < 64; i++) begin
            DOM_AND DA0(clk, nRST, ~Xa0_sh0[i], Xa1_sh0[i], Xa0_sh1[i], Xa1_sh1[i], randbits[5 * i], Xb0_sh0[i], Xb0_sh1[i]);
            DOM_AND DA1(clk, nRST, ~Xa1_sh0[i], Xa2_sh0[i], Xa1_sh1[i], Xa2_sh1[i], randbits[(5 * i) + 1], Xb1_sh0[i], Xb1_sh1[i]);
            DOM_AND DA2(clk, nRST, ~Xa2_sh0[i], Xa3_sh0[i], Xa2_sh1[i], Xa3_sh1[i], randbits[(5 * i) + 2], Xb2_sh0[i], Xb2_sh1[i]);
            DOM_AND DA3(clk, nRST, ~Xa3_sh0[i], Xa4_sh0[i], Xa3_sh1[i], Xa4_sh1[i], randbits[(5 * i) + 3], Xb3_sh0[i], Xb3_sh1[i]);
            DOM_AND DA4(clk, nRST, ~Xa4_sh0[i], Xa0_sh0[i], Xa4_sh1[i], Xa0_sh1[i], randbits[(5 * i) + 4], Xb4_sh0[i], Xb4_sh1[i]);
        end
    endgenerate

    assign Xc0_sh0 = Xa0_sh0_reg ^ Xb1_sh0;
    assign Xc1_sh0 = Xa1_sh0_reg ^ Xb2_sh0;
    assign Xc2_sh0 = Xa2_sh0_reg ^ Xb3_sh0;
    assign Xc3_sh0 = Xa3_sh0_reg ^ Xb4_sh0;
    assign Xc4_sh0 = Xa4_sh0_reg ^ Xb0_sh0;

    assign Xc0_sh1 = Xa0_sh1_reg ^ Xb1_sh1;
    assign Xc1_sh1 = Xa1_sh1_reg ^ Xb2_sh1;
    assign Xc2_sh1 = Xa2_sh1_reg ^ Xb3_sh1;
    assign Xc3_sh1 = Xa3_sh1_reg ^ Xb4_sh1;
    assign Xc4_sh1 = Xa4_sh1_reg ^ Xb0_sh1;

    assign Xsb0_sh0 = Xc0_sh0 ^ Xc4_sh0;
    assign Xsb1_sh0 = Xc1_sh0 ^ Xc0_sh0;
    assign Xsb2_sh0 = ~Xc2_sh0;
    assign Xsb3_sh0 = Xc3_sh0 ^ Xc2_sh0;
    assign Xsb4_sh0 = Xc4_sh0;

    assign Xsb0_sh1 = Xc0_sh1 ^ Xc4_sh1;
    assign Xsb1_sh1 = Xc1_sh1 ^ Xc0_sh1;
    assign Xsb2_sh1 = Xc2_sh1;
    assign Xsb3_sh1 = Xc3_sh1 ^ Xc2_sh1;
    assign Xsb4_sh1 = Xc4_sh1;

endmodule

module DOM_AND(
    input logic clk,
    input logic nRST,
    input logic Ax,
    input logic Ay,
    input logic Bx,
    input logic By,
    input logic Z,
    output logic Aq,
    output logic Bq
);

    logic [3:0] GF_product;
    logic [3:0] regs;

    assign GF_product[0] = Ax & Ay;
    assign GF_product[1] = Ax & By;
    assign GF_product[2] = Bx & Ay;
    assign GF_product[3] = Bx & By;

    assign Aq = regs[0] ^ regs[1];
    assign Bq = regs[2] ^ regs[3];

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)
            regs <= '0;
        else begin
            regs[0] <= GF_product[0];
            regs[1] <= GF_product[1] ^ Z;
            regs[2] <= GF_product[2] ^ Z;
            regs[3] <= GF_product[3];
        end
    end

endmodule
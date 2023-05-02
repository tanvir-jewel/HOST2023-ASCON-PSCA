module ASCON_ROUND_FUNCTION_DOM(
    input logic clk,
    input logic nRST,
    input logic passthrough_en,
    input logic [319:0] randbits,
    input logic [63:0] Xi0_sh0,
    input logic [63:0] Xi1_sh0,
    input logic [63:0] Xi2_sh0,
    input logic [63:0] Xi3_sh0,
    input logic [63:0] Xi4_sh0,
    input logic [63:0] Xi0_sh1,
    input logic [63:0] Xi1_sh1,
    input logic [63:0] Xi2_sh1,
    input logic [63:0] Xi3_sh1,
    input logic [63:0] Xi4_sh1, 
    input logic [7:0] Roundconstant, 
    output logic [63:0] Xo0_sh0,
    output logic [63:0] Xo1_sh0,
    output logic [63:0] Xo2_sh0,
    output logic [63:0] Xo3_sh0,
    output logic [63:0] Xo4_sh0,
    output logic [63:0] Xo0_sh1,
    output logic [63:0] Xo1_sh1,
    output logic [63:0] Xo2_sh1,
    output logic [63:0] Xo3_sh1,
    output logic [63:0] Xo4_sh1
);


logic [63:0] xrc0, xrc1, xrc2, xrc3, xrc4;
logic [63:0] Xsb0_sh0, Xsb1_sh0, Xsb2_sh0, Xsb3_sh0, Xsb4_sh0;
logic [63:0] Xsb0_sh1, Xsb1_sh1, Xsb2_sh1, Xsb3_sh1, Xsb4_sh1;

logic passthrough_en_reg;
logic [63:0] passthrough_0, passthrough_1, passthrough_2, passthrough_3, passthrough_4;

assign xrc0 = Xi0_sh0;
assign xrc1 = Xi1_sh0;
assign xrc2 = Xi2_sh0 ^ {56'b0,Roundconstant};
assign xrc3 = Xi3_sh0;
assign xrc4 = Xi4_sh0;

ASCON_SBOX_DOM asconsbox1(
    .clk(clk),
    .nRST(nRST),
    .passthrough_en(passthrough_en),
    .randbits(randbits),
    .xrc0(xrc0),
    .xrc1(xrc1),
    .xrc2(xrc2),
    .xrc3(xrc3),
    .xrc4(xrc4),
    .xi0_sh1(Xi0_sh1),
    .xi1_sh1(Xi1_sh1),
    .xi2_sh1(Xi2_sh1),
    .xi3_sh1(Xi3_sh1),
    .xi4_sh1(Xi4_sh1),
    .Xsb0_sh0(Xsb0_sh0),
    .Xsb1_sh0(Xsb1_sh0),
    .Xsb2_sh0(Xsb2_sh0),
    .Xsb3_sh0(Xsb3_sh0),
    .Xsb4_sh0(Xsb4_sh0),
    .Xsb0_sh1(Xsb0_sh1),
    .Xsb1_sh1(Xsb1_sh1),
    .Xsb2_sh1(Xsb2_sh1),
    .Xsb3_sh1(Xsb3_sh1),
    .Xsb4_sh1(Xsb4_sh1),
    .passthrough_0(passthrough_0),
    .passthrough_1(passthrough_1),
    .passthrough_2(passthrough_2),
    .passthrough_3(passthrough_3),
    .passthrough_4(passthrough_4)
);

assign Xo0_sh0 = Xsb0_sh0 ^  {Xsb0_sh0[18:0], Xsb0_sh0[63:19]} ^ {Xsb0_sh0[27:0], Xsb0_sh0[63:28]};
assign Xo1_sh0 = Xsb1_sh0 ^  {Xsb1_sh0[60:0], Xsb1_sh0[63:61]} ^ {Xsb1_sh0[38:0], Xsb1_sh0[63:39]};
assign Xo2_sh0 = Xsb2_sh0 ^  {Xsb2_sh0[ 0:0], Xsb2_sh0[63: 1]} ^ {Xsb2_sh0[ 5:0], Xsb2_sh0[63: 6]};
assign Xo3_sh0 = Xsb3_sh0 ^  {Xsb3_sh0[ 9:0], Xsb3_sh0[63:10]} ^ {Xsb3_sh0[16:0], Xsb3_sh0[63:17]};
assign Xo4_sh0 = Xsb4_sh0 ^  {Xsb4_sh0[ 6:0], Xsb4_sh0[63: 7]} ^ {Xsb4_sh0[40:0], Xsb4_sh0[63:41]};

always_ff @(posedge clk, negedge nRST) begin
    if(nRST == 1'b0)
        passthrough_en_reg <= 1'b0;
    else
        passthrough_en_reg <= passthrough_en;
end

always_comb begin
    if(passthrough_en_reg) begin
        Xo0_sh1 = passthrough_0;
        Xo1_sh1 = passthrough_1;
        Xo2_sh1 = passthrough_2;
        Xo3_sh1 = passthrough_3;
        Xo4_sh1 = passthrough_4;
    end
    else begin
        Xo0_sh1 = Xsb0_sh1 ^  {Xsb0_sh1[18:0], Xsb0_sh1[63:19]} ^ {Xsb0_sh1[27:0], Xsb0_sh1[63:28]};
        Xo1_sh1 = Xsb1_sh1 ^  {Xsb1_sh1[60:0], Xsb1_sh1[63:61]} ^ {Xsb1_sh1[38:0], Xsb1_sh1[63:39]};
        Xo2_sh1 = Xsb2_sh1 ^  {Xsb2_sh1[ 0:0], Xsb2_sh1[63: 1]} ^ {Xsb2_sh1[ 5:0], Xsb2_sh1[63: 6]};
        Xo3_sh1 = Xsb3_sh1 ^  {Xsb3_sh1[ 9:0], Xsb3_sh1[63:10]} ^ {Xsb3_sh1[16:0], Xsb3_sh1[63:17]};
        Xo4_sh1 = Xsb4_sh1 ^  {Xsb4_sh1[ 6:0], Xsb4_sh1[63: 7]} ^ {Xsb4_sh1[40:0], Xsb4_sh1[63:41]};
    end
end

endmodule

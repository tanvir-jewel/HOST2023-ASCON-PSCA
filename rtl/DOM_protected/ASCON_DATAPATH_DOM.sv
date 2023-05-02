module ASCON_DATAPATH_DOM(
    input logic clk,
    input logic nRST,
    input logic passthrough_en,
    input logic [319:0] randbits,
    input logic [1:0] rcmode,
    input logic [3:0] constti,
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
    
    logic [7:0] constt;

    ASCON_ROUND_CONSTANT_DOM asconRC1(
        .clk(clk),
        .nRST(nRST),
        .rcmode(rcmode),
        .constti(constti),
        .constt(constt)
    );

    ASCON_ROUND_FUNCTION_DOM asconRF1(
        .clk(clk),
        .nRST(nRST),
        .passthrough_en(passthrough_en),
        .randbits(randbits),
        .Xi0_sh0(Xi0_sh0),
        .Xi1_sh0(Xi1_sh0),
        .Xi2_sh0(Xi2_sh0),
        .Xi3_sh0(Xi3_sh0),
        .Xi4_sh0(Xi4_sh0),
        .Xi0_sh1(Xi0_sh1),
        .Xi1_sh1(Xi1_sh1),
        .Xi2_sh1(Xi2_sh1),
        .Xi3_sh1(Xi3_sh1),
        .Xi4_sh1(Xi4_sh1), 
        .Roundconstant(constt), 
        .Xo0_sh0(Xo0_sh0),
        .Xo1_sh0(Xo1_sh0),
        .Xo2_sh0(Xo2_sh0),
        .Xo3_sh0(Xo3_sh0),
        .Xo4_sh0(Xo4_sh0),
        .Xo0_sh1(Xo0_sh1),
        .Xo1_sh1(Xo1_sh1),
        .Xo2_sh1(Xo2_sh1),
        .Xo3_sh1(Xo3_sh1),
        .Xo4_sh1(Xo4_sh1)
    );
    
endmodule

module ASCON_AEAD_DOM(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic DOM_en,
    input logic [1:0] mode,
    input logic [127:0] key,
    input logic [127:0] nonce,
    input logic [319:0] randbits,
    input logic [63:0] blockin,
    input logic [3:0] datalen,
    output logic [127:0] Tag,
    output logic [63:0] CTblock,
    output logic CTv,
    output logic Tv,
    output logic read,
    output logic [2:0] state,
    output logic [319:0] ASCON_state,
    output logic state_update
);

    logic [1:0] rcmode;
    logic [3:0] rcinit;
    logic passthrough_en;

    logic [63:0] Xi0_sh0, Xi1_sh0, Xi2_sh0, Xi3_sh0, Xi4_sh0;
    logic [63:0] Xi0_sh1, Xi1_sh1, Xi2_sh1, Xi3_sh1, Xi4_sh1;
    
    logic [63:0] Xo0_sh0, Xo1_sh0, Xo2_sh0, Xo3_sh0, Xo4_sh0;
    logic [63:0] Xo0_sh1, Xo1_sh1, Xo2_sh1, Xo3_sh1, Xo4_sh1;

    logic [63:0] Xo0_debug, Xo1_debug, Xo2_debug, Xo3_debug, Xo4_debug;

    assign Xo0_debug = Xo0_sh0 ^ Xo0_sh1;
    assign Xo1_debug = Xo1_sh0 ^ Xo1_sh1;
    assign Xo2_debug = Xo2_sh0 ^ Xo2_sh1;
    assign Xo3_debug = Xo3_sh0 ^ Xo3_sh1;
    assign Xo4_debug = Xo4_sh0 ^ Xo4_sh1;
    
    assign ASCON_state = {Xo4_debug, Xo3_debug, Xo2_debug, Xo1_debug, Xo0_debug};
    

    ASCON_CONTROLER_DOM AC1(
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .DOM_en(DOM_en),
        .mode(mode),
        .key(key),
        .nonce(nonce),
        .randbits(randbits),
        .datalen(datalen),
        .blockin(blockin),
        .Xo0_sh0(Xo0_sh0),
        .Xo1_sh0(Xo1_sh0),
        .Xo2_sh0(Xo2_sh0),
        .Xo3_sh0(Xo3_sh0),
        .Xo4_sh0(Xo4_sh0),
        .Xo0_sh1(Xo0_sh1),
        .Xo1_sh1(Xo1_sh1),
        .Xo2_sh1(Xo2_sh1),
        .Xo3_sh1(Xo3_sh1),
        .Xo4_sh1(Xo4_sh1),
        .Tag(Tag),
        .CTblock(CTblock),
        .CTv(CTv),
        .Tv(Tv),
        .read(read),
        .passthrough_en(passthrough_en),
        .rcmode(rcmode),
        .rcinit(rcinit),
        .state_out(state),
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
        .state_update(state_update)
    );
        
        
    ASCON_DATAPATH_DOM AD1(
        .clk(clk),
        .nRST(nRST),
        .passthrough_en(passthrough_en),
        .randbits(randbits),
        .rcmode(rcmode),
        .constti(rcinit),
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

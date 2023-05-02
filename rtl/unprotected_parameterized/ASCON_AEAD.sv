module ASCON_AEAD(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic [1:0] mode,
    input logic [127:0] key,
    input logic [127:0] nonce,
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
    logic [63:0] Xi0,Xi1,Xi2,Xi3,Xi4,Xo0,Xo1,Xo2,Xo3,Xo4;

    assign ASCON_state = {Xo4, Xo3, Xo2, Xo1, Xo0};

    ASCON_CONTROLER AC1(
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .mode(mode),
        .key(key),
        .nonce(nonce),
        .datalen(datalen),
        .blockin(blockin),
        .Xo0(Xo0),
        .Xo1(Xo1),
        .Xo2(Xo2),
        .Xo3(Xo3),
        .Xo4(Xo4),
        .Tag(Tag),
        .CTblock(CTblock),
        .CTv(CTv),
        .Tv(Tv),
        .read(read),
        .rcmode(rcmode),
        .rcinit(rcinit),
        .state_out(state),
        .Xi0(Xi0),
        .Xi1(Xi1),
        .Xi2(Xi2),
        .Xi3(Xi3),
        .Xi4(Xi4),
        .state_update(state_update)
    );
        
        
    ASCON_DATAPATH AD1(
        .clk(clk),
        .nRST(nRST),
        .rcmode(rcmode),
        .constti(rcinit),
        .Xi0(Xi0),
        .Xi1(Xi1),
        .Xi2(Xi2),
        .Xi3(Xi3),
        .Xi4(Xi4),
        .Xo0(Xo0),
        .Xo1(Xo1),
        .Xo2(Xo2),
        .Xo3(Xo3),
        .Xo4(Xo4)
    );    

endmodule

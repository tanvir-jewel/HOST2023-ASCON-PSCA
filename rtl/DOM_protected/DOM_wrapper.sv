module DOM_wrapper(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic DOM_en,
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
    output logic state_update,
    //trivium
    input logic DOM_start,
    input logic [79:0] trivium_key,
    input logic [79:0] IV_MASK_0,
    input logic [79:0] IV_MASK_1,
    input logic [79:0] IV_MASK_2,
    input logic [79:0] IV_MASK_3,
    input logic [79:0] IV_MASK_4
);

    wire [319:0] randbits;
    
    ASCON_AEAD_DOM AC_DOM(
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .DOM_en(DOM_en),
        .mode(mode),
        .key(key),
        .nonce(nonce),
        .randbits(randbits),
        .blockin(blockin),
        .datalen(datalen),
        .Tag(Tag),
        .CTblock(CTblock),
        .CTv(CTv),
        .Tv(Tv),
        .read(read),
        .state(state),
        .ASCON_state(ASCON_state),
        .state_update(state_update)
    );

    trivium_64b M0(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(DOM_start),
        .enable(DOM_en),
        .key_trivium(trivium_key),
        .IV_trivium(IV_MASK_0),
        .ready(),
        .rng_out(randbits[63:0])
    );

    trivium_64b M1(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(DOM_start),
        .enable(DOM_en),
        .key_trivium(trivium_key),
        .IV_trivium(IV_MASK_1),
        .ready(),
        .rng_out(randbits[127:64])
    );

    trivium_64b M2(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(DOM_start),
        .enable(DOM_en),
        .key_trivium(trivium_key),
        .IV_trivium(IV_MASK_2),
        .ready(),
        .rng_out(randbits[191:128])
    );

    trivium_64b M3(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(DOM_start),
        .enable(DOM_en),
        .key_trivium(trivium_key),
        .IV_trivium(IV_MASK_3),
        .ready(),
        .rng_out(randbits[255:192])
    );

    trivium_64b M4(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(DOM_start),
        .enable(DOM_en),
        .key_trivium(trivium_key),
        .IV_trivium(IV_MASK_4),
        .ready(),
        .rng_out(randbits[319:256])
    );

endmodule
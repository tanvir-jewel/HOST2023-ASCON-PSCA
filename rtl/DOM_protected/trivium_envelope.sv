module trivium_envelope(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic Tv,
    input logic [26:0] rounds,
    input logic [79:0] key,
    input logic [79:0] IV_NONCE_0,
    input logic [79:0] IV_NONCE_1,
    output logic start_ASCON,
    output logic [127:0] nonce,
    output logic auto_control
);

    typedef enum logic [1:0]{
        idle,
        round,
        pause,
        stop
    } state_t;

    logic rand_ready;
    logic strobe;
    logic [26:0] count, next_count;
    state_t state, next_state;

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            count <= '0;
            state <= idle;
            start_ASCON <= '0;
        end
        else begin
            count <= next_count;
            state <= next_state;
            start_ASCON <= strobe;
        end
    end

    always_comb begin
        next_count = count;
        next_state = state;
        strobe = '0;
        auto_control = 1'b1;

        case(state)
            idle: begin
                auto_control = '0;
                if(rand_ready)
                    next_state = round;
            end
            round: begin
                strobe = 1'b1;
                next_state = pause;
                next_count = count + 1;
            end
            pause: begin
                if(Tv) begin
                    if(count == rounds) begin
                        next_state = stop;
                        next_count = '0;
                    end
                    else
                        next_state = round;
                end
            end
            stop: begin
                auto_control = '0;
                if(start)
                    next_state = idle;
            end
        endcase
    end

    trivium_64b N0(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(start),
        .enable(strobe),
        .key_trivium(key),
        .IV_trivium(IV_NONCE_0),
        .ready(rand_ready),
        .rng_out(nonce[63:0])
    );

    trivium_64b N1(
        .clk(clk),
        .nRST(nRST),
        .start_trivium(start),
        .enable(strobe),
        .key_trivium(key),
        .IV_trivium(IV_NONCE_1),
        .ready(),
        .rng_out(nonce[127:64])
    );

endmodule
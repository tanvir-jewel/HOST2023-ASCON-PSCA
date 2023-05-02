`timescale 1ns / 1ps

module trivium_64b(
    input logic            clk,
    input logic            nRST,
    input logic            start_trivium,
    input logic            enable,
    input logic     [79:0] key_trivium,
    input logic     [79:0] IV_trivium,
    output logic           ready,
    output logic    [63:0] rng_out
);
    
logic [287:0] Xi, Xo;
logic [63:0] z;
logic enable_datapath;

trivium_datapath td1(
    .clk(clk),
    .nRST(nRST),
    .enable(enable_datapath),
    .Xi(Xi),
    .Xo(Xo),
    .z(z)   
);

trivium_controller tc1(
    .clk(clk),
    .nRST(nRST),
    .start_trivium(start_trivium),
    .enable(enable),
    .key_trivium(key_trivium),
    .IV_trivium(IV_trivium),
    .Xo(Xo),
    .z(z),
    .enable_datapath(enable_datapath),
    .ready(ready),
    .Xi(Xi),
    .rng_out(rng_out)
);
    
endmodule

module trivium_datapath(
    input logic            clk,
    input logic            nRST,
    input logic            enable,
    input logic    [287:0] Xi,
    output logic   [287:0] Xo,
    output logic    [63:0] z   
);
    logic [287:0] Xreg, next_reg;
    logic  [63:0] a,b,c;
    
    assign a = Xreg[285:222]^Xreg[258:195];
    assign b = Xreg[189:126]^Xreg[174:111];
    assign c = Xreg[108:45]^Xreg[63:0];
    
    assign z = a^b^c;
    
    assign Xo = {
                 c^(Xreg[65:2] & Xreg[64:1])^Xreg[282:219],
                 Xreg[287:259],
                 a^(Xreg[260:197] & Xreg[259:196])^Xreg[180:117],
                 Xreg[194:175],
                 b^(Xreg[176:113] & Xreg[175:112])^Xreg[87:24],
                 Xreg[110:64]
                 };
    
    always_ff @(posedge clk, negedge nRST) begin
        if (nRST == 1'b0) begin
            Xreg <= '0; 
        end
        else begin
            Xreg <= next_reg;
        end
    end

    always_comb begin
        next_reg <= Xreg;
        if(enable)
            next_reg <= Xi;
    end
        
endmodule

module trivium_controller(
    input logic            clk,
    input logic            nRST,
    input logic            start_trivium,
    input logic            enable,
    input logic     [79:0] key_trivium,
    input logic     [79:0] IV_trivium,
    input logic    [287:0] Xo,
    input logic     [63:0] z,
    output logic           enable_datapath,
    output logic           ready,
    output logic   [287:0] Xi,
    output logic    [63:0] rng_out
);
    typedef enum logic [1:0] {
        idle,
        initialize,
        round
    } state_t;
    
    state_t state, next_state;
    logic [31:0] counter, next_counter;
    
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            state   <= idle;
            counter <= '0;
            rng_out <= '0;
        end
        else begin
            state   <= next_state;
            counter <= next_counter;
            rng_out <= z;
        end
    end
    
    always_comb begin
        
        next_state   = state;
        next_counter = counter;
        Xi           = '0;
        enable_datapath = '0;
        ready = '0;
        
        case(state)
            idle: begin
                Xi = {key_trivium,13'd0,IV_trivium,4'd0,111'd7};
                if(start_trivium == 1) begin
                    next_state   = initialize;
                    next_counter = 1;
                    enable_datapath = 1'b1;
                end
            end
            initialize: begin
                Xi = Xo;
                enable_datapath = 1'b1;
                if(counter == 18) begin
                    next_state   = round;
                    next_counter = 1;
                end
                else begin
                    next_state   = initialize;
                    next_counter = counter+1;
                end
            end 
            round: begin
                ready = 1'b1;
                Xi = Xo;
                enable_datapath = enable;
                if(start_trivium) begin
                    Xi = {key_trivium,13'd0,IV_trivium,4'd0,111'd7};
                    next_state = initialize;
                    enable_datapath = 1'b1;
                end

                /*if(counter == num_rounds) begin
                    next_state   = idle;
                    next_counter = 0;
                end
                else begin
                    next_state   = round;
                    next_counter = counter+1;
                end */          
            end                      
        endcase
    end
                        
endmodule
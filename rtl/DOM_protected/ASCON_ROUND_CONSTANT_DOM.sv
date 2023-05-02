module ASCON_ROUND_CONSTANT_DOM(
    input logic clk,
    input logic nRST,
    input logic [1:0] rcmode,
    input logic [3:0] constti,
    output logic [7:0] constt
);

reg [3:0] consttd;
reg [3:0] consttq;

    always_comb begin
        case (rcmode)
            2'b00: consttd = '0;
            2'b01: begin
                if(consttq == 4'hb)
                    consttd = 4'h0;
                else
                    consttd = consttq + 1;
            end
            2'b10:  begin
                if(consttq == 4'hb)
                    consttd = 4'h6;
                else
                    consttd = consttq + 1;
            end
            2'b11: consttd = constti;
        endcase
    end


    always_ff @(posedge clk , negedge nRST) begin

    if (nRST == 1'b0)
        consttq <= 4'b0000;
    else
        consttq <= consttd;
    end

    assign constt = {~consttq,consttq};

endmodule

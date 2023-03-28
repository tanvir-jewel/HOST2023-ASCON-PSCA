`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/27/2020 03:00:59 PM
// Design Name: 
// Module Name: ASCON_CONTROLER
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ASCON_DATAPATH_2rc(

   input clk,rst,intial,inc,
   input [3:0]  constti,
   input[63:0] Xi0,Xi1,Xi2,Xi3,Xi4,
    output [63:0]Xo0,Xo1,Xo2,Xo3,Xo4
    );
    
    wire [7:0] constt;
    wire [3:0] constt2;
    reg [63:0] Xreg0,Xreg1,Xreg2,Xreg3,Xreg4;
    wire [63:0] Xm0,Xm1,Xm2,Xm3,Xm4;

    assign constt2 = constt[3:0] + 1;
    
    ASCON_ROUND_CONSTANT_2rc asconRC1(
        .clk(clk),.rst(rst),.intial(intial),.inc(inc),
        .constti(constti),
        .constt(constt)
    );
    
    ASCON_ROUND_FUNCTION asconRF1(
        Xreg0,Xreg1,Xreg2,Xreg3,Xreg4, 
        constt, 
        Xm0,Xm1,Xm2,Xm3,Xm4 
    );

    ASCON_ROUND_FUNCTION asconRF2(
        Xm0,Xm1,Xm2,Xm3,Xm4, 
        {~constt2, constt2}, 
        Xo0,Xo1,Xo2,Xo3,Xo4 
    );
    
    always @ (posedge clk , posedge rst) begin
    
    if (rst) begin
    Xreg0 = 0;
    Xreg1 = 0;
    Xreg2 = 0;
    Xreg3 = 0;
    Xreg4 = 0; 
    end
    else begin
    Xreg0 = Xi0;
    Xreg1 = Xi1;
    Xreg2 = Xi2;
    Xreg3 = Xi3;
    Xreg4 = Xi4;
    end
    
    end
    
endmodule

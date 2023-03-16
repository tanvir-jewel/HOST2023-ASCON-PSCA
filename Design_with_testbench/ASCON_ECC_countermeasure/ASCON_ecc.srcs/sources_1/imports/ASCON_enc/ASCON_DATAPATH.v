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


module ASCON_DATAPATH(

   input clk,rst,intial,inc,
   input [3:0]  constti,
   input[63:0] Xi0,Xi1,Xi2,Xi3,Xi4,
    output [63:0]Xo0,Xo1,Xo2,Xo3,Xo4,
    output [63:0] XsboxIN0, XsboxIN1, XsboxIN2, XsboxIN3, XsboxIN4,
    output [63:0] Xsbox0, Xsbox1, Xsbox2, Xsbox3, Xsbox4, p0,p1,p2
    );
    
    wire [7:0] constt;
    reg [63:0] Xreg0,Xreg1,Xreg2,Xreg3,Xreg4;
    
    ASCON_ROUND_CONSTANT asconRC1(
        .clk(clk),.rst(rst),.intial(intial),.inc(inc),
        .constti(constti),
        .constt(constt)
    );
    
    ASCON_ROUND_FUNCTION asconRF1(
        Xreg0,Xreg1,Xreg2,Xreg3,Xreg4, 
        constt, 
        Xo0,Xo1,Xo2,Xo3,Xo4,XsboxIN0, XsboxIN1, XsboxIN2, XsboxIN3, XsboxIN4,
        Xsbox0, Xsbox1, Xsbox2, Xsbox3, Xsbox4, p0,p1,p2
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

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/27/2020 11:35:19 AM
// Design Name: 
// Module Name: ASCON_AEAD
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


module ASCON_AEAD(
input clk,rst,start, 
input [127:0] key,nonce,
output reg [63:0] Xo0F,Xo1F,Xo2F,Xo3F,Xo4F,
output done
);



wire intial,inc;
wire [3:0] consti;
wire [63:0] Xi0,Xi1,Xi2,Xi3,Xi4,Xo0,Xo1,Xo2,Xo3,Xo4;





ASCON_CONTROLER  asconcont1(
 clk,rst,start,
 key,nonce,


intial,inc,
consti,
 Xi0,Xi1,Xi2,Xi3,Xi4,
Xo0,Xo1,Xo2,Xo3,Xo4,
done
    );
    
    
always @ (posedge clk) begin
if (done ==1'b1) begin
    Xo0F<=Xo0;
    Xo1F<=Xo1;
    Xo2F<=Xo2;
    Xo3F<=Xo3;
    Xo4F<=Xo4;
end
end
    
    
ASCON_DATAPATH ascondatapath1(
 clk,rst,intial,inc,
 consti,
 Xi0,Xi1,Xi2,Xi3,Xi4,
 Xo0,Xo1,Xo2,Xo3,Xo4
    
        );    

endmodule

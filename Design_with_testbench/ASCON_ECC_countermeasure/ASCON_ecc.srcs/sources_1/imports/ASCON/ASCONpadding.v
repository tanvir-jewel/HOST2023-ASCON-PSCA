`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/30/2020 03:44:50 PM
// Design Name: 
// Module Name: padding
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


module ASCONpadding(input [63:0]Ti,input [3:0]Tlen, output reg [63:0]To, output paddone );


always@(*) begin

case (Tlen)

4'd0: begin
To={1'b1,63'b0};
//paddone = 1;
end

4'd1:begin
To={Ti[63:56],1'b1,55'b0};
//paddone = 1;
end

4'd2:begin
To={Ti[63:48],1'b1,47'b0};
//paddone = 1;
end

4'd3:begin
To={Ti[63:40],1'b1,39'b0};
//paddone = 1;
end

4'd4:begin
To={Ti[63:32],1'b1,31'b0};
//paddone = 1;
end

4'd5:begin
To={Ti[63:24],1'b1,23'b0};
//paddone = 1;
end

4'd6:begin
To={Ti[63:16],1'b1,15'b0};
//paddone = 1;
end

4'd7:begin
To={Ti[63:8],1'b1,7'b0};
//paddone = 1;
end

4'd8: begin
To={Ti[63:0]};
//paddone = 0;
end

default:begin
To={Ti[63:0]};
//paddone = 0;
end


endcase

end
assign paddone = !Tlen[3];
endmodule

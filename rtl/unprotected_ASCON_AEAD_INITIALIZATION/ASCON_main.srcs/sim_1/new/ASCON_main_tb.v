`timescale 1ns / 1ps
`define NULL 0 

module ASCON_main_tb;
reg clk,rst,start;
reg [127:0] key,nonce;
wire [63:0] Xo0F,Xo1F,Xo2F,Xo3F,Xo4F;
wire done;

integer inFile, outFile, i;
integer scan;
reg	[19:0] clk_count; // For Tracing/Debugginh 

initial 
begin 
	clk	<= 1'b0; 
	clk_count <= 20'd0; 
end 
always 
begin 
	#1 clk <= ~clk;
end 

initial begin
	inFile = $fopen("C:/My_Computer/Research/xilinx/ASCON_main/ip_sequence.txt", "r");
	// Please change your directory
	if(inFile == `NULL)
	begin
		$display("Could not open the stimulus file");
		$finish;
	end
	outFile = $fopen("C:/My_Computer/Research/xilinx/ASCON_main/op_sequence.txt", "w");
	// Please change your directory
end

ASCON_AEAD DUT (
.clk (clk),
.rst (rst),
.start (start),
.key (key),
.nonce (nonce),
.Xo0F (Xo0F),
.Xo1F (Xo1F),
.Xo2F (Xo2F),
.Xo3F (Xo3F),
.Xo4F (Xo4F),
.done (done)
);

initial 
begin  
    rst	= 1'b1; 
    repeat (2)  
    @(posedge clk);  
    rst	= 1'b0; 
    clk_count <= clk_count + 20'd1; 
end 

//always 
//begin
//    if (done) begin
//        #1 rst = 1'b1;
//    end
//end

initial
begin
    while(!$feof(inFile))
    begin
        scan = $fscanf(inFile, "%b %h %h\n", start, key, nonce );
        @(posedge clk);
        if (start == 1'b1) begin
            repeat (14)
            @(posedge clk);
            $fwrite(outFile, "%b %h %h %h %h %h\n", done, Xo4F, Xo3F, Xo2F, Xo1F, Xo0F);
            @(posedge clk);
            rst = 1'b1;
            @(posedge clk);
            rst = 1'b0;
            end
    end
    $fclose(inFile);
    $fclose(outFile);
    $stop;
    //#200 $finish();
end
endmodule

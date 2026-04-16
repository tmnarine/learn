module top import params::*; (
        input clk,      // Clock signal,
        input rst,
        output reg [7:0] accumulator,
        output reg exec
);

    logic [3:0] pc;
    logic [15:0] current_mem;
    logic [15:0] code[0:15];
    logic mem_data_read;
    
    initial begin
        pc = 4'h0;
        current_mem = 16'h00;
        mem_data_read = 1'b0;
        foreach (code[i]) begin
            code[i] = 16'h00;
        end
        code[0] = 16'(LOAD << 8 | 8'h01);
        code[1] = 16'(ADD  << 8 | 8'h02);
        code[2] = 16'(ADD  << 8 | 8'h03);
        code[3] = 16'(ADD  << 8 | 8'h04);
        code[4] = 16'(ADD  << 8 | 8'h05);
        code[5] = 16'(SUB  << 8 | 8'h0A);
        code[6] = 16'(MUL  << 8 | 8'h07);
    end
    
    always_ff @(posedge clk) begin
        current_mem <= code[pc];
    end
    
    immediate_mode_cpu cpu1(
        clk,
        rst,
        pc,
        accumulator,
        current_mem,
        mem_data_read,
        exec
    );
        
endmodule

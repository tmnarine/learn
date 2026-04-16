
// Generated with AI and then modified

module immediate_mode_cpu import params::*; (
    input clk,
    input rst,
    output reg [3:0] pc,
    output reg [7:0] accumulator,
    input [15:0] mem_data_in,   // Data from Memory (16-bit: [15:12] Opcode, [11:0] Addr)
    output reg mem_read,
    output reg exec
);

    // FSM States
    parameter FETCH  = 3'b000;
    parameter DECODE = 3'b001;
    parameter EXEC   = 3'b010;
    
    // Internal Registers
    reg [15:0] ir;              // Instruction Register
    reg [2:0] state;            // FSM State

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 4'b0;
            accumulator <= 8'b0;
            state <= FETCH;
        end else begin
            exec = FALSE;
            case (state)
                FETCH: begin
                    ir <= mem_data_in;
                    mem_read <= TRUE;
                    state <= DECODE;
                end
                
                DECODE: begin
                    state <= EXEC;
                    mem_read <= FALSE;
                end

                EXEC: begin
                    case (ir[15:8]) // Opcode 15:8 and immediate value 7:0
                        LOAD:  accumulator <= ir[7:0];
                        ADD:   accumulator <= accumulator + ir[7:0];
                        SUB:   accumulator <= accumulator - ir[7:0];
                        MUL:   accumulator <= accumulator * ir[7:0];
                        default: accumulator <= 0;
                    endcase
                    $display("0x%x: 0x%x 0x%x # %s 0x%x", pc, ir[15:8], ir[7:0], isa_names[ir[15:8]], ir[7:0]);
                    pc <= pc + 1'b1;
                    state <= FETCH;
                    exec = TRUE;
                end
                default: begin
                end
            endcase
        end
    end
endmodule


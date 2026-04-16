package params;
    // Opcodes
    parameter LOAD  = 8'h00;
    parameter ADD   = 8'h01;
    parameter SUB   = 8'h02;
    parameter MUL   = 8'h03;
    parameter NO_OP = 8'hFF;
    // ISA name associative array
    string isa_names[byte] = '{LOAD: "LOAD", ADD: "ADD", SUB: "SUB", MUL: "MUL", NO_OP: "NO_OP"};
    // Booleans
    parameter TRUE  = 1'b1;
    parameter FALSE = 1'b0;
endpackage

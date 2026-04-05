// Reference
//  https://de-iitr.vlabs.ac.in/exp/4bit-synchronous-asynchronous-counter/theory.html

module top (
        input clk,      // Clock signal,
        output reg q0,
        output reg q1,
        output reg q2,
        output reg q3
);
    reg jk0_q_bar_unused;
    reg jk1_q_bar_unused;
    reg jk2_q_bar_unused;
    reg jk3_q_bar_unused;
    
    reg and0_out;
    reg and1_out;
    
    jk jk0(
        .clk(clk),
        .reset(1'b0),
        .j(1'b1),
        .k(1'b1),
        .q(q0),
        .q_bar(jk0_q_bar_unused)
    );
    
    jk jk1(
        .clk(clk),
        .reset(1'b0),
        .j(q0),
        .k(q0),
        .q(q1),
        .q_bar(jk1_q_bar_unused)
    );
    
    andgate and0(
        .a(q0),
        .b(q1),
        .result(and0_out)
    );

    jk jk2(
        .clk(clk),
        .reset(1'b0),
        .j(and0_out),
        .k(and0_out),
        .q(q2),
        .q_bar(jk2_q_bar_unused)
    );
 
     andgate and1(
        .a(q1),
        .b(q2),
        .result(and1_out)
    );
    
    jk jk3(
        .clk(clk),
        .reset(1'b0),
        .j(and1_out),
        .k(and1_out),
        .q(q3),
        .q_bar(jk3_q_bar_unused)
    );
    
endmodule

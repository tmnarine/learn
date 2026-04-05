module top (
        input clk,    // Clock signal,
        input j,
        input k,
        output q_out,
        output q_bar_out
);

    jk jk1(
        .clk(clk),
        .reset(1'b0),
        .j(j),
        .k(k),
        .q(q_out),
        .q_bar(q_bar_out)
    );

endmodule

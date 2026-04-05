module top (
    real divisor,
    real sum_in,
    output real sum_out
);

    real intermediate_result;
    
    div div1(/*AUTOINST*/
        .a(4.0),
        .b(divisor),
        .result(intermediate_result)
    );
    
    add add1(/*AUTOINST*/
        .a(sum_in),
        .b(intermediate_result),
        .sum(sum_out)
    );

endmodule

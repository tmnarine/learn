module add (
    real a,
    real b,
    output real sum
);

  always @(*) begin
    sum = a + b;
  end
  
endmodule

module div (
    real a,
    real b,
    output real result
);

  always @(*) begin
    result = 0;
    if (b) begin
        result = a / b;
    end
  end

endmodule

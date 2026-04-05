// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "adder.v"
#include "Vadder.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vadder* adder = new Vadder{contextp};
    
    double sum = 0;

    // Set initial input values
    adder->a = 10.5;
    adder->b = 20.1;

    // Evaluate the model
    adder->eval();

    // Print the result
    std::cout << "Result of " << (double)adder->a << " + " << (double)adder->b << " = " << (double)adder->sum << std::endl;
    sum += (double)adder->sum;
    
    // Change inputs and evaluate again
    adder->a = 255;
    adder->b = 1.1;
    adder->eval();
    std::cout << "Result of " << (double)adder->a << " + " << (double)adder->b << " = " << (double)adder->sum << std::endl;
    sum += (double)adder->sum;

    // Change inputs and evaluate again
    adder->a = 128;
    adder->b = -1;
    adder->eval();
    std::cout << "Result of " << (double)adder->a << " + " << (double)adder->b << " = " << (double)adder->sum << std::endl;
    sum += (double)adder->sum;
    
    std::cout << "Overall sum " << sum << std::endl;
    
    delete adder;
    delete contextp;
    return 0;
}

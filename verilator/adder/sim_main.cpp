// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "adder.v"
#include "Vadder.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vadder* adder = new Vadder{contextp};

    // Set initial input values
    adder->a = 10;
    adder->b = 20;

    // Evaluate the model
    adder->eval();

    // Print the result
    std::cout << "Result of " << (int)adder->a << " + " << (int)adder->b << " = " << (int)adder->sum << std::endl;

    // Change inputs and evaluate again
    adder->a = 255;
    adder->b = 1;
    adder->eval();
    std::cout << "Result of " << (int)adder->a << " + " << (int)adder->b << " = " << (int)adder->sum << std::endl;

    // Change inputs and evaluate again
    adder->a = 128;
    adder->b = -1;
    adder->eval();
    std::cout << "Result of " << (int)adder->a << " + " << (int)adder->b << " = " << (int)adder->sum << std::endl;
    
    delete adder;
    delete contextp;
    return 0;
}

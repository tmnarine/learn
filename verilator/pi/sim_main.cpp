// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};
    
    // Pi =  4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 ...)
    //    = (4 - 4/3 + 4/5 - 4/7 + 4/9 ...)
    double sum = 0.0;
    double divisor = 1.0;
    unsigned iterations = 2024;
    
    for (unsigned i = 0; i < iterations; ++i) {
        // Run
        top->divisor = divisor * ((i % 2 == 0) ? 1 : -1);
        top->sum_in = sum;
        top->eval();
         sum = double(top->sum_out);
        // Next
        divisor += 2.0;
    }
    
    // Algorithm converges slowly so very simple pass/fail detection
    std::string str = std::to_string(sum);
    size_t index = str.find("3.14");
    std::string status = (index == 0) ? "PASS" : "FAIL";
    std::cout << sum << " " << status << std::endl;

    delete top;
    delete contextp;
    return (index == 0) ? 0 : 1;
}

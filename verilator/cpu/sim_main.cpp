// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};

    top->accumulator = 0;
    top->exec = 0;
    top->eval();
    
    while (!contextp->gotFinish() && contextp->time() < 300) {
        
        contextp->timeInc(5);
        top->clk = !top->clk;
        top->eval();
        
        if (top->clk && top->exec) {
            std::cout << "\t# " << int(top->accumulator) << std::endl;
        }
    }

    delete top;
    delete contextp;
    return 0;
}

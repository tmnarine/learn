// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};

    while (!contextp->gotFinish() && contextp->time() < 200) {
        
        contextp->timeInc(5);
        top->clk = !top->clk;
        top->eval();
        
        if (top->clk) {
            // Order is reversed for counting up
            std::cout << "# "
                << int(top->q3)
                << int(top->q2)
                << int(top->q1)
                << int(top->q0)
                << std::endl;
        }
    }

    delete top;
    delete contextp;
    return 0;
}

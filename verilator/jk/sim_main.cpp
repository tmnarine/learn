// Include common routines
#include <verilated.h>

// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

#include <iostream>

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtop* top = new Vtop{contextp};
    
    std::vector<std::pair<int, int>> bit_list = {{0,0}, {0,1}, {1,0}, {1,1}};
    size_t index = 0;
    
    while (!contextp->gotFinish() && contextp->time() < 64) {
        
        if (!top->clk) {
            auto bits = bit_list[index];
            index += 1;
            index = index % bit_list.size();
            
            top->j = bits.first;
            top->k = bits.second;
        }
        
        contextp->timeInc(5);
        top->clk = !top->clk;
        top->eval();
        
        if (top->clk) {
            std::cout << "# time " << contextp->time()
                << " clk " << int(top->clk)
                << " j " << int(top->j)
                << " k " << int(top->k)
                << " q " << int(top->q_out)
                << " q_bar " << int(top->q_bar_out) << std::endl;
        }
    }

    delete top;
    delete contextp;
    return 0;
}

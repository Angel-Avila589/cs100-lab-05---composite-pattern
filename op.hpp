#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Op : public Base {
    private:
        double var = 0;
    public:
        Op(double value) : Base() {
            var = value;
        }
        double evaluate() { return var; }
        std::string stringify(){            
             return std::to_string(var);
        }
};

#endif //__OP_HPP__

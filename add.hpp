#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

using namespace std;

class Add : public Base{
    private:
        Base* add_val1;
        Base* add_val2;
    public:
        Add(Base* val1, Base* val2) : Base(){
            add_val1 = val1;
            add_val2 = val2;
        }
       ~Add(){
          //   cout << "destructor called" << endl;
            delete this->add_val1;
            delete this->add_val2;
        };
        double evaluate() {
            return add_val1->evaluate() + add_val2->evaluate();
        }
        std::string stringify()  {
            return "(" + add_val1->stringify() + " + " +  add_val2->stringify() + ")";
        }   
};

#endif //__ADD_HPP__

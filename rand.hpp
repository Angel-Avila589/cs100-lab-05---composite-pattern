#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <ctime>

class Rand : public Base{
    private:
	double var = 0;
    public:
	Rand() : Base(){
	    srand(static_cast<int>(time(0)));
	    this->var = rand() % 100;
	}

	double evaluate(){return this->var;}

	std::string stringify(){
	     return std::to_string(var);
	}
};

#endif //__RAND_HPP__

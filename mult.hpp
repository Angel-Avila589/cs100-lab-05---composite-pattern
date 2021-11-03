#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Mult : public Base {
    private:
	Base *lft;
	Base *rht;
    public:
	Mult(Base* itm1, Base* itm2) : Base(){
		this->lft = itm1;
		this->rht = itm2;
	}
	
	~Mult(){delete this->lft; delete this->rht;};

	double evaluate(){return this->lft->evaluate() * this->rht->evaluate();}

	std::string stringify(){
		std::string s = "(" + this->lft->stringify() + " * " + this->rht->stringify() + ")";
		return s;
	}
};

#endif //__MULT_HPP__

#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>
#include <string>

class Div : public Base{
    private:
	Base *lft;
	Base *rht;
    public:
	Div(Base* itm1, Base* itm2) : Base(){
		this->lft = itm1;
		this->rht = itm2;
	} 

	~Div(){delete this->lft; delete this->rht;}

	double evaluate(){
		if(this->rht->evaluate() == 0)
		{
			std::cerr << "Error Zero Denominator";
			exit(1);
		}
		else
		{
			return this->lft->evaluate() / this->rht->evaluate();
		}
	}

	std::string stringify(){
		std::string s = "(" + this->lft->stringify() + " / " + this->rht->stringify() + ")";
		return s;
	}
};

#endif //__DIV_HPP__

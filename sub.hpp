#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Sub : public Base {
    private:
	Base* lft;
	Base* rht;
    public:
	Sub(Base* itm1, Base* itm2) : Base(){
	    this->lft = itm1;
	    this->rht = itm2;
	}

	~Sub(){delete this->lft; delete this->rht;}

	double evaluate(){return this->lft->evaluate() - this->rht->evaluate();}

	std::string stringify(){
		std::string s = "(" + this->lft->stringify() + " - " + this->rht->stringify() + ")";
		return s; 
	}
};

#endif //__SUB_HPP__

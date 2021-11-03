#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <cmath>

class Pow : public Base{
    private:
	Base* lft;
	Base* rht;
    public:
	Pow(Base* itm1, Base* itm2) : Base(){
	       this->lft = itm1;
	       this->rht = itm2;	 
	}

	~Pow(){delete this->lft; delete this->rht;}

	double evaluate(){return pow(this->lft->evaluate(), this->rht->evaluate());}

	std::string stringify(){
		std::string s = "(" + this->lft->stringify() + " ** " + this->rht->stringify() + ")";
		return s; 
	}
};

#endif //__POW_HPP__

#pragma once
#include<iostream>

class TCircle {	
protected:
	double R;
public:
	TCircle();
	TCircle(double r);
	virtual ~TCircle();
	virtual double Square() const;
	virtual void Print() const;
};



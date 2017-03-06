#pragma once
#include"TCircle.h"


class TBall : public TCircle {
public:
	TBall();
	TBall(double r);
	~TBall();
	double Square() const;
	void Print() const;
};
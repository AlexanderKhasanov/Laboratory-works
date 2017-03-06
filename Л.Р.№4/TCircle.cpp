#include"TCircle.h"
#include<cmath>

TCircle::TCircle() {
	R = 0;
}

TCircle::TCircle(double r) {
	R = r;
}

TCircle::~TCircle() {
}

double TCircle::Square() const{
	double const pi = 3.14;
	return pi*pow(R, 2);
}

void TCircle::Print() const{
	std::cout << "R=" << R << " " << "Square of a circle: " << Square() << std::endl;
}


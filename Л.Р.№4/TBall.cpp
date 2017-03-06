#include"TBall.h"

TBall::TBall() : TCircle(0) {
	R = 0;
}

TBall::TBall(double r) : TCircle(r) {
}

TBall::~TBall() {
}

double TBall::Square() const {
	double const pi = 3.14;
	return 4 / 3 * pi*pow(R, 3);
}

void TBall::Print() const {
	std::cout << "R=" << R << " " << "Volume of a ball: " << Square() << std::endl;
}
#include"TComplex.h"

TComplex::TComplex() : TPair(0, 0) {
}

TComplex::TComplex(int real, int imaginary) : TPair(real, imaginary) {

}

TComplex::~TComplex() {
}

TComplex operator+(const TComplex& a, const TComplex& b) {
	TComplex result;
	result.FirstNumber = a.FirstNumber + a.SecondNumber;
	result.SecondNumber = b.FirstNumber + b.SecondNumber;
	return result;
}

TComplex operator-(const TComplex& a, const TComplex& b) {
	TComplex result;
	result.FirstNumber = a.FirstNumber - a.SecondNumber;
	result.SecondNumber = b.FirstNumber - b.SecondNumber;
	return result;
}

TComplex operator*(const TComplex& a, const TComplex& b) {
	TComplex result;
	result.FirstNumber = a.FirstNumber*b.FirstNumber - a.SecondNumber*b.SecondNumber;
	result.SecondNumber = a.FirstNumber*b.SecondNumber + a.SecondNumber*b.FirstNumber;
	return result;
}
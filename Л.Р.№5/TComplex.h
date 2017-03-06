#pragma once
#include"TPair.h"

class TComplex : public TPair {
public:
	TComplex();
	TComplex(int real, int imaginary);
	~TComplex();
	friend TComplex operator+(const TComplex& a, const TComplex& b);
	friend TComplex  operator*(const TComplex& a, const TComplex& b);
	friend TComplex  operator-(const TComplex& a, const TComplex& b);
};
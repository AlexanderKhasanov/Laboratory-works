#include"TPair.h"

TPair::TPair() {
	FirstNumber = 0;
	SecondNumber = 0;
}

TPair::TPair(int firstNumner, int secondNumber) {
	FirstNumber = firstNumner;
	SecondNumber = secondNumber;
}

TPair::~TPair() {
}

void TPair::SetFirst(int first) {
	FirstNumber = first;
}

void TPair::SetSecond(int second) {
	SecondNumber = second;
}

TPair& TPair::operator=(const TPair& newPair) {
	FirstNumber = newPair.FirstNumber;
	SecondNumber = newPair.SecondNumber;
	return *this;
}

TPair operator+(const TPair& a, const TPair& b) {
	TPair result;
	result.FirstNumber = a.FirstNumber + a.SecondNumber;
	result.SecondNumber = b.FirstNumber + b.SecondNumber;
	return result;
}

void TPair::Print() const{
	std::cout << "(" << FirstNumber << ", " << SecondNumber << ")" << std::endl;
}
#pragma once
#include<iostream>

class TPair {
protected:
	int FirstNumber;
	int SecondNumber;
public:
	TPair();
	TPair(int firstNumber, int secondNumber);
	virtual ~TPair();
	void SetFirst(int first);
	void SetSecond(int second);
	void Print() const;
	TPair& operator=(const TPair& newPair);
	friend TPair operator+(const TPair& a, const TPair& b);
};
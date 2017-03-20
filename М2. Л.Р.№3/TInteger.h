#pragma once
#include<iostream>
#include<exception>
#include<limits>

struct TOverflowValue
	: public std::exception
{
	TOverflowValue(char const* const message) throw()
		: std::exception(message)
	{
	}
};

struct TDivisionByZero
	: public std::exception
{
	TDivisionByZero(char const* const message) throw()
		: std::exception(message)
	{
	}
};

class TInteger {
	int Value;
public:
	TInteger();
	TInteger(const TInteger& rhs);
	TInteger(const long long int value);
	~TInteger();//=default?
	TInteger& operator=(const TInteger& rhs);
	bool operator==(const TInteger& rhs) const;
	bool operator>(const TInteger& rhs) const;
	TInteger& operator++();
	TInteger operator++(int);
	TInteger& operator--();
	TInteger operator--(int);
	TInteger& operator+=(const TInteger& rhs);
	TInteger& operator-=(const TInteger& rhs);
	TInteger& operator*=(const TInteger& rhs);
	TInteger& operator/=(const TInteger& rhs);
	TInteger& operator%=(const TInteger& rhs);

private:
	bool CheckOverflow(const long long int value) const;

	friend std::ostream& operator<<(std::ostream&, const TInteger&);
};

TInteger operator+(const TInteger& a, const TInteger& b);
TInteger operator-(const TInteger& a, const TInteger& b);
TInteger operator*(const TInteger& a, const TInteger& b);
TInteger operator/(const TInteger& a, const TInteger& b);
TInteger operator%(const TInteger& a, const TInteger& b);
bool operator!=(const TInteger& a, const TInteger& b);
bool operator>=(const TInteger& a, const TInteger& b);
bool operator<=(const TInteger& a, const TInteger& b);
bool operator<(const TInteger& a, const TInteger& b);
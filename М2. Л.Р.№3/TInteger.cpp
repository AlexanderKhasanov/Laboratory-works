#include"TInteger.h"

bool TInteger::CheckOverflow(const long long int value) const{
	if (value >= INT_MIN && value <= INT_MAX)
		return true;
	else
		throw TOverflowValue("Error! OverflowNumber!");
}

TInteger::TInteger()
	: Value(0)
{}

TInteger::TInteger(const TInteger& rhs)
	: Value(rhs.Value)
{}

TInteger::TInteger(const long long int value) {
	if (CheckOverflow(value))
		Value = static_cast<int>(value);
}

TInteger::~TInteger() 
{}

TInteger& TInteger::operator=(const TInteger& rhs) {
	if (&rhs == this)
		return *this;
	Value = rhs.Value;
	return *this;
}

bool TInteger::operator==(const TInteger& rhs) const {
	if (Value == rhs.Value)
		return true;
	else
		return false;
}

bool TInteger::operator>(const TInteger& rhs) const {
	if (Value > rhs.Value)
		return true;
	else
		return false;
}

TInteger& TInteger::operator++() {
	if (CheckOverflow(Value + 1)) {
		++Value;
		return *this;
	}
}

TInteger TInteger::operator++(int) {
	if (CheckOverflow(Value + 1)) {
		int value = Value;
		++Value;
		return value;
	}
}

TInteger& TInteger::operator--() {
	if (CheckOverflow(Value - 1)) {
		--Value;
		return *this;
	}
}

TInteger TInteger::operator--(int) {
	if (CheckOverflow(Value - 1)) {
		int value = Value;
		--Value;
		return value;
	}
}

TInteger& TInteger::operator+=(const TInteger& rhs) {//При разных знаках Value и rhs.Value мы точно не выйдем за границу
	if (Value < 0 && rhs.Value < 0 && Value < INT_MIN - rhs.Value)//Проверям выход за нижнюю границу
		throw TOverflowValue("Error! Overflow Number!");
	if (Value > 0 && rhs.Value > 0 && Value > INT_MAX - rhs.Value)//Проверяем выхож за верхнюю границу
		throw TOverflowValue("Error! Overflow Number!");
	Value += rhs.Value;
	return *this;
}

TInteger& TInteger::operator-=(const TInteger& rhs){//При разных одинаковых Value и rhs.Value мы точно не выйдем за границу
	if (Value < 0 && rhs.Value > 0 && Value < INT_MIN + rhs.Value)
		throw TOverflowValue("Error! Overflow Number!");
	if (Value > 0 && rhs.Value < 0 && Value > INT_MAX + rhs.Value)
		throw TOverflowValue("Error! Overflow Number!");
	Value -= rhs.Value;
	return *this;
}

TInteger& TInteger::operator*=(const TInteger& rhs) {
	if(Value > 0 && rhs.Value > 0 && Value > INT_MAX/rhs.Value)
		throw TOverflowValue("Error! Overflow Number!");
	if (Value < 0 && rhs.Value < 0 && Value > INT_MAX / rhs.Value)
		throw TOverflowValue("Error! Overflow Number!");
	if (Value < 0 && rhs.Value > 1 && Value < INT_MIN / rhs.Value) 
		throw TOverflowValue("Error! Overflow Number!");
	if (Value > 0 && rhs.Value < -1 && Value > INT_MIN / rhs.Value) 
		throw TOverflowValue("Error! Overflow Number!");
	Value *= rhs.Value;
	return *this;
}

TInteger& TInteger::operator/=(const TInteger& rhs) {
	if (rhs.Value == 0)
		throw TDivisionByZero("Errow! Division by zero");
	Value /= rhs.Value;
	return *this;
}

TInteger& TInteger::operator%=(const TInteger& rhs) {
	if (rhs.Value == 0)
		throw TDivisionByZero("Errow! Division by zero");
	Value %= rhs.Value;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const TInteger& val) {
	out << val.Value;
	return out;
}

TInteger operator+(const TInteger& a, const TInteger& b) {
	TInteger res(a);
	res += b;
	return res;
}

TInteger operator-(const TInteger& a, const TInteger& b) {
	TInteger res(a);
	res -= b;
	return res;
}

TInteger operator*(const TInteger& a, const TInteger& b) {
	TInteger res(a);
	res *= b;
	return res;
}

TInteger operator/(const TInteger& a, const TInteger& b) {
	TInteger res(a);
	res /= b;
	return res;
}

TInteger operator%(const TInteger& a, const TInteger& b) {
	TInteger res(a);
	res %= b;
	return res;
}

bool operator<(const TInteger& a, const TInteger& b){
	if (a == b || a > b)
		return false;
	else
		return true;
}

bool operator!=(const TInteger& a, const TInteger& b){
	if (a == b)
		return false;
	else
		return true;
}

bool operator>=(const TInteger& a, const TInteger& b){
	if (a > b || a == b)
		return true;
	else
		return false;
}

bool operator<=(const TInteger& a, const TInteger& b){
	if (a < b || a == b)
		return true;
	else
		return false;
}
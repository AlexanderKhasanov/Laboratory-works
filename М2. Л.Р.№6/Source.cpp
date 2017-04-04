#include"CastException.h"
#include<iostream>
#include<cmath>
#include<limits>

template<typename T>
T FromString(const char * data);

int GetNumberSymbol(const char symbol) {
	if (symbol >= 48 && symbol <= 57)
		return symbol - 48;
	else
		throw IncorrectSymbol();
}

int SizeNumber(const char* data) {
	int size = 0;
	while (data[size])
		++size;
	return size;
}


template<>
bool FromString<bool>(const char * data) {
	if (strcmp(data, "")==0)
		throw EmptyLine();
	std::string str(data);
	int i = 0;
	while (str[i]) {
		str[i] = char(tolower(data[i]));
		++i;
	}
	if (!str.compare("true") || !str.compare("1"))
		return true;
	else if (!str.compare("false") || !str.compare("0"))
		return false;
	else
		throw IncorrectSymbol();
}

template<>
int FromString<int>(const char* data) {
	if (strcmp(data, "") == 0)
		throw EmptyLine();
	int number = 0;
	int size = SizeNumber(data);
	int sizeMax = 10;
	bool minus = false;
	int i = 0;
	int check = 0;
	if (data[0] == '-') {
		minus = true;
		i = 1;
	}
	while (data[i] == '0') {
		++i;
	}
	if (size - i > 10)
		throw ArithmeticOverflow();
	else {
		if (size - i == 10) {
			if (GetNumberSymbol(data[i]) > 2)
				throw ArithmeticOverflow();
		}
		for (i; i < size; ++i) {
			if (minus) {
				number = number * 10 - GetNumberSymbol(data[i]);
				if (number > 0)
					throw ArithmeticOverflow();
			}
			else {
				number = number * 10 + GetNumberSymbol(data[i]);
				if (number < 0)
					throw ArithmeticOverflow();
			}
		}
	}
	return number;
}

template<>
float FromString<float>(const char * data) {
	if (strcmp(data, "") == 0)
		throw EmptyLine();
	float number = 0;
	int size = SizeNumber(data);
	bool minus = false;
	int i = 0;
	int positionOfDot = 0;
	bool dot = false;
	if (data[0] == '-') {
		minus = true;
		i = 1;
	}
	for (i; i < size; ++i) {
		if ((data[i] == '.' || data[i] == ',') && !dot) {
			dot = true;
			positionOfDot = i;
		}
		else {
			number = number * 10 + GetNumberSymbol(data[i]);
			if (number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
				throw ArithmeticOverflow();
		}
	}
	if (dot)
		number *= pow(0.1, size - positionOfDot - 1);
	if (minus)
		return -number;
	else
		return number;
}

int main() {
	int i = FromString<int>("-002147483648");
	try {
		std::cout << FromString<int>("-2147483647") << std::endl;
		std::cout << FromString<int>("-6147483647") << std::endl;
	}
	catch (EmptyLine & e) {
		std::cout << "Entered empty line" << std::endl;
	}
	catch (IncorrectSymbol & e) {
		std::cout << "Entered an invalid character" << std::endl;
	}
	catch (ArithmeticOverflow & e) {
		std::cout << "Entered a long number" << std::endl;
	}
	std::cout << std::endl;


	bool b=FromString<bool>("FalSe");
	try {
		std::cout << FromString<bool>("true") << std::endl;
		FromString<bool>("FalSse");
	}
	catch (EmptyLine & e) {
		std::cout << "Entered empty line" << std::endl;
	}
	catch (IncorrectSymbol & e) {
		std::cout << "Entered an invalid character" << std::endl;
	}
	std::cout << std::endl;

	float f = FromString<float>("-000001.2343");
	try {
		
		std::cout << FromString<float>("00003333") << std::endl;
		std::cout << FromString<float>("12e.456") << std::endl;
	}
	catch (EmptyLine & e) {
		std::cout << "Entered empty line" << std::endl;
	}
	catch (IncorrectSymbol & e) {
		std::cout << "Entered an invalid character" << std::endl;
	}
	catch (ArithmeticOverflow & e) {
		std::cout << "Entered a long number" << std::endl;
	}
	return 0;
}
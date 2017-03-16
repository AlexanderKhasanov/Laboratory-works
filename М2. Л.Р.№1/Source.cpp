#include"CastException.h"
#include<iostream>
#include<cmath>
#include<limits>

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

bool boolFromString(const char * data) {
	if (data == nullptr)
		throw EmptyLine();
	if (strcmp(data, "TRUE") == 0 || strcmp(data, "TRUe") == 0 || strcmp(data, "TRue") == 0 || strcmp(data, "True") == 0 || strcmp(data, "true") == 0 || strcmp(data, "1") == 0)
		return true;
	else if (strcmp(data, "FALSE") == 0 || strcmp(data, "FAlse") == 0 || strcmp(data, "FALse") == 0 || strcmp(data, "FALSe") == 0 || strcmp(data, "false") == 0 || strcmp(data, "0") == 0)
			return false;
		else
			throw IncorrectSymbol();
}

/*int intFromString(const char* data) {
	if (data == nullptr)
		throw EmptyLine();
	int number = 0;
	int check = 0;
	int size = SizeNumber(data);
	bool minus = false;
	int i = 0;
	if (data[0] == '-') {
		minus = true;
		i = 1;
	}
	for (i; i < size; ++i) {
		if (data[i] == '.' || data[i] == ',')
			break;
		number = number * 10 + GetNumberSymbol(data[i]);
		if (number < check)//при переполнении int присваивается минимально возможное значение
			throw ArithmeticOverflow();
		check = number;
	}
	if (minus)
		return -number;
	else
		return number;
}*/

int intFromString(const char* data) {
	if (data == nullptr)
		throw EmptyLine();
	int number = 0;
	int size = SizeNumber(data);
	bool minus = false;
	int i = 0;
	if (data[0] == '-') {
		minus = true;
		i = 1;
	}
	for (i; i < size; ++i) {
		if (data[i] == '.' || data[i] == ',')
			break;
		if (minus) {
			number = number * 10 - GetNumberSymbol(data[i]);
			if (number > 0)//при превышении минимального int присваивается максимально возможное значение
				throw ArithmeticOverflow();
		}
		else {
			number = number * 10 + GetNumberSymbol(data[i]);
			if (number < 0)//при превышении максимального значения int присваивается минимально возможное значение
				throw ArithmeticOverflow();
		}
	}
	return number;
}

float floatFromString(const char * data) {
	if (data == nullptr)
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
			if (number > std::numeric_limits<float>::max())
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
	std::cout << intFromString("-002147483648") << std::endl;
	std::cout << intFromString("002147483647") << std::endl;
	try {
		std::cout <<  intFromString("-000123") << std::endl;
		std::cout << intFromString("-002147483649") << std::endl;
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
	
	try {
		std::cout << boolFromString("true") << std::endl;
		boolFromString("tru");
	}
	catch (EmptyLine & e) {
		std::cout << "Entered empty line" << std::endl;
	}
	catch (IncorrectSymbol & e) {
		std::cout << "Entered an invalid character" << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << floatFromString("-000123.1456") << std::endl;
		std::cout << floatFromString("12e.456") << std::endl;
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
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
	if (data == "")
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

int intFromString(const char* data) {
	if (data == "")
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
	while(data[i]=='0'){
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
				if (number > 0)//при превышении минимального int присваивается максимально возможное значение
					throw ArithmeticOverflow();
				//check = number;
			}
			else {
				number = number * 10 + GetNumberSymbol(data[i]);				
				if (number < 0)//при превышении максимального значения int присваивается минимально возможное значение
					throw ArithmeticOverflow();
				 //check = number;
			}
		}
	}
	return number;
}

/*int intFromString(const char *data) {
	int x(0), size = 0;
	int k(0);
	bool flag = true;
	for (int i = 0; data[i] != '\0'; i++) {
		if (isalpha(data[i])) {
			throw IncorrectSymbol();
		}
		if (data[i] == '.' || data[i] == ',') break;
		k++;

		if (data[0] == '-') continue;
		if (flag && (data[i] == '0')) {

		}
		else {
			flag = false;
		}
		if (!flag) {
			size++;
		}


	}

	if (size > 11) {
		throw ArithmeticOverflow();
	}
	else {
		if (data[0] != '-') {
			for (int i = 0; i < k; i++) {
				x = (int)((int(data[k - i - 1]) - 48) * pow(10, i)) + x;
			}
		}
		else {
			for (int i = 0; i < k - 1; i++) {
				x = -((int)((int(data[k - i - 1]) - 48) * pow(10, i))) + x;
			}
		}
		if ((x >= 0 && data[0] != '-') || (x <= 0 && data[0] == '-'))
			return x;
		else {
			throw ArithmeticOverflow();
		}

	}

}*/

float floatFromString(const char * data) {
	if (data == "")
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
			if (number > std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min())
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
		std::cout<<intFromString("-2147483647")<<std::endl;
		std::cout << intFromString("-0") << std::endl;
		std::cout<<intFromString("-6147483647")<<std::endl;
		std::cout<<intFromString("-0021f48364")<<std::endl;
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


	boolFromString("FalSe");
	try {
		std::cout << boolFromString("true") << std::endl;
		boolFromString("FalSse");
	}
	catch (EmptyLine & e) {
		std::cout << "Entered empty line" << std::endl;
	}
	catch (IncorrectSymbol & e) {
		std::cout << "Entered an invalid character" << std::endl;
	}
	std::cout << std::endl;


	try {
		std::cout << floatFromString("11111111111111111111111111111111111111.2343") << std::endl;
		std::cout << floatFromString("00003333") << std::endl;
		std::cout << floatFromString("-000001.2343") << std::endl;
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
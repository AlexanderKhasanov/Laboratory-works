#include"TInteger.h"

int main() {
	try {
		TInteger a(2147483648);
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	TInteger a;
	TInteger b(2147483647);
	TInteger c(0);
	a = 10;

	try {
		a = b / c;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		c = a + b;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		c = b * a;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	b *= -1;

	try {
		c = b-a;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<string>

int main() {
	std::string str;
	int length = 0;
	bool result = true;
	std::cout << "Enter word" << std::endl;
	std::cin >> str;
	length = str.length();
	int c = length / 2;
	for (int i = 0; i < length/2; ++i) {
		if (str[i] != str[length - 1- i]) {
			result = false;
			break;
		}
	}
	if (result)
		std::cout << "It is palindrom" << std::endl;
	else 
		std::cout << "It is not palindrom" << std::endl;
	system("pause");
	return 0;
}
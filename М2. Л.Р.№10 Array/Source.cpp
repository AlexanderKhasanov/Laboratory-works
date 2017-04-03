#include"TArray.h"

template<typename IT>
void Print(IT beg, IT end) {
	for (IT i = beg; i != end; ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

int main() {
	TArray <int, 4> arr1{ 1, 2, 3, 4 };
	std::cout << "arr1: ";
	Print(arr1.begin(), arr1.end());
	TArray <double, 4> arr2;
	arr2 = { 10.1, 20.1, 30.1, 40.1 };
	std::cout << "arr2: ";
	Print(arr2.begin(), arr2.end());
	std::cout << arr2.front() << std::endl;
	std::cout << arr2.back() << std::endl;
	std::cout << arr2[1] << std::endl;
	std::cout << arr2.at(2) << std::endl;
	TArray<int, 4> arr3;
	arr3.fill(5);
	std::cout << "arr3: ";
	Print(arr3.begin(), arr3.end());
	swap(arr1, arr3);
	std::cout << "arr1: "; 
	Print(arr1.begin(), arr1.end());
	std::cout << "arr3: ";
	Print(arr3.begin(), arr3.end());
	if(arr1==arr3)
		std::cout << "arr1:"<<std::endl;
	else
		std::cout << "arr2:"<<std::endl;
	if (arr1 != arr3)
		std::cout << "arr1:" << std::endl;
	else
		std::cout << "arr2:" << std::endl;
	try {
		int s=arr1.at(4);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<list>
#include<cmath>

template<typename T>
void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template<typename IT>
void Print(IT beg, IT end) {
	for (IT i = beg; i != end; ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

/*template<typename IT>
void Sort(IT beg, IT end) {
	Print(beg, end);
	for (IT i = beg; i != end - 1; ++i) {
		for (IT j = beg; j != end - 1;  ++j) {
			if (*j > *(j + 1))
				swap(*j, *(j + 1));
			Print(beg, end);
		}
	}
}*/

/*template<typename IT>
void Sort(IT beg, IT end) {
	int k = 0;
	for (IT i = beg; i != end - 1; ++i) {
		k = i - beg;
		for (IT j = beg; j != end - k - 1; ++j) {
			if (*j > *(j + 1))
				swap(*j, *(j + 1));
		}
	}
}*/

template<typename IT>
void Sort(IT beg, IT end) {
	for (IT i = beg; i != end; ++i) {
		IT minCurrent = i;
		for (IT j = i; j != end; ++j) {
			if (*j < *minCurrent)
				swap(*j, *minCurrent);
		}
	}
}

int main() {
	int arr[] = { 123, 3, 0, 13212, -100 };
	Sort(&arr[0], &arr[3]); // arr: 0, 3, 123, 13212, -100
	Print(&arr[0], &arr[5]);
	Sort(&arr[2], &arr[5]); // arr: 0, 3, -100, 123, 13212
	Print(&arr[0], &arr[5]);

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	Sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	Print(vec.begin(), vec.end());

	std::list<double> list = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	Sort(list.begin(), list.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	Print(list.begin(), list.end());
	return 0;
}
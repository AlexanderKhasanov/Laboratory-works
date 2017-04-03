#include <iostream>

template<std::size_t N>
void print() {
	if (N <= 100) {
		std::cout << 100 - N << " ";
		print<N - 1>();
	}
}

template<>
void print<0>() {
	return;
}

int main() {
	print<100>();
	system("pause");
	return 0;
}
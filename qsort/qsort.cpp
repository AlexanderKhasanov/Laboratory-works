#include <iostream>
#include <vector>
#include <ctime>

template<class It, class Cmp>
void qsort(It first, It last, Cmp cmp) {
	if (first != last) {
		It pivot = first;
		It left = first+1;
		It right = last;
		while (left != right)
		{
			if (cmp(*left, *pivot))
			{
				++left;
			}
			else
			{
				do
				{
					--right;
				} while ((left != right) && cmp(*pivot, *right));
				std::swap(*left, *right);
			}
		}
		--left;
		std::swap(*pivot, *left);
		qsort(first, left, cmp);
		qsort(right, last, cmp);
	}
}

void Print(std::vector<int>& a)
{
	for(auto i=a.begin(); i!=a.end(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';
}

int main()
{
	srand(time(NULL));
	std::vector<int> vec;
	for (size_t i = 0; i < 100; ++i)
		vec.push_back(rand() % 1000);
	Print(vec);
	qsort<std::vector<int>::iterator, std::less<int>>(vec.begin(), vec.end(), std::less<int>());
	std::cout << "__________________________________________________________\n"<<"After sort:\n";
	Print(vec);
	system("pause");
	return 0;
}
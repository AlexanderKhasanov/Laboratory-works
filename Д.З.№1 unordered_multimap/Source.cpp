#include "Tunordered_multimap.h"

int main() {
	TUnordered_Map<int, int> map;
	if (map.empty())
		std::cout << "empty" << std::endl;
	else
		std::cout << "no empty" << std::endl;
	std::pair<int, int> p(1, 5);
	map.insert(p);
	map.insert(std::pair<int, int>(2, 4));
	map.insert(std::pair<int, int>(3, 5));
	map.insert(std::pair<int, int>(4, 4));
	map.insert(std::pair<int, int>(5, 5));
	map.insert(std::pair<int, int>(6, 4));
	map.insert(std::pair<int, int>(7, 5));
	map.insert(std::pair<int, int>(8, 4));
	map.insert(std::pair<int, int>(9, 5));
	map.insert(std::pair<int, int>(10, 4));
	if (map.empty())
		std::cout << "empty" << std::endl;
	else
		std::cout << "no empty" << std::endl;
	std::cout << map.size() << std::endl;

	for (auto i = map.begin(); i != map.end(); ++i)
		std::cout << "1 ";
	std::cout << "["<< map.at(5)<<"]"<< std::endl;
	std::cout << map.count(10) << std::endl;
	std::cout << map.bucket_count() << std::endl;
	std::cout << map.max_bucket_count() << std::endl;
	std::cout << map.bucket_size(7) << std::endl;
	auto a = map.find(10);
	std::cout << "[" << a->first << ", " << a->second << "]" << std::endl;
	map.erase(10);
	system("pause"); 
	return 0;
}
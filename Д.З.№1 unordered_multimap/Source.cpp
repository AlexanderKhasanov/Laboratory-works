#include "Tunordered_multimap.h"

void PrintMap(unordered_map<int, int>& map)
{
	for (auto i = map.begin(); i != map.end(); ++i)
		std::cout << "[" << i->first << ", " << i->second << "]" << std::endl;
}

int main() {
	unordered_map<int, int> map;
	unordered_map<int, int> map2;
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
	map2.insert(std::pair<int, int>(6, 4));
	map2.insert(std::pair<int, int>(7, 5));
	map2.insert(std::pair<int, int>(8, 4));
	map2.insert(std::pair<int, int>(9, 5));
	map2.insert(std::pair<int, int>(10, 4));
	PrintMap(map);
	std::cout << std::endl;
	PrintMap(map2);
	map.insert(map2.begin(), map2.end());
	std::cout << std::endl;
	PrintMap(map);
	std::cout << std::endl;
	map2.erase(10);
	PrintMap(map2);
	map2.erase(map2.begin(), map2.end());
	if (map2.empty())
		std::cout << "empty" << std::endl;

	if (map != map2)
		std::cout << "map==map1" << std::endl;
	else
		std::cout << "map!=map1" << std::endl;
	if (map.empty())
		std::cout << "empty" << std::endl;
	else
		std::cout << "no empty" << std::endl;
	for (auto i = map.begin(); i != map.end(); ++i)
		std::cout << "1 ";
	std::cout << std::endl;
	std::cout << map.size() << std::endl;
	std::cout << "["<< map.at(5)<<"]"<< std::endl;
	std::cout << map.count(10) << std::endl;
	std::cout << map.bucket_count() << std::endl;
	std::cout << map.max_bucket_count() << std::endl;
	std::cout << map.bucket_size(7) << std::endl;
//	auto a = map.find(10);
//	std::cout << "[" << a->first << ", " << a->second << "]" << std::endl;
	map[2] = 20;
	std::cout << "[" << map.at(2) << "]" << std::endl;
	system("pause"); 
	return 0;
}
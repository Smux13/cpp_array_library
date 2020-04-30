#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

#include "Array.h"

int main()
{
	std::srand(std::time(nullptr));
	std::rand();

	Array<int, 100> arr{};
	for (std::size_t i{}; i < arr.size(); ++i)
		arr[i] = i;

	std::random_shuffle(arr.begin(), arr.end());

	for (auto e : arr)
		std::cout << e << ' ';

	std::cout << '\n' << '\n';

	std::sort(arr.begin(), arr.end());

	for (auto e : arr)
		std::cout << e << ' ';
	std::cout << '\n' << '\n';

	Array<char, 8> charArr{};
	std::cout << "The size of a char array with 8 elements: " << sizeof(charArr) << " bytes" << '\n';

	Array<bool, 8> boolArr{};
	//std::cout << "The size of a bool array with 8 elements: " << boolArr.getSize() << " bytes" << '\n';

	for (std::size_t i{}; i < boolArr.size(); ++i)
		std::cout << boolArr[i] << ' ';

	return 0;
}

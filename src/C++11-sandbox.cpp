//============================================================================
// Name        : C++11-sandbox.cpp
// Author      : Arun Kanagasabapathy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

#include <Dog.h>
#include <variadic_arithmetic.h>

using namespace std;

template <class Container>
auto findNull(const Container& cont) -> decltype(begin(cont))
{
	auto it = begin(cont);
	for (; it != end(cont); ++it) {
		if (*it == nullptr) {
			break;
		}
	}

	return it;
}

int main() {
	static_assert(sizeof(long) >= 4,
			      "This needs to be at least 32 bit machine");
	std::vector<int> v = {1, 2, 3, 4, 5};

	for (auto& i: v) {
		std::cout << i << std::endl;
	}

	std::cout << "Printing out using for_each and lambda" << std::endl;
	for_each(v.begin(), v.end(), [] (int& i) {
		std::cout << "lambda: " << i << std::endl;
	});

	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << "Pointer value of " << *it << " = " << &(*it) << std::endl;

	}

	Sandbox::Dog dog = {4, 5.6};
	std::vector<Sandbox::Dog> dogs = { {4, 5.6}, {5, 6.7} };
	std::cout << "Size of dogs: " << dogs.size() << std::endl;


	///////
	{
		int a = 10, b = 5, c = 10;
		std::vector<int* > intPointers = { &a, &b, &c, nullptr, &a };
		auto location = findNull(intPointers) - intPointers.begin();
		std::cout << "Null pointer points to location: " << location
				  << std::endl;

		int* arrPointers[] = {&a, &b, nullptr, &c, &a };
		auto loc2 = findNull(arrPointers) - arrPointers;
		std::cout << "Null pointer in array pointer points to location: "
				  << loc2 << std::endl;
	}

	/// Variadic Artithmetic
	{
		auto int_sum = Sum::sum(1, 2, 3, 4, 5, 6, 7);
		std::cout << "int_sum: " << int_sum
				  << " Type: " << typeid(int_sum).name()
				  << std::endl;

		auto float_sum = Sum::sum(1.2, 3.4, 5.0, 8);
		std::cout << "float_sum: " << float_sum
				  << " Type: " << typeid(float_sum).name()
				  << std::endl;

		auto mixed_sum = Sum::sum(1, 2.2);
		std::cout << "mixed_sum: " << mixed_sum
				  << " Type: " << typeid(mixed_sum).name()
				  << std::endl;
	}

	return 0;
}

//
// Created by grvelva on 8/25/22.
//
#include <vector>
//    #define VECTOR std::vector
#define VECTOR ft::vector
#include "vector.hpp"

#include <cstdlib>

#define COUNT 100

int main() {
	VECTOR<std::string> vector_str;
	VECTOR<int> vector_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_int.push_back(i);
	}
	for (int i = 0; i < 5; i++)
	{
		vector_int.pop_back();
	}
	for (unsigned int i = 0; i < vector_int.size(); i++)
	{
		std::cout << vector_int[i];
	}

	for (int i = 0; i < COUNT; i++)
	{
		vector_str.push_back("sw");
	}
	for (int i = 0; i < 5; i++)
	{
		vector_str.pop_back();
	}
	for (unsigned int i = 0; i < vector_str.size(); i++)
	{
		std::cout << vector_str[i];
	}

	return (0);
}

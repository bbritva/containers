//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <map>
#include <stack>
#include <list>

#define NAMESPACE ft
//#define NAMESPACE std
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
//#include "daria/map.hpp"
#include "containers_test/srcs/base.hpp"

//#define TESTED_TYPE foo<int>
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define COUNT 100

int main() {

	{ //VECTOR
//		NAMESPACE::vector<std::string> vector_str;
//		NAMESPACE::vector<int> vector_int;
//
//		for (int i = 0; i < COUNT; i++) {
//			vector_int.push_back(i);
//		}
//		for (int i = 0; i < 5; i++) {
//			vector_int.pop_back();
//		}
//		NAMESPACE::vector<int>::iterator it = vector_int.begin();
//		while (it != vector_int.end()) {
//			std::cout << *it++;
//		}
//
//		for (int i = 0; i < COUNT; i++) {
//			vector_str.push_back("sw");
//		}
//		for (int i = 0; i < 5; i++) {
//			vector_str.pop_back();
//		}
//		for (unsigned int i = 0; i < vector_str.size(); i++) {
//			std::cout << vector_str[i];
//		}
//		std::cout << std::endl;
//
//		it++;
//		std::cout << *it << "\n";

	}
	{ //MAP
		NAMESPACE::map<int, int> map_int;
		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(ft::make_pair(i, i));
		}
	}

	{ //STACK
//		NAMESPACE::stack<std::string> stack_str;
//		NAMESPACE::stack<int> stack_int;
//
//		for (int i = 0; i < COUNT; i++) {
//			stack_int.push(i);
//		}
//		for (int i = 0; i < 5; i++) {
//			stack_int.pop();
//		}
//		while (!stack_int.empty()) {
//			std::cout << stack_int.top();
//			stack_int.pop();
//		}
//
//		for (int i = 0; i < COUNT; i++) {
//			stack_str.push("i");
//		}
//		for (int i = 0; i < 5; i++) {
//			stack_str.pop();
//		}
//		while (!stack_str.empty()) {
//			std::cout << stack_str.top();
//			stack_str.pop();
//		}
//		std::cout << std::endl;
//		{
//			NAMESPACE::vector<int> vector;
//			for (int i = 0; i < 10; i++) {
//				vector.push_back(i);
//			}
//			vector.insert(vector.begin() + 3, 3, 77);
//			NAMESPACE::vector<int>::iterator it = vector.begin();
//			while (it != vector.end()) {
//				std::cout << *it++;
//			}
//		}
//		std::cout << std::endl;
//		{
//			NAMESPACE::vector<int> vector;
//			std::vector<int> std_vector;
//			for (int i = 0; i < 3; i++) {
//				std_vector.push_back(i + 100);
//			}
//			for (int i = 0; i < 10; i++) {
//				vector.push_back(i);
//			}
//			vector.insert(vector.begin() + 3, std_vector.begin(), std_vector.end());
//			NAMESPACE::vector<int>::iterator it = vector.begin();
//			while (it != vector.end()) {
//				std::cout << *it++ << ", ";
//			}
//		}
	}
	std::cout << std::endl;

	{

	}
	return (0);
}

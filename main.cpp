//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <stack>
#define NAMESPACE ft
//#define NAMESPACE std
#include "vector.hpp"
#include "stack.hpp"

#include <cstdlib>

#define COUNT 100

int main() {
	/*{ //VECTOR
		NAMESPACE::vector<std::string> vector_str;
		NAMESPACE::vector<int> vector_int;

		for (int i = 0; i < COUNT; i++) {
			vector_int.push_back(i);
		}
		for (int i = 0; i < 5; i++) {
			vector_int.pop_back();
		}
		for (unsigned int i = 0; i < vector_int.size(); i++) {
			std::cout << vector_int[i];
		}

		for (int i = 0; i < COUNT; i++) {
			vector_str.push_back("sw");
		}
		for (int i = 0; i < 5; i++) {
			vector_str.pop_back();
		}
		for (unsigned int i = 0; i < vector_str.size(); i++) {
			std::cout << vector_str[i];
		}
		std::cout << std::endl;
	}*/
	{ //STACK
		NAMESPACE::stack<std::string> stack_str;
		NAMESPACE::stack<int> stack_int;

		for (int i = 0; i < COUNT; i++) {
			stack_int.push(i);
		}
		for (int i = 0; i < 5; i++) {
			stack_int.pop();
		}
		while (!stack_int.empty()) {
			std::cout << stack_int.top();
			stack_int.pop();
		}

		for (int i = 0; i < COUNT; i++) {
			stack_str.push("i");
		}
		for (int i = 0; i < 5; i++) {
			stack_str.pop();
		}
		while (!stack_str.empty()) {
			std::cout << stack_str.top();
			stack_str.pop();
		}
		std::cout << std::endl;
	}




	return (0);
}

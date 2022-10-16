//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <stack>
#include <list>

#define NAMESPACE ft
//#define NAMESPACE std
#include "vector.hpp"
#include "stack.hpp"
//#include "containers_test/srcs/base.hpp"

//#define TESTED_TYPE foo<int>
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define COUNT 100

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << (vct.empty() ? "true" : "false") << std::endl;
}

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main() {
	/*
	{ //VECTOR
		NAMESPACE::vector<std::string> vector_str;
		NAMESPACE::vector<int> vector_int;

		for (int i = 0; i < COUNT; i++) {
			vector_int.push_back(i);
		}
		for (int i = 0; i < 5; i++) {
			vector_int.pop_back();
		}
		NAMESPACE::vector<int>::iterator it = vector_int.begin();
		while (it != vector_int.end()) {
			std::cout << *it++;
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

		it++;
		std::cout << *it << "\n";

	}

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
		{
			NAMESPACE::vector<int> vector;
			for (int i = 0; i < 10; i++) {
				vector.push_back(i);
			}
			vector.insert(vector.begin() + 3, 3, 77);
			NAMESPACE::vector<int>::iterator it = vector.begin();
			while (it != vector.end()) {
				std::cout << *it++;
			}
		}
		std::cout << std::endl;
		{
			NAMESPACE::vector<int> vector;
			std::vector<int> std_vector;
			for (int i = 0; i < 3; i++) {
				std_vector.push_back(i + 100);
			}
			for (int i = 0; i < 10; i++) {
				vector.push_back(i);
			}
			vector.insert(vector.begin() + 3, std_vector.begin(), std_vector.end());
			NAMESPACE::vector<int>::iterator it = vector.begin();
			while (it != vector.end()) {
				std::cout << *it++ << ", ";
			}
		}
	}
	std::cout << std::endl;
	 */
	{
		const int start_size = 7;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
//		printSize(vct, true);

		vct.resize(10, 42);
//		printSize(vct, true);

		vct.resize(18, 43);
//		printSize(vct, true);
		vct.resize(10);
//		printSize(vct, true);
		vct.resize(23, 44);
//		printSize(vct, true);
		vct.resize(5);
//		printSize(vct, true);
		vct.reserve(5);
		vct.reserve(3);
//		printSize(vct, true);
		vct.resize(87);
		vct.resize(5);
//		printSize(vct, true);

		std::cout << "is_empty vct2: ";
		is_empty(vct2);
		vct2 = vct;
		std::cout << "is_empty vct2: ";
		is_empty(vct2);
		vct.reserve(vct.capacity() + 1);
		std::cout << "print vct:\n";
		printSize(vct, true);
		std::cout << "print vct2:\n";
		printSize(vct2, true);

		vct2.resize(0);
		std::cout << "is_empty vct2: ";
		is_empty(vct2);
		std::cout << "print vct2:\n";
		printSize(vct2, true);
	}
	return (0);
}

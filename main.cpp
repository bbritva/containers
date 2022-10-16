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
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define COUNT 100

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

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
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit = vct.rbegin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cr_ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			rit[i] = (size - i) * 5;

		std::cout << *rit << std::endl;
		rit = rit + 5;
		std::cout << *rit << std::endl;
		rit = 1 + rit;
		std::cout << *rit << std::endl;
		rit = rit - 4;
		std::cout << *rit << std::endl;
		std::cout << *(rit += 2) << std::endl;
		std::cout << *(rit -= 1) << std::endl;

		*(rit -= 2) = 42;
		*(rit += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(cr_ite += 2) << " | " << *(cr_ite -= 2) << std::endl;

		std::cout << "(rit == const_it): " << (cr_ite == rit) << std::endl;
		std::cout << "(const_ite - rit): " << (cr_ite - rit) << std::endl;
		std::cout << "(cr_ite + 3 == rit): " << (cr_ite + 3 == rit) << std::endl;

		printSize(vct, true);

	}
	return (0);
}

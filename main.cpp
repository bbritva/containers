//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <stack>
#define NAMESPACE ft
//#define NAMESPACE std
#include "vector.hpp"
#include "stack.hpp"

#define COUNT 100

#define TESTED_NAMESPACE NAMESPACE

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

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
#define TESTED_TYPE int
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		for (unsigned long int i = 0; i < vct_c.size(); ++i)
			std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
		try {
			std::cout << vct_c.at(10) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printSize(vct_c);
	}
	return (0);
}

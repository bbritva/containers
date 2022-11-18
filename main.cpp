#include "main.hpp"

int		main()
{
	std::cout << "SUBJECT TESTS:\n";
	std::cout << "Test 1, seed = 1000:\n";
	subject_test(1000);
	std::cout << "Test 2, seed = 1000:\n";
	subject_test(1000);
	std::cout << "Test 3, seed = 10001000:\n";
	subject_test(10001000);

}

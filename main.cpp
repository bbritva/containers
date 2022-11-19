#include "main.hpp"

int subjTests() {
	int result1,result3,result2;
	std::cout << KBLU"SUBJECT TESTS:\n" RST;
	std::cout << "Test 1, seed = 1000:\n";
	result1 =  subject_test(1000);
	std::cout << "Test 2, seed = 1000:\n";
	result2 = subject_test(1000);
	std::cout << "Test 3, seed = 10001000:\n";
	result3 = subject_test(10001000);
	if (result1 == result2 && result1 != result3)
		std::cout << KGRN"===========SUBJECT TESTS PASSED===========\n" RST;
	else {
		std::cout << KRED"===========SUBJECT TESTS FAILED===========\n" RST;
		return 1;
	}
	return 0;
}

int	main() {

//	if (subjTests()) return 1;
	if (vectorTests()) return 1;
	if (stackTests()) return 1;
	return 0;
}

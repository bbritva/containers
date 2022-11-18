#include "main.hpp"


int vectorCapacityTests() {
	const int num = 42;
	int count = 42;
	std::cout << KBLU"Capacity and size:\n" RST;
	std::cout << "Push " << count << " elements\n";
	std::vector<int> vct_std_int;
	ft::vector<int> vct_ft_int;
	for (int i = 0; i < count; ++i) {
		vct_ft_int.push_back(num);
		vct_std_int.push_back(num);
		if (vct_ft_int.size() != vct_std_int.size()
			|| vct_ft_int.capacity() != vct_std_int.capacity()) {
			std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 20;
	std::cout << "Resize to " << count << "\n";
	vct_ft_int.resize(count);
	vct_std_int.resize(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 400;
	std::cout << "Resize to " << count << "\n";
	vct_ft_int.resize(count);
	vct_std_int.resize(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 2;
	std::cout << "Resize to " << count << "\n";
	vct_ft_int.resize(count);
	vct_std_int.resize(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 4200;
	std::cout << "Resize to " << count << "\n";
	vct_ft_int.resize(count);
	vct_std_int.resize(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	std::cout << "Push " << count << " elements\n";

	count = 2;
	for (int i = 0; i < count; ++i) {
		vct_ft_int.push_back(num);
		vct_std_int.push_back(num);
		if (vct_ft_int.size() != vct_std_int.size()
			|| vct_ft_int.capacity() != vct_std_int.capacity()) {
			std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	std::cout << KGRN"===========Capacity and size TESTS PASSED===========\n" RST;
	return 0;
}
int vectorEmptyTests() {
	const int num = 42;
	int count = 4;
	std::cout << KBLU"Empty:\n" RST;
	std::cout << "Create vectors\n";
	std::vector<int> vct_std_int;
	ft::vector<int> vct_ft_int;
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Is empty? " << (vct_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (vct_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "Push " << count << " elements\n";
	for (int i = 0; i < count; ++i) {
		vct_ft_int.push_back(num);
		vct_std_int.push_back(num);
		if (vct_ft_int.size() != vct_std_int.size()
			|| vct_ft_int.capacity() != vct_std_int.capacity()) {
			std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Is empty? " << (vct_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (vct_ft_int.empty() ? "true" : "false") <<"\n";

	std::cout << "Clear vectors\n";
	vct_std_int.clear();
	vct_ft_int.clear();
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========Capacity and size TESTS FAILED===========\n" RST;
		return 1;
	}
	std::cout << "STD: Is empty? " << (vct_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (vct_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";


	std::cout << KGRN"===========Empty TESTS PASSED===========\n" RST;
	return 0;
}


int vectorTests() {
	std::cout << KBLU"Vector TESTS:\n" RST;
	if (vectorCapacityTests()) return 1;
	if (vectorEmptyTests()) return 1;

	std::cout << KGRN"===========Vector TESTS PASSED===========\n" RST;
	return 0;
}
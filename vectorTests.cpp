#include "main.hpp"

template <typename T>
void printVector(const T &vec)
{
	std::cout << "begin:\n";
	size_t size = (vec.size() > 100) ? 100 : vec.size();
	for (size_t i = 0; i < size; ++i) {
		std::cout << "[" << vec[i] << "]";
		if (!((i+1)%10)) std::cout << "\n";
		else std::cout << " ";
	}
	std::cout << "\nend\n";
}

template <typename T, typename U>
bool isVectorsIdentical(const T &vct_ft, const U &vct_std)
{
	if (vct_ft.size() != vct_std.size()) {
		std::cout << KRED"Different size!!!\n" RST;
		std::cout << "STD: Capacity " << vct_std.capacity() << ", size = " << vct_std.size() <<"\n";
		std::cout << "FT:  Capacity " << vct_ft.capacity() << ", size = " << vct_ft.size() <<"\n";
		return false;
	} else {
		for (size_t i = 0; i < vct_ft.size(); ++i) {
			if (vct_ft[i] != vct_std[i]){
				std::cout << "std[" << i << "] " <<  vct_std[i] << " != " <<
				"ft[" << i << "] " <<  vct_ft[i] << "\n";
				std::cout << KRED"Different vectors!!!\n" RST;
				return false;
			}
		}
	}
	std::cout << KGRN"Identical vectors\n" RST;
	return true;
}

int vectorReserve() {
	std::string test_name("Reserve");
	int count = 42;
	std::cout << KBLU"Reserve:\n" RST;
	std::cout << "Create vectors with capacity =  " << count << "\n";
	std::vector<int> vct_std_int(count);
	ft::vector<int> vct_ft_int(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 200;
	std::cout << "Reserve " << count << "\n";
	vct_ft_int.reserve(count);
	vct_std_int.reserve(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 40;
	std::cout << "Reserve " << count << "\n";
	vct_ft_int.reserve(count);
	vct_std_int.reserve(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 2000;
	std::cout << "Reserve " << count << "\n";
	vct_ft_int.reserve(count);
	vct_std_int.reserve(count);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

int vectorCapacity() {
	std::string test_name("Capacity");
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
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Capacity " << vct_std_int.capacity() << ", size = " << vct_std_int.size() <<"\n";
	std::cout << "FT:  Capacity " << vct_ft_int.capacity() << ", size = " << vct_ft_int.size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

int vectorEmpty() {
	std::string test_name("Empty");
	const int num = 42;
	int count = 4;
	std::cout << KBLU"Empty:\n" RST;
	std::cout << "Create vectors\n";
	std::vector<int> vct_std_int;
	ft::vector<int> vct_ft_int;
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
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
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Is empty? " << (vct_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (vct_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

int vectorAssign() {
	std::string test_name("Assign");
	std::cout << KBLU<< test_name <<"\n" RST;
	int num = 42;
	int count = 4;
	std::cout << "Assign vectors " << count <<" elements(" << num <<")\n";
	std::vector<int> vct_std_int;
	ft::vector<int> vct_ft_int;
	vct_std_int.assign(count, num);
	vct_ft_int.assign(count, num);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	isVectorsIdentical(vct_std_int, vct_ft_int);

	num = 400;
	count = 400;
	std::cout << "Assign vectors " << count <<" elements(" << num <<")\n";
	vct_std_int.assign(count, num);
	vct_ft_int.assign(count, num);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	isVectorsIdentical(vct_std_int, vct_ft_int);

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

template<class T>
int createVectors(const std::string& test_name, T = 0)  {
	std::vector<T> vct_std;
	ft::vector<T> vct_ft;
	if (vct_ft.max_size() != vct_std.max_size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: max_size =  " << vct_std.max_size() <<"\n";
	std::cout << "ft:  max_size =  " << vct_ft.max_size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	return 0;
}

int vectorMaxSize() {
	std::string test_name("MaxSize");
	std::cout << KBLU << test_name<< "\n" RST;
	std::cout << "Create vectors with ints:\n";
	if (createVectors(test_name, int())) return 1;
	std::cout << "Create vectors with strings:\n";
	if (createVectors(test_name, std::string())) return 1;
	std::cout << "Create vectors with struct Buffer:\n";
	if (createVectors(test_name, Buffer())) return 1;
	std::cout << "Create vectors with ft::vector<int>:\n";
	if (createVectors(test_name, ft::vector<int>())) return 1;
	std::cout << "Create vectors with std::vector<std::string>:\n";
	if (createVectors(test_name, std::vector<std::string>())) return 1;

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

int vectorIterators() {
	std::string test_name("Iterators");
	std::cout << KBLU << test_name<< "\n" RST;
	std::vector<int> vct_std_int;
	ft::vector<int> vct_ft_int;
	int num = 42;
	int count = 50;
	int count2 = 50;
	std::cout << "Push " << count << " elements\n";
	for (int i = 0; i < count; ++i) {
		vct_ft_int.push_back(num);
		vct_std_int.push_back(num);
	}
	count = 20;
	num = 300;
	std::cout << "insert "<< num <<" to begin() + " << count << "\n";
	vct_std_int.insert(vct_std_int.begin() + count, num);
	vct_ft_int.insert(vct_ft_int.begin() + count, num);
	std::cout << "STD: ";
	printVector(vct_std_int);
	std::cout << "FT:  ";
	printVector(vct_ft_int);
	if (!isVectorsIdentical(vct_std_int, vct_ft_int)) return 1;
	count = 13;
	num = 300;
	count2 = 25;
	std::cout << "insert to (begin() + "<< count2 << ") " << count << " elements(" << num << ")\n";
	vct_std_int.insert(vct_std_int.begin() + count2, count, num);
	vct_ft_int.insert(vct_ft_int.begin() + count2, count, num);
	std::cout << "STD: ";
	printVector(vct_std_int);
	std::cout << "FT:  ";
	printVector(vct_ft_int);
	if (isVectorsIdentical(vct_std_int, vct_ft_int))
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}

int swap() {
	std::string test_name("Swap");
	std::cout << KBLU << test_name<< "\n" RST;
	std::vector<int> vct_std_int1;
	ft::vector<int> vct_ft_int1;
	std::vector<int> vct_std_int2;
	ft::vector<int> vct_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to vectors\n";
	for (int i = 0; i < count; ++i) {
		vct_ft_int1.push_back(num);
		vct_std_int1.push_back(num);
	}
	std::cout << "Push " << num << " elements(" << count << ") to other vectors\n";
	for (int i = 0; i < num; ++i) {
		vct_ft_int2.push_back(count);
		vct_std_int2.push_back(count);
	}
	std::cout << "Before swap:\n";
	std::cout << "STD1: ";
	printVector(vct_std_int1);
	std::cout << "FT1:  ";
	printVector(vct_ft_int1);
	std::cout << "STD2: ";
	printVector(vct_std_int2);
	std::cout << "FT2:  ";
	printVector(vct_ft_int2);
	vct_ft_int1.swap(vct_ft_int2);
	vct_std_int1.swap(vct_std_int2);
	std::cout << "After swap:\n";
	std::cout << "STD1: ";
	printVector(vct_std_int1);
	std::cout << "FT1:  ";
	printVector(vct_ft_int1);
	std::cout << "STD2: ";
	printVector(vct_std_int2);
	std::cout << "FT2:  ";
	printVector(vct_ft_int2);
	if (isVectorsIdentical(vct_std_int1, vct_ft_int1)
	&& isVectorsIdentical(vct_std_int2, vct_ft_int2) )
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}


int vectorTests() {
	std::cout << KMAG BOLD "Vector TESTS:\n" RST;
	if (vectorCapacity()) return 1;
	if (vectorEmpty()) return 1;
	if (vectorReserve()) return 1;
	if (vectorMaxSize()) return 1;
	if (vectorAssign()) return 1;
	if (vectorIterators()) return 1;
	if (swap()) return 1;

	std::cout << KGRN"===========Vector TESTS PASSED===========\n\n" RST;
	return 0;
}
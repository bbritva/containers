#include "main.hpp"

template <typename T>
void printStack(const T &vec)
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
bool isStacksIdentical(const T &vct_ft, const U &vct_std)
{
	if (vct_ft.size() != vct_std.size()) {
		std::cout << KRED"Different size!!!\n" RST;
		return false;
	} else {
		for (size_t i = 0; i < vct_ft.size(); ++i) {
			if (vct_ft[i] != vct_std[i]){
				std::cout << "std[" << i << "] " <<  vct_std[i] << " != " <<
				"ft[" << i << "] " <<  vct_ft[i] << "\n";
				std::cout << KRED"Different stacks!!!\n" RST;
				return false;
			}
		}
	}
	std::cout << KGRN"Identical stacks\n" RST;
	return true;
}

int stackReserve() {
	std::string test_name("Reserve");
	int count = 42;
	std::cout << KBLU"Reserve:\n" RST;
	std::cout << "Create stacks with capacity =  " << count << "\n";
	std::stack<int> vct_std_int(count);
	ft::stack<int> vct_ft_int(count);
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

int stackCapacity() {
	std::string test_name("Capacity");
	const int num = 42;
	int count = 42;
	std::cout << KBLU"Capacity and size:\n" RST;
	std::cout << "Push " << count << " elements\n";
	std::stack<int> vct_std_int;
	ft::stack<int> vct_ft_int;
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

int stackEmpty() {
	std::string test_name("Empty");
	const int num = 42;
	int count = 4;
	std::cout << KBLU"Empty:\n" RST;
	std::cout << "Create stacks\n";
	std::stack<int> vct_std_int;
	ft::stack<int> vct_ft_int;
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

	std::cout << "Clear stacks\n";
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

int stackAssign() {
	std::string test_name("Assign");
	std::cout << KBLU<< test_name <<"\n" RST;
	int num = 42;
	int count = 4;
	std::cout << "Assign stacks " << count <<" elements(" << num <<")\n";
	std::stack<int> vct_std_int;
	ft::stack<int> vct_ft_int;
	vct_std_int.assign(count, num);
	vct_ft_int.assign(count, num);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	isstacksIdentical(vct_std_int, vct_ft_int);

	num = 400;
	count = 400;
	std::cout << "Assign stacks " << count <<" elements(" << num <<")\n";
	vct_std_int.assign(count, num);
	vct_ft_int.assign(count, num);
	if (vct_ft_int.size() != vct_std_int.size()
		|| vct_ft_int.capacity() != vct_std_int.capacity()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	isstacksIdentical(vct_std_int, vct_ft_int);

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

template<class T>
int createstacks(const std::string& test_name, T = 0)  {
	std::stack<T> vct_std;
	ft::stack<T> vct_ft;
	if (vct_ft.max_size() != vct_std.max_size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: max_size =  " << vct_std.max_size() <<"\n";
	std::cout << "ft:  max_size =  " << vct_ft.max_size() <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	return 0;
}

int stackMaxSize() {
	std::string test_name("MaxSize");
	std::cout << KBLU << test_name<< "\n" RST;
	std::cout << "Create stacks with ints:\n";
	if (createstacks(test_name, int())) return 1;
	std::cout << "Create stacks with strings:\n";
	if (createstacks(test_name, std::string())) return 1;
	std::cout << "Create stacks with struct Buffer:\n";
	if (createstacks(test_name, Buffer())) return 1;
	std::cout << "Create stacks with ft::stack<int>:\n";
	if (createstacks(test_name, ft::stack<int>())) return 1;
	std::cout << "Create stacks with std::stack<std::string>:\n";
	if (createstacks(test_name, std::stack<std::string>())) return 1;

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

int stackIterators() {
	std::string test_name("Iterators, insert and erase");
	std::cout << KBLU << test_name<< "\n" RST;
	std::stack<int> vct_std_int;
	ft::stack<int> vct_ft_int;
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
	printstack(vct_std_int);
	std::cout << "FT:  ";
	printstack(vct_ft_int);
	if (!isstacksIdentical(vct_std_int, vct_ft_int)) return 1;
	count = 13;
	num = 300;
	count2 = 25;
	std::cout << "insert to (begin() + "<< count2 << ") " << count << " elements(" << num << ")\n";
	vct_std_int.insert(vct_std_int.begin() + count2, count, num);
	vct_ft_int.insert(vct_ft_int.begin() + count2, count, num);
	std::cout << "STD: ";
	printstack(vct_std_int);
	std::cout << "FT:  ";
	printstack(vct_ft_int);

	count = 13;
	count2 = 25;
	std::cout << "erase from (begin() + "<< count << ") to (end() - "<< count2 << ")\n";
	vct_std_int.erase(vct_std_int.begin() + count, vct_std_int.end() - count2);
	vct_ft_int.erase(vct_ft_int.begin() + count, vct_ft_int.end() - count2);
	std::cout << "STD: ";
	printstack(vct_std_int);
	std::cout << "FT:  ";
	printstack(vct_ft_int);
	if (isstacksIdentical(vct_std_int, vct_ft_int))
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}

int swap() {
	std::string test_name("Swap");
	std::cout << KBLU << test_name<< "\n" RST;
	std::stack<int> vct_std_int1;
	ft::stack<int> vct_ft_int1;
	std::stack<int> vct_std_int2;
	ft::stack<int> vct_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to stacks\n";
	for (int i = 0; i < count; ++i) {
		vct_ft_int1.push_back(num);
		vct_std_int1.push_back(num);
	}
	std::cout << "Push " << num << " elements(" << count << ") to other stacks\n";
	for (int i = 0; i < num; ++i) {
		vct_ft_int2.push_back(count);
		vct_std_int2.push_back(count);
	}
	std::cout << "Before swap:\n";
	std::cout << "STD1: ";
	printstack(vct_std_int1);
	std::cout << "FT1:  ";
	printstack(vct_ft_int1);
	std::cout << "STD2: ";
	printstack(vct_std_int2);
	std::cout << "FT2:  ";
	printstack(vct_ft_int2);
	vct_ft_int1.swap(vct_ft_int2);
	vct_std_int1.swap(vct_std_int2);
	std::cout << "After swap:\n";
	std::cout << "STD1: ";
	printstack(vct_std_int1);
	std::cout << "FT1:  ";
	printstack(vct_ft_int1);
	std::cout << "STD2: ";
	printstack(vct_std_int2);
	std::cout << "FT2:  ";
	printstack(vct_ft_int2);
	if (isstacksIdentical(vct_std_int1, vct_ft_int1)
	&& isstacksIdentical(vct_std_int2, vct_ft_int2) )
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}

int compare(){
	std::string test_name("Compare");
	std::cout << KBLU << test_name<< "\n" RST;
	std::stack<int> vct_std_int1;
	ft::stack<int> vct_ft_int1;
	std::stack<int> vct_std_int2;
	ft::stack<int> vct_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to stacks\n";
	for (int i = 0; i < count; ++i) {
		vct_ft_int1.push_back(num);
		vct_std_int1.push_back(num);
	}
	std::cout << "Push " << num << " elements(" << count << ") to other stacks\n";
	for (int i = 0; i < num; ++i) {
		vct_ft_int2.push_back(count);
		vct_std_int2.push_back(count);
	}
	std::cout << "stacks:\n";
	std::cout << "STD1: ";
	printstack(vct_std_int1);
	std::cout << "FT1:  ";
	printstack(vct_ft_int1);
	std::cout << "STD2: ";
	printstack(vct_std_int2);
	std::cout << "FT2:  ";
	printstack(vct_ft_int2);

	std::cout << "ft stack one == ft stack two:" << std::endl;
	std::cout << ((vct_ft_int1 == vct_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std stack one == std stack two:" << std::endl;
	std::cout << ((vct_ft_int1 == vct_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	std::cout << "Equating stacks\n";

	vct_ft_int1 = vct_ft_int2;
	vct_std_int1 = vct_std_int2;
	std::cout << "stacks:\n";
	std::cout << "STD1: ";
	printstack(vct_std_int1);
	std::cout << "FT1:  ";
	printstack(vct_ft_int1);
	std::cout << "STD2: ";
	printstack(vct_std_int2);
	std::cout << "FT2:  ";
	printstack(vct_ft_int2);
	std::cout << "ft stack one == ft stack two:" << std::endl;
	std::cout << ((vct_ft_int1 == vct_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std stack one == std stack two:" << std::endl;
	std::cout << ((vct_ft_int1 == vct_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	if (isstacksIdentical(vct_std_int1, vct_std_int2)
		&& isstacksIdentical(vct_ft_int1, vct_ft_int2) )
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}

int stackTests() {
	std::cout << KMAG BOLD "Stack TESTS:\n" RST;
	if (stackCapacity()) return 1;
	if (stackEmpty()) return 1;
	if (stackReserve()) return 1;
	if (stackMaxSize()) return 1;
	if (stackAssign()) return 1;
	if (stackIterators()) return 1;
	if (swap()) return 1;
	if (compare()) return 1;

	std::cout << KGRN"===========Stack TESTS PASSED===========\n\n" RST;
	return 0;
}
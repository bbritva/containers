#include "main.hpp"

template <typename Iter>
void printIter(Iter first, Iter last, bool isFt)
{
	int i = 1;
	if (isFt) std::cout << "FT map begin:\n";
	else  std::cout << "STD map begin:\n";
	while(first != last) {
		std::cout << "map[" << first->first << "]" << " = " << first->second;
		if (i%10) std::cout << ", ";
		else std::cout << "\n";
		first++; i++;
	}
	std::cout << "\nend\n";
}

template <typename T, typename U>
bool isMapsIdentical(T first, T last, U otherFirst)
{
	while (first != last) {
		if (first->first != otherFirst->first
			|| first->second != otherFirst->second) {
			std::cout << "std[" << first->first << "] " <<  first->second << " != " <<
			"ft[" << otherFirst->first << "] " <<  otherFirst->second << "\n";
			std::cout << KRED"Different maps!!!\n" RST;
			return false;
		}
		first++; otherFirst++;
	}
	std::cout << KGRN"Identical maps\n" RST;
	return true;
}

static int mapInsertSize() {
	std::string test_name("Insert, Size, Empty");
	const int num = 100;
	int count = 42;
	std::cout << "Create maps\n";

	std::map<int, int> map_std_int;
	ft::map<int, int> map_ft_int;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "Push " << count << " elements\n";

	for (int i = 0; i < count; ++i) {
		map_ft_int.insert(ft::make_pair(i, i + num));
		map_std_int.insert(std::make_pair(i, i + num));
		if (map_ft_int.size() != map_std_int.size()
			|| map_ft_int[i] != map_std_int[i]) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	printIter(map_ft_int.begin(), map_ft_int.end(), true);
	printIter(map_std_int.begin(), map_std_int.end(), true);
	if (!isMapsIdentical(map_ft_int.begin(), map_ft_int.end(), map_std_int.begin()))
		return 1;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 20;
	std::cout << "Delete element with key = " << count << "el\n";
	map_ft_int.erase(count);
	map_std_int.erase(count);
	if (map_ft_int.size() != map_std_int.size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	printIter(map_ft_int.begin(), map_ft_int.end(), true);
	printIter(map_std_int.begin(), map_std_int.end(), true);
	if (!isMapsIdentical(map_ft_int.begin(), map_ft_int.end(), map_std_int.begin()))
		return 1;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << "Clear maps\n";
	map_ft_int.clear();
	map_std_int.clear();
	printIter(map_ft_int.begin(), map_ft_int.end(), true);
	printIter(map_std_int.begin(), map_std_int.end(), true);
	if (!isMapsIdentical(map_ft_int.begin(), map_ft_int.end(), map_std_int.begin()))
		return 1;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

template<class T, class U>
int createMaps(const std::string& test_name, T = 0, U = 0)  {
	std::map<T,U> vct_std;
	ft::map<T,U> vct_ft;
	std::cout << "STD: max_size =  " << vct_std.max_size() <<"\n";
	std::cout << "ft:  max_size =  " << vct_ft.max_size() <<"\n";
	if (vct_ft.max_size() != vct_std.max_size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "--------------------------------------------------------------------------------------\n";
	return 0;
}

static int mapMaxSize() {
	std::string test_name("MaxSize");
	std::cout << KBLU << test_name<< "\n" RST;
	std::cout << "Create Maps with ints:\n";
	if (createMaps(test_name, int(), int())) return 1;
	std::cout << "Create Maps with int and string:\n";
	if (createMaps(test_name, int(), std::string())) return 1;
	std::cout << "Create Maps with int and struct Buffer:\n";
	if (createMaps(test_name, int(), Buffer())) return 1;
	std::cout << "Create Maps with int and ft::vector<int>:\n";
	if (createMaps(test_name, int(), ft::vector<int>())) return 1;
	std::cout << "Create Maps with int and std::vector<std::string>:\n";
	if (createMaps(test_name, int(), std::vector<std::string>())) return 1;

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}


int mapTests() {
	std::cout << KMAG BOLD "Map TESTS:\n" RST;
	if (mapInsertSize()) return 1;
	if (mapMaxSize()) return 1;
//	if (mapAssign()) return 1;
//	if (mapIterators()) return 1;
//	if (swap()) return 1;
//	if (compare()) return 1;

	std::cout << KGRN"===========Map TESTS PASSED===========\n\n" RST;
	return 0;
}
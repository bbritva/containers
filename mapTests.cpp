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
	std::string test_name("Map");
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
	std::cout << "Delete element with key = " << count << "\n";
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

	count = 20;
	std::cout << "Delete with iterators " << count << " elements from begin\n";
	ft::map<int, int>::iterator ft_it = map_ft_int.begin();
	std::map<int, int>::iterator std_it = map_std_int.begin();
	for (int i = 0; i < count; ++i) { ft_it++; std_it++; }
	map_ft_int.erase(map_ft_int.begin(), ft_it);
	map_std_int.erase(map_std_int.begin(), std_it);
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

static int findUpperLower() {
	std::string test_name("Find, Upper, Lower");
	int num = 100;
	int count = 42;
	std::cout << "Create maps\n";
	std::map<int, int> map_std_int;
	ft::map<int, int> map_ft_int;

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
	printIter(map_std_int.begin(), map_std_int.end(), false);
	if (!isMapsIdentical(map_ft_int.begin(), map_ft_int.end(), map_std_int.begin()))
		return 1;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 20;
	std::cout << "Find element with key = " << count << "\n";
	ft::map<int, int>::iterator ft_fit = map_ft_int.find(count);
	std::map<int, int>::iterator std_fit = map_std_int.find(count);
	std::cout << "STD founded el: [" << std_fit->first << "]" << " = " << std_fit->second << "\n";
	std::cout << "FT  founded el: [" << ft_fit->first << "]" << " = " << ft_fit->second << "\n";

	count = 20;
	num = 30;
	std::cout << "Delete from key " << count << "to key " << num << "\n";
	ft_fit = map_ft_int.find(count);
	std_fit = map_std_int.find(count);
	ft::map<int, int>::iterator ft_fit_end = map_ft_int.find(num);
	std::map<int, int>::iterator std_fit_end = map_std_int.find(num);
	map_ft_int.erase(ft_fit, ft_fit_end);
	map_std_int.erase(std_fit, std_fit_end);
	if (map_ft_int.size() != map_std_int.size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	printIter(map_ft_int.begin(), map_ft_int.end(), true);
	printIter(map_std_int.begin(), map_std_int.end(), false);
	if (!isMapsIdentical(map_ft_int.begin(), map_ft_int.end(), map_std_int.begin()))
		return 1;
	std::cout << "STD: Is empty? " << (map_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (map_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 25;
	std::cout << "Upper bound to value " << count << "\n";
	ft_fit = map_ft_int.upper_bound(count);
	std_fit = map_std_int.upper_bound(count);
	std::cout << "STD upper bound el: [" << std_fit->first << "]" << " = " << std_fit->second << "\n";
	std::cout << "FT  upper bound el: [" << ft_fit->first << "]" << " = " << ft_fit->second << "\n";

	std::cout << "Lower bound to value " << count << "\n";
	ft_fit = map_ft_int.lower_bound(count);
	std_fit = map_std_int.lower_bound(count);
	std::cout << "STD lower bound el: [" << std_fit->first << "]" << " = " << std_fit->second << "\n";
	std::cout << "FT  lower bound el: [" << ft_fit->first << "]" << " = " << ft_fit->second << "\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 35;
	std::cout << "Upper bound to value " << count << "\n";
	ft_fit = map_ft_int.upper_bound(count);
	std_fit = map_std_int.upper_bound(count);
	std::cout << "STD upper bound el: [" << std_fit->first << "]" << " = " << std_fit->second << "\n";
	std::cout << "FT  upper bound el: [" << ft_fit->first << "]" << " = " << ft_fit->second << "\n";

	std::cout << "Lower bound to value " << count << "\n";
	ft_fit = map_ft_int.lower_bound(count);
	std_fit = map_std_int.lower_bound(count);
	std::cout << "STD lower bound el: [" << std_fit->first << "]" << " = " << std_fit->second << "\n";
	std::cout << "FT  lower bound el: [" << ft_fit->first << "]" << " = " << ft_fit->second << "\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << "Clear maps\n";
	map_ft_int.clear();
	map_std_int.clear();
	printIter(map_ft_int.begin(), map_ft_int.end(), true);
	printIter(map_std_int.begin(), map_std_int.end(), false);
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
	std::map<T,U> map_std;
	ft::map<T,U> map_ft;
	std::cout << "STD: max_size =  " << map_std.max_size() <<"\n";
	std::cout << "ft:  max_size =  " << map_ft.max_size() <<"\n";
	if (map_ft.max_size() != map_std.max_size()) {
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
	std::cout << "Create Maps with int and ft::map<int, int>:\n";
	if (createMaps(test_name, int(), ft::vector<int>())) return 1;
	std::cout << "Create Maps with int and std::map<std::string>:\n";
	if (createMaps(test_name, int(), std::vector<std::string>())) return 1;

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

static int swap() {
	std::string test_name("Swap");
	std::cout << KBLU << test_name<< "\n" RST;
	std::map<int, int> map_std_int1;
	ft::map<int, int> map_ft_int1;
	std::map<int, int> map_std_int2;
	ft::map<int, int> map_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to maps\n";
	for (int i = 0; i < count; ++i) {
		map_ft_int1.insert(ft::make_pair(i, i + num));
		map_std_int1.insert(std::make_pair(i, i + num));
		if (map_ft_int1.size() != map_std_int1.size()
			|| map_ft_int1[i] != map_std_int1[i]) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "Push " << num << " elements(" << count << ") to other maps\n";
	for (int i = 0; i < num; ++i) {
		map_ft_int2.insert(ft::make_pair(i, i + count));
		map_std_int2.insert(std::make_pair(i, i + count));
		if (map_ft_int2.size() != map_std_int2.size()
			|| map_ft_int2[i] != map_std_int2[i]) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "Before swap:\n";
	std::cout << "1: ";
	printIter(map_std_int1.begin(), map_std_int1.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int1.begin(), map_ft_int1.end(), true);
	std::cout << "2: ";
	printIter(map_std_int2.begin(), map_std_int2.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int2.begin(), map_ft_int2.end(), true);

	map_ft_int1.swap(map_ft_int2);
	map_std_int1.swap(map_std_int2);
	std::cout << "After swap:\n";
	std::cout << "1: ";
	printIter(map_std_int1.begin(), map_std_int1.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int1.begin(), map_ft_int1.end(), true);
	std::cout << "2: ";
	printIter(map_std_int2.begin(), map_std_int2.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int2.begin(), map_ft_int2.end(), true);
	if (!isMapsIdentical(map_ft_int1.begin(), map_ft_int1.end(), map_std_int1.begin())
		|| !isMapsIdentical(map_ft_int2.begin(), map_ft_int2.end(), map_std_int2.begin())) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	return 0;
}

static int compare(){
	std::string test_name("Compare");
	std::cout << KBLU << test_name<< "\n" RST;
	std::map<int, int> map_std_int1;
	ft::map<int, int> map_ft_int1;
	std::map<int, int> map_std_int2;
	ft::map<int, int> map_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to maps\n";
	for (int i = 0; i < count; ++i) {
		map_ft_int1.insert(ft::make_pair(i, i + num));
		map_std_int1.insert(std::make_pair(i, i + num));
		if (map_ft_int1.size() != map_std_int1.size()
			|| map_ft_int1[i] != map_std_int1[i]) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "Push " << num << " elements(" << count << ") to other maps\n";
	for (int i = 0; i < num; ++i) {
		map_ft_int2.insert(ft::make_pair(i, i + count));
		map_std_int2.insert(std::make_pair(i, i + count));
		if (map_ft_int2.size() != map_std_int2.size()
			|| map_ft_int2[i] != map_std_int2[i]) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "Maps:\n";
	std::cout << "1: ";
	printIter(map_std_int1.begin(), map_std_int1.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int1.begin(), map_ft_int1.end(), true);
	std::cout << "2: ";
	printIter(map_std_int2.begin(), map_std_int2.end(), false);
	std::cout << "1:  ";

	std::cout << "ft map one == ft map two:" << std::endl;
	std::cout << ((map_ft_int1 == map_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std map one == std map two:" << std::endl;
	std::cout << ((map_ft_int1 == map_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	std::cout << "Equating maps\n";

	map_ft_int1 = map_ft_int2;
	map_std_int1 = map_std_int2;
	std::cout << "Maps:\n";
	std::cout << "1: ";
	printIter(map_std_int1.begin(), map_std_int1.end(), false);
	std::cout << "1:  ";
	printIter(map_ft_int1.begin(), map_ft_int1.end(), true);
	std::cout << "2: ";
	printIter(map_std_int2.begin(), map_std_int2.end(), false);
	std::cout << "1:  ";
	std::cout << "ft map one == ft map two:" << std::endl;
	std::cout << ((map_ft_int1 == map_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std map one == std map two:" << std::endl;
	std::cout << ((map_ft_int1 == map_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	if (!isMapsIdentical(map_ft_int1.begin(), map_ft_int1.end(), map_std_int1.begin())
		|| !isMapsIdentical(map_ft_int2.begin(), map_ft_int2.end(), map_std_int2.begin())) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	return 0;
}


int mapTests() {
	std::cout << KMAG BOLD "Map TESTS:\n" RST;
	if (mapInsertSize()) return 1;
	if (mapMaxSize()) return 1;
	if (findUpperLower()) return 1;
	if (swap()) return 1;
	if (compare()) return 1;

	std::cout << KGRN"===========Map TESTS PASSED===========\n\n" RST;
	return 0;
}
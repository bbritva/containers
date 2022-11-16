//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <map>
#include <stack>
#include <list>

#define NAMESPACE ft
//#define NAMESPACE std
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
//#include "daria/map.hpp"
//#include "containers_test/srcs/base.hpp"

//#define TESTED_TYPE foo<int>
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define COUNT 100
#define _pair TESTED_NAMESPACE::pair

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << (char)iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T3, typename T4>
void	printReverse(TESTED_NAMESPACE::map<T3, T4> &mp)
{
	typename TESTED_NAMESPACE::map<T3, T4>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main() {
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, (i + 1) * 7));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it_ = mp.begin();
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(it_), ite;
	printSize(mp);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	printReverse(mp);

	return (0);
}
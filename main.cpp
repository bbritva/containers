//
// Created by grvelva on 8/25/22.
//
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <iomanip>

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

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

#define COUNT 100
#define _pair TESTED_NAMESPACE::pair

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class Key, class T>
void	print(ft::map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main() {
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

	return 0;
}
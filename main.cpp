//#include <iterator>
#include "main.hpp"
#if STL == 1
#include <map>
#define _NAMESPACE std
# else
#include "map.hpp"
#define _NAMESPACE ft
#endif

#include <iostream>
#include <algorithm>

#include <sys/time.h>

time_t time() {
	struct timeval start = {};
	gettimeofday(&start, NULL);
	time_t ms = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return ms;
}


void testConstructorMap() {
	_NAMESPACE::map<char,int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	_NAMESPACE::map<char,int> second (first.begin(),first.end());

	_NAMESPACE::map<char,int> third (second);

	_NAMESPACE::map<char,int>::iterator it;

	for (it = third.begin(); it != third.end(); it++)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

}

void testBegin() {
	_NAMESPACE::map<char, int> map;

	map['b'] = 100;
	map['a'] = 200;
	map['c'] = 300;

	// show content:
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testClearMap() {
	_NAMESPACE::map<char, int> map;

	map['x'] = 100;
	map['y'] = 200;
	map['z'] = 300;

	std::cout << "\tmap contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

	map.clear();
	map['a'] = 1101;
	map['b'] = 2202;

	std::cout << "\tmap contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testCount() {
	char c;
	_NAMESPACE::map<char, int> map;

	map['a'] = 101;
	map['c'] = 202;
	map['f'] = 303;

	for (c = 'a'; c < 'h'; c++) {
		std::cout << "\t " << c;
		if (map.count(c) > 0)
			std::cout << "\t  is an element of map.\n";
		else
			std::cout << "\t  is not an element of map.\n";
	}
}

void testEmptyMap() {
	_NAMESPACE::map<char,int> map;

	map['a']=10;
	map['b']=20;
	map['c']=30;

	while (!map.empty())
	{
		std::cout << "\t" << map.begin()->first << " => " << map.begin()->second << '\n';
		map.erase(map.begin());
	}
}

void testEnd() {
	_NAMESPACE::map<char,int> map;

	map['b'] = 100;
	map['a'] = 200;
	map['c'] = 300;

	// show content:
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testEqualRange() {
	_NAMESPACE::map<char, int> map;

	map['a'] = 10;
	map['b'] = 20;
	map['c'] = 30;

	_NAMESPACE::pair<_NAMESPACE::map<char, int>::iterator, _NAMESPACE::map<char, int>::iterator> ret;
	ret = map.equal_range('b');

	std::cout << "\tlower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "\tupper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void testEraseMap() {
	_NAMESPACE::map<char, int> map;
	_NAMESPACE::map<char, int>::iterator it;

	// insert some values:
	map['a'] = 10;
	map['b'] = 20;
	map['c'] = 30;
	map['d'] = 40;
	map['e'] = 50;
	map['f'] = 60;

	it = map.find('b');
	map.erase(it);                   // erasing by iterator

	map.erase('c');                  // erasing by key

	it = map.find('e');
	map.erase(it, map.end());    // erasing by range

	// show content:
	for (it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testFind() {
	_NAMESPACE::map<char,int> map;
	_NAMESPACE::map<char,int>::iterator it;

	map['a']=50;
	map['b']=100;
	map['c']=150;
	map['d']=200;

	it = map.find('b');
	if (it != map.end())
		map.erase (it);

	// print content:
	std::cout << "\telements in map:" << '\n';
	std::cout << "\ta => " << map.find('a')->second << '\n';
	it = map.find('c');
	std::cout << "\tc => " << it->second << '\n';
	std::cout << "\td => " << map.find('d')->second << '\n';
}

void testGetAllocator() {
	_NAMESPACE::map<char, int> map;
	_NAMESPACE::pair<const char, int> *p;

	// allocate an array of 5 elements using map's allocator:
	p = map.get_allocator().allocate(5);

	// assign some values to array
	int psize = sizeof(_NAMESPACE::map<char, int>::value_type) * 5;

	std::cout << "\tThe allocated array has a size of " << psize << " bytes.\n";

	map.get_allocator().deallocate(p, 5);

}

void testInsertMap() {
	_NAMESPACE::map<char, int> map;

	// first insert function version (single parameter):
	map.insert(_NAMESPACE::pair<char, int>('a', 100));
	map.insert(_NAMESPACE::pair<char, int>('z', 200));

	_NAMESPACE::pair<_NAMESPACE::map<char, int>::iterator, bool> ret;
	ret = map.insert(_NAMESPACE::pair<char, int>('z', 500));
	if (ret.second == false) {
		std::cout << "\telement 'z' already existed";
		std::cout << "\t with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	_NAMESPACE::map<char, int>::iterator it = map.begin();
	map.insert (it, _NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
	map.insert (it, _NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	_NAMESPACE::map<char, int> anothermap;
	anothermap.insert(map.begin(), map.find('c'));

	// showing contents:
	std::cout << "\tmap contains:\n";
	for (it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

	std::cout << "\tanothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testKeyComp() {
	_NAMESPACE::map<char,int> map;
	_NAMESPACE::map<char,int>::key_compare comp = map.key_comp();

	map['a']=100;
	map['b']=200;
	map['c']=300;

	std::cout << "\t" << "map contains:\n";

	char highest = map.rbegin()->first;     // key value of last element

	_NAMESPACE::map<char,int>::iterator it = map.begin();
	do {
		std::cout << "\t" << it->first << " => " << it->second << '\n';
	} while ( comp((*it++).first, highest) );

	std::cout << '\n';
}

void testLowerBound() {
	_NAMESPACE::map<char,int> map;
	_NAMESPACE::map<char,int>::iterator itlow,itup;

	map['a'] = 20;
	map['b'] = 40;
	map['c'] = 60;
	map['d'] = 80;
	map['e'] = 100;

	itlow = map.lower_bound('b');  // itlow points to b
	itup = map.upper_bound('d');   // itup points to e (not d!)

	map.erase(itlow, itup);        // erases [itlow,itup)

	// print content:
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testMaxSizeMap() {
	int i;
	_NAMESPACE::map<int, int> map;

	if (map.max_size() > 1000) {
		for (i = 0; i < 1000; i++) map[i] = 0;
		std::cout << "\tThe map contains 1000 elements.\n";
	} else std::cout << "\tThe map could not hold 1000 elements.\n";

}

void testUpperBound() {
	_NAMESPACE::map<char, int> map;
	_NAMESPACE::map<char, int>::iterator itlow, itup;

	map['a'] = 20;
	map['b'] = 40;
	map['c'] = 60;
	map['d'] = 80;
	map['e'] = 100;

	itlow = map.lower_bound('b');  // itlow points to b
	itup = map.upper_bound('d');   // itup points to e (not d!)

	map.erase(itlow, itup);        // erases [itlow,itup)

	// print content:
	for (_NAMESPACE::map<char, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';
}

void testSizeMap() {
	_NAMESPACE::map<char,int> map;
	map['a']=101;
	map['b']=202;
	map['c']=302;

	std::cout << "\tmap.size() is " << map.size() << '\n';
}

void testRbeginMap() {
	_NAMESPACE::map<char, int> map;

	map['x'] = 100;
	map['y'] = 200;
	map['z'] = 300;

	// show content:
	_NAMESPACE::map<char, int>::reverse_iterator rit;
	for (rit = map.rbegin(); rit != map.rend(); ++rit)
		std::cout << "\t" << rit->first << " => " << rit->second << '\n';
}

void testRendMap() {
	_NAMESPACE::map<char, int> map;

	map['x'] = 100;
	map['y'] = 200;
	map['z'] = 300;

	// show content:
	_NAMESPACE::map<char, int>::reverse_iterator rit;
	for (rit = map.rbegin(); rit != map.rend(); ++rit)
		std::cout << "\t" << rit->first << " => " << rit->second << '\n';
}

void testAccessElement() {
	_NAMESPACE::map<char, std::string> map;

	map['a'] = "an element";
	map['b'] = "another element";
	map['c'] = map['b'];

	std::cout << "\tmap['a'] is " << map['a'] << '\n';
	std::cout << "\tmap['b'] is " << map['b'] << '\n';
	std::cout << "\tmap['c'] is " << map['c'] << '\n';
	std::cout << "\tmap['d'] is " << map['d'] << '\n';

	std::cout << "\tmap now contains " << map.size() << " elements.\n";
}

void testCopyContent() {
	_NAMESPACE::map<char, int> first;
	_NAMESPACE::map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;                // second now contains 3 ints
	first = _NAMESPACE::map<char, int>();  // and first is now empty

	std::cout << "\tSize of first: " << first.size() << '\n';
	std::cout << "\tSize of second: " << second.size() << '\n';
}

void testMapRelationalOperators() {
	_NAMESPACE::map<char, int> foo, bar;
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 10;
	bar['z'] = 1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo == bar) std::cout << "\t" << "foo and bar are equal\n";
	if (foo != bar) std::cout << "\t" << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "\t" << "foo is less than bar\n";
	if (foo > bar) std::cout << "\t" << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "\t" << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "\t" << "foo is greater than or equal to bar\n";
}

void testSwapMap() {
	_NAMESPACE::map<char,int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	std::cout << "\t" << "foo contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

	std::cout << "\t" << "bar contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

}

void testSwapMapNonMember() {
	_NAMESPACE::map<char,int> foo,bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	swap(foo, bar);

	std::cout << "\t" << "foo contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

	std::cout << "\t" << "bar contains:\n";
	for (_NAMESPACE::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << '\n';

}

void testValueComp() {
	_NAMESPACE::map<char, int> map;

	map['x'] = 1001;
	map['y'] = 2002;
	map['z'] = 3003;

	std::cout << "\t" << "map contains:\n";

	_NAMESPACE::pair<char, int> highest = *map.rbegin();          // last element

	_NAMESPACE::map<char, int>::iterator it = map.begin();
	do {
		std::cout << "\t" << it->first << " => " << it->second << '\n';
	} while (map.value_comp()(*it++, highest));
}

void testMap() {
	testConstructorMap();
	std::cout << FBLU("Constructor ^") << std::endl;

	testBegin();
	std::cout << FBLU("Begin ^") << std::endl;

	testClearMap();
	std::cout << FBLU("Clear ^") << std::endl;

	testCount();
	std::cout << FBLU("Count ^") << std::endl;

	testEraseMap();
	std::cout << FBLU("Erase ^") << std::endl;

	testEmptyMap();
	std::cout << FBLU("Empty ^") << std::endl;

	testEnd();
	std::cout << FBLU("End ^") << std::endl;

	testEqualRange();
	std::cout << FBLU("Equal Range ^") << std::endl;

	testFind();
	std::cout << FBLU("Find ^") << std::endl;

	testGetAllocator();
	std::cout << FBLU("Get Allocator ^") << std::endl;

	testInsertMap();
	std::cout << FBLU("Insert ^") << std::endl;

	testKeyComp();
	std::cout << FBLU("Key Comp ^") << std::endl;

	testValueComp();
	std::cout << FBLU("Value Comp ^") << std::endl;

	testLowerBound();
	std::cout << FBLU("Lower Bound ^") << std::endl;

	testMaxSizeMap();
	std::cout << FBLU("Max Size ^") << std::endl;

	testUpperBound();
	std::cout << FBLU("Upper Bound ^") << std::endl;

	testSizeMap();
	std::cout << FBLU("Size ^") << std::endl;

	testRbeginMap();
	std::cout << FBLU("Rbegin ^") << std::endl;

	testRendMap();
	std::cout << FBLU("Rend ^") << std::endl;

	testAccessElement();
	std::cout << FBLU("Access Element ^") << std::endl;

	testCopyContent();
	std::cout << FBLU("Copy Content ^") << std::endl;

	testMapRelationalOperators();
	std::cout << FBLU("Relational Operators ^") << std::endl;

	testSwapMap();
	std::cout << FBLU("Swap ^") << std::endl;

	testSwapMapNonMember();
	std::cout << FBLU("Swap Non Member ^") << std::endl;

}

int main() {

	long timestamp1;
	timestamp1 = time();

	std::cout << BOLD(FYEL("M A P   T E S T")) << std::endl;
	testMap();
//	testSwapMapNonMember();



	long timestamp2;
	timestamp2 = time();

	std::cout << "time " << (timestamp2 - timestamp1) << "\n";

}

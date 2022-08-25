#include <iostream>
#include <string>
#include <deque>
//#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
    #include <vector>
    #define STACK std::stack
//    #define VECTOR std::vector
    #define MAP std::map
//#else
//    #define STACK ft::stack
    #define VECTOR ft::vector
//    #define MAP ft::map
    #include "vector.hpp"
//    #include "Map.hpp"
//    #include "Stack.hpp"
//#endif

#include <cstdlib>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int		idx;
	char	buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public STACK<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename STACK<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
    ft::vector<Buffer> vec;
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	VECTOR<std::string> vector_str;
    VECTOR<int> vector_int;
	STACK<int> stack_int;
    VECTOR<Buffer> vector_buffer;
	STACK<Buffer, std::deque<Buffer> > stack_deq_buffer;
	MAP<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
//    VECTOR<Buffer>().swap(vector_buffer);

//	try
//	{
//		for (int i = 0; i < COUNT; i++)
//		{
//			const int idx = rand() % COUNT;
//			vector_buffer.at(idx);
//			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//		}
//	}
//	catch(const std::exception& e)
//	{
//		//NORMAL ! :P
//	}

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(std::make_pair(rand(), rand()));
//		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		MAP<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}

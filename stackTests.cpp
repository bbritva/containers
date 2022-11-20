#include "main.hpp"

static int pushPopTop() {
	std::string test_name("PushPopTop");
	int count = 42;
	std::cout << "Push " << count << " elements\n";
	std::stack<int> stk_std_int;
	ft::stack<int> stk_ft_int;
	for (int i = 0; i < count; ++i) {
		stk_ft_int.push(i);
		stk_std_int.push(i);
		if (stk_ft_int.top() != stk_std_int.top()
			|| stk_ft_int.size() != stk_std_int.size()) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "std::stack top = "<< stk_std_int.top() << ", size = "<< stk_std_int.size() << "\n";
	std::cout << "ft::stack top  = "<< stk_ft_int.top() << ", size = "<< stk_ft_int.size() << "\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	count = 10;
	std::cout << "Pop " << count << " elements\n";
	for (int i = 0; i < count; ++i) {
		stk_ft_int.pop();
		stk_std_int.pop();
		if (stk_ft_int.top() != stk_std_int.top()
			|| stk_ft_int.size() != stk_std_int.size()) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "std::stack top = "<< stk_std_int.top() << ", size = "<< stk_std_int.size() << "\n";
	std::cout << "ft::stack top  = "<< stk_ft_int.top() << ", size = "<< stk_ft_int.size() << "\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

static int stackEmpty() {
	std::string test_name("Empty");
	const int num = 42;
	int count = 4;
	std::cout << KBLU"Empty:\n" RST;
	std::cout << "Create stacks\n";
	std::stack<int> stk_std_int;
	ft::stack<int> stk_ft_int;
	if (stk_ft_int.size() != stk_std_int.size()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "STD: Is empty? " << (stk_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (stk_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "Push " << count << " elements\n";
	for (int i = 0; i < count; ++i) {
		stk_ft_int.push(num);
		stk_std_int.push(num);
		if (stk_ft_int.size() != stk_std_int.size()
			|| stk_ft_int.top() != stk_std_int.top()) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Is empty? " << (stk_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (stk_ft_int.empty() ? "true" : "false") <<"\n";

	std::cout << "Clear stacks\n";
	while (stk_ft_int.size()) {
		stk_ft_int.pop();
		stk_std_int.pop();
		if (stk_ft_int.size() != stk_std_int.size()) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "STD: Is empty? " << (stk_std_int.empty() ? "true" : "false") <<"\n";
	std::cout << "FT:  Is empty? " << (stk_ft_int.empty() ? "true" : "false") <<"\n";
	std::cout << "--------------------------------------------------------------------------------------\n";

	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

static int stackAssign() {
	std::string test_name("Operator =");
	std::cout << KBLU<< test_name <<"\n" RST;
	int count = 4;
	std::cout << "Push stacks " << count <<" elements\n";
	std::stack<int> stk_std_int;
	ft::stack<int> stk_ft_int;
	for (int i = 0; i < count; ++i) {
		stk_ft_int.push(i);
		stk_std_int.push(i);
		if (stk_ft_int.size() != stk_std_int.size()
			|| stk_ft_int.top() != stk_std_int.top()) {
			std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
			return 1;
		}
	}
	std::cout << "std::stack top = "<< stk_std_int.top() << ", size = "<< stk_std_int.size() << "\n";
	std::cout << "ft::stack top  = "<< stk_ft_int.top() << ", size = "<< stk_ft_int.size() << "\n";
	std::cout << "Creating stacks by operator =\n";
	std::stack<int> stk_std_int1 = stk_std_int;
	ft::stack<int> stk_ft_int1 = stk_ft_int;
	if (stk_ft_int1.size() != stk_std_int1.size()
		|| stk_ft_int.top() != stk_std_int.top()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "std::stack1 top = "<< stk_std_int.top() << ", size = "<< stk_std_int.size() << "\n";
	std::cout << "ft::stack1 top  = "<< stk_ft_int.top() << ", size = "<< stk_ft_int.size() << "\n";

	std::cout << "Pop from original stacks\n";
	stk_ft_int.pop();
	stk_std_int.pop();
	if (stk_ft_int1.size() == stk_ft_int.size()
		|| stk_ft_int1.top() == stk_ft_int.top()) {
		std::cout << KRED"===========" << test_name << " TESTS FAILED===========\n\n" RST;
		return 1;
	}
	std::cout << "ft::stack  top = "<< stk_std_int.top() << ", size = "<< stk_std_int.size() << "\n";
	std::cout << "ft::stack1 top = "<< stk_ft_int.top() << ", size = "<< stk_ft_int.size() << "\n";
	std::cout << "ft stack one == ft stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std stack one == std stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	return 0;
}

static int compare(){
	std::string test_name("Compare");
	std::cout << KBLU << test_name<< "\n" RST;
	std::stack<int> stk_std_int1;
	ft::stack<int> stk_ft_int1;
	std::stack<int> stk_std_int2;
	ft::stack<int> stk_ft_int2;
	int num = 3;
	int count = 5;
	std::cout << "Push " << count << " elements(" << num << ") to stacks\n";
	for (int i = 0; i < count; ++i) {
		stk_ft_int1.push(num);
		stk_std_int1.push(num);
	}
	std::cout << "Push " << num << " elements(" << count << ") to other stacks\n";
	for (int i = 0; i < num; ++i) {
		stk_ft_int2.push(count);
		stk_std_int2.push(count);
	}

	std::cout << "ft stack one == ft stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std stack one == std stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	std::cout << "Equating stacks\n";

	stk_ft_int1 = stk_ft_int2;
	stk_std_int1 = stk_std_int2;
	std::cout << "ft stack one == ft stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;
	std::cout << "std stack one == std stack two:" << std::endl;
	std::cout << ((stk_ft_int1 == stk_ft_int2) ? KGRN "True" RST : KRED "False" RST ) << std::endl;

	if (stk_std_int1 == stk_std_int2
		&& stk_ft_int1 == stk_ft_int2)
		std::cout << KGRN"===========" << test_name << " TESTS PASSED===========\n\n" RST;
	else
		return 1;
	return 0;
}

int stackTests() {
	std::cout << KMAG BOLD "Stack TESTS:\n" RST;
	if (pushPopTop()) return 1;
	if (stackEmpty()) return 1;
	if (stackAssign()) return 1;
	if (compare()) return 1;

	std::cout << KGRN"===========Stack TESTS PASSED===========\n\n" RST;
	return 0;
}
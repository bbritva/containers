//
// Created by grvelva on 11/17/22.
//

#ifndef MAIN_CPP_MAIN_HPP
#define MAIN_CPP_MAIN_HPP

#include <iostream>
#include <string>
#include <deque>

#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
#define COUNT (MAX_RAM / (int)sizeof(Buffer))
//#define COUNT 10000

// COLORS
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

int subject_test(int seed);

#endif //MAIN_CPP_MAIN_HPP

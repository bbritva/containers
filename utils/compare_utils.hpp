//
// Created by grvelva on 11/11/22.
//

#ifndef MAIN_CPP_COMPARE_UTILS_HPP
#define MAIN_CPP_COMPARE_UTILS_HPP

namespace ft {
	template<class T, class U>
	bool lexicographical_compare(T first1, T last1, U first2, U last2) {
		while (first1 != last1 && first2 != last2) {
			if (first2 == last2 || *first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			first1++;
			first2++;
		}
		return first2 != last2;
	}

	template<class T, class U>
	bool equal(T first1, T last1, U first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif //MAIN_CPP_COMPARE_UTILS_HPP

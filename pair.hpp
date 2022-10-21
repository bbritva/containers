//
// Created by grvelva on 10/21/22.
//

#ifndef CONTAINERS_PAIR_HPP
#define CONTAINERS_PAIR_HPP

namespace ft {
	template <class T1, class T2>
	class pair
	{
	public:
		T1 first;
		T2 second;

		pair() : first(), second() {}

		template<class U, class V>
		pair(const pair<U, V>& other) : first(other.first), second(other.second) {}

		pair(const T1& a, const T2& b) : first(a), second(b) {}

		pair& operator=(const pair& other)
		{
			if (*this == other)
				return *this;
			first = other.first;
			second = other.second;
			return *this;
		}
	};
}

#endif //CONTAINERS_PAIR_HPP

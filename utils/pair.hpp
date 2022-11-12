//
// Created by grvelva on 10/21/22.
//

#ifndef CONTAINERS_PAIR_HPP
#define CONTAINERS_PAIR_HPP

namespace ft {
	template <class Key, class Value>
	class pair
	{
	public:
		typedef Key first_type;
		typedef Value second_type;

		first_type	first;
		second_type	second;

		pair() : first(), second() {}

		template<class U, class V>
		explicit pair(const pair<U, V>& other) : first(other.first), second(other.second) {}

		pair(const first_type& a, const second_type& b) : first(a), second(b) {}

		pair& operator=(const pair& other)
		{
			if (*this == other)
				return *this;
			first = other.first;
			second = other.second;
			return *this;
		}
		~pair(){};

		operator pair<const first_type, second_type>() const {
			return (pair<const first_type, second_type>(*this));
		}
	};

//	template<typename _T1, typename _T2>
//	inline pair<_T1, _T2>
//	make_pair(_T1 __x, _T2 __y)
//	{ return pair<_T1, _T2>(__x, __y); }

	template <class first_type, class second_type>
	pair<first_type, second_type> make_pair(first_type key, second_type value) {
		return ft::pair<first_type, second_type>(key, value);
	}

	template <class first_type, class second_type>
	bool operator==(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return first.first == second.first && first.second == second.second;
	}

	template <class first_type, class second_type>
	bool operator!=(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return !(first == second);
	}

	template <class first_type, class second_type>
	bool operator<(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return first.first < second.first \
 				|| (!(second.first < first.first) && first.second < second.second);
	}

	template <class first_type, class second_type>
	bool operator<=(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return !(second < first);
	}

	template <class first_type, class second_type>
	bool operator>(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return second < first;
	}

	template <class first_type, class second_type>
	bool operator>=(const ft::pair<first_type,second_type>& first, const ft::pair<first_type,second_type>& second) {
		return !(first < second);
	}
}

#endif //CONTAINERS_PAIR_HPP

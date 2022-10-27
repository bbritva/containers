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
		T1 _key;
		T2 _value;

		pair() : _key(), _value() {}

		template<class U, class V>
		pair(const pair<U, V>& other) : _key(other._key), _value(other._value) {}

		pair(const T1& a, const T2& b) : _key(a), _value(b) {}

		pair& operator=(const pair& other)
		{
//			if (*this == other)
//				return *this;
			_key = other._key;
			_value = other._value;
			return *this;
		}
	};
}

#endif //CONTAINERS_PAIR_HPP

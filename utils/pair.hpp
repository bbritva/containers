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
		Key _key;
		Value _value;

		pair() : _key(), _value() {}

		template<class U, class V>
		pair(const pair<U, V>& other) : _key(other._key), _value(other._value) {}

		pair(const Key& a, const Value& b) : _key(a), _value(b) {}

		pair& operator=(const pair& other)
		{
			if (*this == other)
				return *this;
			_key = other._key;
			_value = other._value;
			return *this;
		}
	};

	template <class Key, class Value>
	pair<Key, Value> make_pair(Key key, Value value) {
		return ft::pair<Key, Value>(key, value);
	}

	template <class Key, class Value>
	bool operator==(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return first._key == second._key && first._value == second._value;
	}

	template <class Key, class Value>
	bool operator!=(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return !(first == second);
	}

	template <class Key, class Value>
	bool operator<(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return first._key < second._key \
			|| (!(second._key < first._key) \
			&& first._value < second._value);
	}

	template <class Key, class Value>
	bool operator<=(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return !(second < first);
	}

	template <class Key, class Value>
	bool operator>(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return second < first;
	}

	template <class Key, class Value>
	bool operator>=(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return !(first < second);
	}
}

#endif //CONTAINERS_PAIR_HPP

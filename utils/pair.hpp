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
		Key		first;
		Value	second;

		pair() : first(), second() {}

		template<class U, class V>
		explicit pair(const pair<U, V>& other) : first(other.first), second(other.second) {}

		pair(const Key& a, const Value& b) : first(a), second(b) {}

		pair& operator=(const pair& other)
		{
			if (*this == other)
				return *this;
			first = other.first;
			second = other.second;
			return *this;
		}
		~pair(){};

		operator pair<const Key, Value>() const {
			return (pair<const Key, Value>(*this));
		}
	};

	template <class Key, class Value>
	pair<Key, Value> make_pair(const Key &key, const Value &value) {
		return ft::pair<Key, Value>(key, value);
	}

	template <class Key, class Value>
	bool operator==(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return first.first == second.first && first.second == second.second;
	}

	template <class Key, class Value>
	bool operator!=(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return !(first == second);
	}

	template <class Key, class Value>
	bool operator<(const ft::pair<Key,Value>& first, const ft::pair<Key,Value>& second) {
		return first.first < second.first \
 				|| (!(second.first < first.first) && first.second < second.second);
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

//
// Created by grvelva on 9/14/22.
//

#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP

#include "vector.hpp"

namespace ft {
	template<typename T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef Container container_type;
	private:
		Container _data;

	public:
		explicit stack(const Container& cont = Container()) : _data(cont){
		};

		stack(const stack &other) : _data(other._data) {}

		stack &operator=(const stack &other) {
			if (this == &other)
				return (*this);
			_data = other._data;
			return *this;
		}

		T& top() {
			return _data.back();
		}

		const T& top() const {
			return _data.back();
		}

		bool empty() const {
			return _data.empty();
		}

		std::size_t size() const {
			return _data.size();
		}

		void push(const T element) {
			_data.push_back(element);
		}

		void pop() {
			_data.pop_back();
		}

		const Container &getData() const {
			return _data;
		}
	};

	template<class T, class Container>
	bool operator==(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return first.getData() == second.getData();
	}

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return !(first == second);
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return first.getData() < second.getData();
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return first.getData() <= second.getData();
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return first.getData() > second.getData();
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &first,
					const stack<T, Container> &second) {
		return first.getData() >= second.getData();
	}
}

#endif //CONTAINERS_STACK_HPP

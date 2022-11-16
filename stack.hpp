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

	protected:
		Container c;
	public:
		explicit stack(const Container& cont = Container()) : c(cont){
		};

		stack(const stack &other) : c(other.c) {}

		stack &operator=(const stack &other) {
			if (this == &other)
				return (*this);
			c = other.c;
			return *this;
		}

		T& top() {
			return c.back();
		}

		const T& top() const {
			return c.back();
		}

		bool empty() const {
			return c.empty();
		}

		std::size_t size() const {
			return c.size();
		}

		void push(const T element) {
			c.push_back(element);
		}

		void pop() {
			c.pop_back();
		}

		const Container &getData() const {
			return c;
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

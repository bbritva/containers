//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_DIRECT_VECTOR_ITERATOR_HPP
# define CONTAINERS_DIRECT_VECTOR_ITERATOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "sfinae.hpp"

namespace ft {

	template<class T>
	class random_access_iterator : public ft::iterator_base<ft::random_access_iterator_tag, T> {
	private:
		T *_pointer;
	public:
		random_access_iterator() : _pointer(NULL) {}

		explicit random_access_iterator(T *x) : _pointer(x) {}

		random_access_iterator(const random_access_iterator &other) : _pointer(other._pointer) {}

		random_access_iterator &operator=(random_access_iterator const &other) {
			if (this == &other)
				return (*this);
			_pointer = other._pointer;
			return (*this);
		}

		operator random_access_iterator<const T>() const {
			return (random_access_iterator<const T>(this->_pointer));
		}

		random_access_iterator &operator++() {
			++_pointer;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator tmp(*this);
			operator++();
			return tmp;
		}

		random_access_iterator &operator--() {
			--_pointer;
			return *this;
		}

		random_access_iterator operator--(int) {
			random_access_iterator tmp(*this);
			operator--();
			return tmp;
		}

		random_access_iterator operator+(std::size_t step) const {
			return random_access_iterator(_pointer + step);
		}

		random_access_iterator operator-(std::size_t step) const {
			return random_access_iterator(_pointer - step);
		}

		long int operator-(const random_access_iterator &other) const {
			return (_pointer - other._pointer);
		}

		random_access_iterator operator+=(std::size_t step) {
			_pointer += step;
			return *this;
		}

		random_access_iterator operator-=(std::size_t step) {
			_pointer -= step;
			return *this;
		}

		T &operator[](std::size_t offset) {
			return *(_pointer + offset);
		}

		T &operator*() {
			return *_pointer;
		}

		T *operator->() {
			return _pointer;
		}

		T *getPtr() const {
			return _pointer;
		}

	};

	template <class T>
	bool operator==(const random_access_iterator<T> first,
					const random_access_iterator<T> second) {
		return first.getPtr() == second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const random_access_iterator<T_F> first,
					const random_access_iterator<T_S> second) {
		return first.getPtr() == second.getPtr();
	}

	template <class T>
	bool operator!=(const random_access_iterator<T> first,
					const random_access_iterator<T> second) {
		return first.getPtr() != second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const random_access_iterator<T_F> first,
					const random_access_iterator<T_S> second) {
		return first.getPtr() != second.getPtr();
	}

	template <class T>
	bool operator<(const random_access_iterator<T> first,
					const random_access_iterator<T> second)
	{
		return first.getPtr() < second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<(const random_access_iterator<T_F> first,
					const random_access_iterator<T_S> second)
	{
		return first.getPtr() < second.getPtr();
	}

	template <class T>
	bool operator>(const random_access_iterator<T> first,
					const random_access_iterator<T> second) {
		return first.getPtr() > second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>(const random_access_iterator<T_F> first,
					const random_access_iterator<T_S> second) {
		return first.getPtr() > second.getPtr();
	}

	template <class T>
	bool operator<=(const random_access_iterator<T> first,
					const random_access_iterator<T> second) {
		return first.getPtr() <= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<=(const random_access_iterator<T_F> first,
			   const random_access_iterator<T_S> second) {
		return first.getPtr() <= second.getPtr();
	}

	template <class T>
	bool operator>=(const random_access_iterator<T> first,
					const random_access_iterator<T> second) {
		return first.getPtr() >= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>=(const random_access_iterator<T_F> first,
					const random_access_iterator<T_S> second) {
		return first.getPtr() >= second.getPtr();
	}

	template <class T>
	long int operator-(const random_access_iterator<T> first,
							const random_access_iterator<T> second) {
		return first.getPtr() - second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	long int operator-(const random_access_iterator<T_F> first,
							const random_access_iterator<T_S> second)
	{
		return first.getPtr() - second.getPtr();
	}

	template<class T>
	random_access_iterator<T> operator+(std::size_t step, random_access_iterator<T> &iterator) {
		return random_access_iterator<T>(iterator + step);
	}

}
#endif //CONTAINERS_DIRECT_VECTOR_ITERATOR_HPP

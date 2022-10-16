//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP
# define CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

# include <iostream>
# include "direct_vector_iterator.hpp"

namespace ft {
	template<class T>
	class reverse_iterator : public ft::iterator_base<ft::random_access_iterator_tag, T> {
	private:
		random_access_iterator<T> _iter;
	public:
		reverse_iterator() : _iter(NULL) {}

		explicit reverse_iterator(T *x) : _iter(x) {}

		reverse_iterator(const reverse_iterator &other) : _iter(other._iter) {}

		reverse_iterator(const random_access_iterator<T> &other) :
			_iter(other.getPtr()) {}

		reverse_iterator &operator=(reverse_iterator const &other) {
			if (this == &other)
				return (*this);
			_iter = other._iter;
			return (*this);
		}

		operator reverse_iterator<const T>() const {
			return (reverse_iterator<const T>(this->_iter));
		}

		random_access_iterator<T> base() const {
			return _iter;
		}

		T &operator*() {
			random_access_iterator<T> ret(this->base());
			return *--ret;
		}

		T *operator->() {
			return &(operator*());
		}

		reverse_iterator &operator++() {
			--_iter;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}

		reverse_iterator &operator--() {
			++_iter;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp(_iter);
			operator--();
			return tmp;
		}

		reverse_iterator operator+(std::size_t step) const {
			return reverse_iterator(_iter - step);
		}

		reverse_iterator operator-(std::size_t step) const {
			return reverse_iterator(_iter + step);
		}

		long int operator-(const reverse_iterator &other) const {
			return (_iter + other._iter);
		}

		reverse_iterator operator+=(std::size_t step) {
			_iter -= step;
			return *this;
		}

		reverse_iterator operator-=(std::size_t step) {
			_iter += step;
			return *this;
		}

		T &operator[](std::size_t offset) {
			return *(_iter - 1 - offset);
		}

		T *getPtr() const {
			return (_iter - 1).getPtr();
		}

	};

	template <class T>
	bool operator==(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.getPtr() == second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.getPtr() == second.getPtr();
	}

	template <class T>
	bool operator!=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.getPtr() != second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.getPtr() != second.getPtr();
	}

	template <class T>
	bool operator<(const reverse_iterator<T> first,
				   const reverse_iterator<T> second)
	{
		return first.getPtr() > second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<(const reverse_iterator<T_F> first,
				   const reverse_iterator<T_S> second)
	{
		return first.getPtr() > second.getPtr();
	}

	template <class T>
	bool operator>(const reverse_iterator<T> first,
				   const reverse_iterator<T> second) {
		return first.getPtr() < second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>(const reverse_iterator<T_F> first,
				   const reverse_iterator<T_S> second) {
		return first.getPtr() < second.getPtr();
	}

	template <class T>
	bool operator<=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.getPtr() >= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.getPtr() >= second.getPtr();
	}

	template <class T>
	bool operator>=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.getPtr() <= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.getPtr() <= second.getPtr();
	}

	template <class T>
	long int operator-(const reverse_iterator<T> first,
					   const reverse_iterator<T> second) {
		return second.getPtr() - first.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	long int operator-(const reverse_iterator<T_F> first,
					   const reverse_iterator<T_S> second)
	{
		return second.getPtr() - first.getPtr();
	}

	template<class T>
	reverse_iterator<T> operator+(std::size_t step, reverse_iterator<T> &iterator) {
		return reverse_iterator<T>(iterator + step);
	}

}
#endif //CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP
# define CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

# include <iostream>
# include "direct_vector_iterator.hpp"

namespace ft {
	template<class Iter>
	class reverse_iterator : public Iter {
	private:
		Iter _iter;
	public:
		reverse_iterator() : _iter() {}

		explicit reverse_iterator(Iter x) : _iter(x) {}

		template < typename U >
		explicit reverse_iterator(const reverse_iterator<U> &other) : _iter(other.base()) {}

		template < typename U >
		reverse_iterator &operator=(reverse_iterator<U> const &other) {
			if (this == &other)
				return (*this);
			_iter = other.base();
			return (*this);
		}

		operator reverse_iterator<const Iter>() const {
			return (reverse_iterator<const Iter>(this->_iter));
		}

		Iter base() const {
			return _iter;
		}

		typename ft::iterator_traits<Iter>::reference operator*() {
			Iter ret(this->base());
			return *--ret;
		}

		typename ft::iterator_traits<Iter>::pointer operator->() {
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
			return (other._iter - _iter);
		}

		reverse_iterator operator+=(std::size_t step) {
			_iter -= step;
			return *this;
		}

		reverse_iterator operator-=(std::size_t step) {
			_iter += step;
			return *this;
		}

		typename ft::iterator_traits<Iter>::reference operator[](std::size_t offset) {
			return *(_iter - 1 - offset);
		}

		typename ft::iterator_traits<Iter>::pointer getPtr() const {
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

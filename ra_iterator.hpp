//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_RA_ITERATOR_HPP
# define CONTAINERS_RA_ITERATOR_HPP

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
#endif //CONTAINERS_RA_ITERATOR_HPP

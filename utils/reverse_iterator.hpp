//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_REVERSE_ITERATOR_HPP
# define CONTAINERS_REVERSE_ITERATOR_HPP

# include "iterators.hpp"

namespace ft {
	template<class Iter>
	class reverse_iterator : public ft::iterator_base<
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference >
	{
	private:
		Iter _iter;
	public:
		typedef Iter														iterator_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::reference			reference;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;

		reverse_iterator() : _iter() {}
		explicit reverse_iterator(iterator_type &other) : _iter(other) {}
		explicit reverse_iterator(iterator_type const &other) : _iter(other) {}
		reverse_iterator(reverse_iterator const &other) : _iter(other.base()) {}
		template <class U> reverse_iterator(const reverse_iterator<U>& other) : _iter(other.base()) {}
//		template <class U> reverse_iterator(const U& other) : _iter(other.base()) {}

//		template < typename U >
//		reverse_iterator &operator=(const reverse_iterator<U> &other) {
//			if (this == &other)
//				return (*this);
//			_iter = other.base();
//			return (*this);
//		}
//
//		reverse_iterator &operator=(reverse_iterator const &other) {
//			if (this == &other)
//				return (*this);
//			_iter = other.base();
//			return (*this);
//		}

//		operator reverse_iterator<iterator_type>() const {
//			return (reverse_iterator<iterator_type>(this->_iter));
//		}

		iterator_type base() const {
			return _iter;
		}

		reference operator*() const {
			iterator_type ret = _iter;
			return *--ret;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reverse_iterator &operator++() {
			--_iter;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
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

		reverse_iterator operator+(difference_type step) const {
			return reverse_iterator(_iter - step);
		}

		reverse_iterator operator-(difference_type step) const {
			return reverse_iterator(_iter + step);
		}

		long int operator-(const reverse_iterator &other) const {
			return (other._iter - _iter);
		}

		reverse_iterator operator+=(difference_type step) {
			_iter -= step;
			return *this;
		}

		reverse_iterator operator-=(difference_type step) {
			_iter += step;
			return *this;
		}

		reference operator[](difference_type offset) {
			return *(_iter - 1 - offset);
		}
	};

	template <class T>
	bool operator==(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.base() == second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.base() == second.base();
	}

	template <class T>
	bool operator!=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.base() != second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.base() != second.base();
	}

	template <class T>
	bool operator<(const reverse_iterator<T> first,
				   const reverse_iterator<T> second)
	{
		return first.base() > second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<(const reverse_iterator<T_F> first,
				   const reverse_iterator<T_S> second)
	{
		return first.base() > second.base();
	}

	template <class T>
	bool operator>(const reverse_iterator<T> first,
				   const reverse_iterator<T> second) {
		return first.base() < second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>(const reverse_iterator<T_F> first,
				   const reverse_iterator<T_S> second) {
		return first.base() < second.base();
	}

	template <class T>
	bool operator<=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.base() >= second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.base() >= second.base();
	}

	template <class T>
	bool operator>=(const reverse_iterator<T> first,
					const reverse_iterator<T> second) {
		return first.base() <= second.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>=(const reverse_iterator<T_F> first,
					const reverse_iterator<T_S> second) {
		return first.base() <= second.base();
	}

	template <class T>
	long int operator-(const reverse_iterator<T> first,
					   const reverse_iterator<T> second) {
		return second.base() - first.base();
	}

	// for non-const and const
	template<class T_F, class T_S>
	long int operator-(const reverse_iterator<T_F> first,
					   const reverse_iterator<T_S> second)
	{
		return second.base() - first.base();
	}

	template<class T>
	reverse_iterator<T> operator+(std::size_t step, reverse_iterator<T> &iterator) {
		return reverse_iterator<T>(iterator + step);
	}

}
#endif //CONTAINERS_REVERSE_VECTOR_ITERATOR_HPP

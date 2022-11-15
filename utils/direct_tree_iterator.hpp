//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_DIRECT_TREE_ITERATOR_HPP
# define CONTAINERS_DIRECT_TREE_ITERATOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "sfinae.hpp"
# include "node.hpp"

namespace ft {
	template<class T>
	class tree_iterator : public iterator_base<bidirectional_iterator_tag, T> {
	private:
		typedef iterator_base<std::bidirectional_iterator_tag, typename T::value_type>	_iterator;
	public:
		typedef tree_iterator							iterator_type;
		typedef typename _iterator::value_type			value_type;
		typedef typename _iterator::difference_type		difference_type;
		typedef typename _iterator::reference			reference;
		typedef typename _iterator::pointer				pointer;
		typedef typename _iterator::iterator_category	iterator_category;
		typedef T										node_type;

	private:
		node_type *_current;

	public:
		explicit tree_iterator(node_type *node = NULL) : _current(node) {}
		tree_iterator(const tree_iterator &other) : _current(other._current) {}

		tree_iterator &operator=(tree_iterator const &other) {
			if (this == &other)
				return (*this);
			_current = other._current;
			return (*this);
		}

		// CAST TO CONST
//		operator tree_iterator<const T>() const {
//			return (tree_iterator<const T>(this->_current));
//		}

		reference operator*() {
			return _current->_value;
		}
		reference operator*() const{
			return _current->_value;
		}
		pointer operator->() const {
			return &(operator*());
		}
		pointer operator->() {
			return &(operator*());
		}

		tree_iterator &operator++() {
			_current = _current->getSuccessor();
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator tmp(*this);
			operator++();
			return tmp;
		}

		tree_iterator &operator--() {
			_current = _current->getPredecessor();
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator tmp(*this);
			operator--();
			return tmp;
		}

		bool operator==(const tree_iterator &other) const {
			return _current == other._current;
		}

		bool operator!=(const tree_iterator &other) const {
			return !(operator==(other));
		}

		node_type *getCurrent() const {
			return _current;
		}
	};

	template<class const_T>
	class tree_iterator_const : public iterator_base<bidirectional_iterator_tag,
								typename const_T::value_type> {
	private:
		typedef iterator_base<std::bidirectional_iterator_tag, typename const_T::value_type const>	_const_iterator;
	public:
		typedef tree_iterator_const								iterator_type;
		typedef typename _const_iterator::value_type			value_type;
		typedef typename _const_iterator::difference_type		difference_type;
		typedef typename _const_iterator::reference				reference;
		typedef typename _const_iterator::pointer				pointer;
		typedef typename _const_iterator::iterator_category		iterator_category;
		typedef const_T											node_type;

	private:
		node_type const *_current;

	public:
		explicit tree_iterator_const(node_type const *node = NULL) : _current(node) {}
		tree_iterator_const(const tree_iterator_const &other) : _current(other._current) {}
		tree_iterator_const(const tree_iterator<node_type> &other) : _current(other._current) {}

		tree_iterator_const &operator=(const tree_iterator_const  &other) {
			if (this == &other)
				return (*this);
			_current = other._current;
			return (*this);
		}

		reference operator*() const {
			return _current->_value;
		}
		pointer operator->() const {
			return &(operator*());
		}

		tree_iterator_const &operator++() {
			_current = _current->getSuccessor();
			return *this;
		}

		tree_iterator_const operator++(int) {
			tree_iterator_const tmp(*this);
			operator++();
			return tmp;
		}

		tree_iterator_const &operator--() {
			_current = _current->getPredecessor();
			return *this;
		}

		tree_iterator_const operator--(int) {
			tree_iterator_const tmp(*this);
			operator--();
			return tmp;
		}

		bool operator==(const tree_iterator_const &other) const {
			return _current == other._current;
		}

		bool operator!=(const tree_iterator_const &other) const {
			return !(operator==(other));
		}

		node_type *getCurrent() const {
			return _current;
		}
	};

//	template <class T>
//	bool operator==(const tree_iterator<T> first,
//					const tree_iterator<T> second) {
//		return first.getCurrent() == second.getCurrent();
//	}
//
//	// for non-const and const
//	template<class T_F, class T_S>
//	bool operator==(const tree_iterator<T_F> first,
//					const tree_iterator<T_S> second) {
//		return first.getCurrent() == second.getCurrent();
//	}
//
//	template <class T>
//	bool operator!=(const tree_iterator<T> first,
//					const tree_iterator<T> second) {
//		return first.getCurrent() != second.getCurrent();
//	}
//
//	// for non-const and const
//	template<class T_F, class T_S>
//	bool operator!=(const tree_iterator<T_F> first,
//					const tree_iterator<T_S> second) {
//		return first.getCurrent() != second.getCurrent();
//	}
}
#endif //CONTAINERS_DIRECT_TREE_ITERATOR_HPP

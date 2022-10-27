//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_DIRECT_TREE_ITERATOR_HPP
# define CONTAINERS_DIRECT_TREE_ITERATOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "sfinae.hpp"

namespace ft {
	template<class T, class Node>
	class tree_iterator : public iterator_base<bidirectional_iterator_tag, T> {
	private:
		Node *_node;
		Node *_root;
	public:
		explicit tree_iterator(Node *node = NULL, Node *root = NULL)
			: _node(node), _root(root) {}

		tree_iterator(const tree_iterator &other)
			: _node(other._node), _root(other._root) {}

		tree_iterator &operator=(tree_iterator const &other) {
			if (this == &other)
				return (*this);
			_node = other._node;
			_root = other._root;
			return (*this);
		}

		operator tree_iterator<const T, const Node>() const {
			return (tree_iterator<const T, const Node>(this->_node, this->_root));
		}

		Node &operator*() {
			return *_node;
		}

		Node *operator->() {
			return _node;
		}

		tree_iterator &operator++() {
			++_node;
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator tmp(*this);
			operator++();
			return tmp;
		}

		tree_iterator &operator--() {
			--_pointer;
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator tmp(*this);
			operator--();
			return tmp;
		}

		tree_iterator operator+(std::size_t step) const {
			return tree_iterator(_pointer + step);
		}

		tree_iterator operator-(std::size_t step) const {
			return tree_iterator(_pointer - step);
		}

		long int operator-(const tree_iterator &other) const {
			return (_pointer - other._pointer);
		}

		tree_iterator operator+=(std::size_t step) {
			_pointer += step;
			return *this;
		}

		tree_iterator operator-=(std::size_t step) {
			_pointer -= step;
			return *this;
		}

		T &operator[](std::size_t offset) {
			return *(_pointer + offset);
		}

		T *getPtr() const {
			return _pointer;
		}
	};

	template <class T>
	bool operator==(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getPtr() == second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getPtr() == second.getPtr();
	}

	template <class T>
	bool operator!=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getPtr() != second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getPtr() != second.getPtr();
	}

	template <class T>
	bool operator<(const tree_iterator<T> first,
					const tree_iterator<T> second)
	{
		return first.getPtr() < second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second)
	{
		return first.getPtr() < second.getPtr();
	}

	template <class T>
	bool operator>(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getPtr() > second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getPtr() > second.getPtr();
	}

	template <class T>
	bool operator<=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getPtr() <= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<=(const tree_iterator<T_F> first,
			   const tree_iterator<T_S> second) {
		return first.getPtr() <= second.getPtr();
	}

	template <class T>
	bool operator>=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getPtr() >= second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>=(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getPtr() >= second.getPtr();
	}

	template <class T>
	long int operator-(const tree_iterator<T> first,
							const tree_iterator<T> second) {
		return first.getPtr() - second.getPtr();
	}

	// for non-const and const
	template<class T_F, class T_S>
	long int operator-(const tree_iterator<T_F> first,
							const tree_iterator<T_S> second)
	{
		return first.getPtr() - second.getPtr();
	}

	template<class T>
	tree_iterator<T> operator+(std::size_t step, tree_iterator<T> &iterator) {
		return tree_iterator<T>(iterator + step);
	}

}
#endif //CONTAINERS_DIRECT_TREE_ITERATOR_HPP

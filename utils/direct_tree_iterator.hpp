//
// Created by grvelva on 10/15/22.
//

#ifndef CONTAINERS_DIRECT_TREE_ITERATOR_HPP
# define CONTAINERS_DIRECT_TREE_ITERATOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "sfinae.hpp"

namespace ft {
	template<class T, class Node = node<T> >
	class tree_iterator : public iterator_base<bidirectional_iterator_tag, T> {
	private:
		Node *_node;
		Node *_root;
		Node *_last;
	public:
		explicit tree_iterator(Node *node = NULL, Node *root = NULL, Node *last = NULL)
			: _node(node), _root(root), _last(last) {}

		tree_iterator(const tree_iterator &other)
			: _node(other._node), _root(other._root), _last(other._last) {}

		tree_iterator &operator=(tree_iterator const &other) {
			if (this == &other)
				return (*this);
			_node = other._node;
			_root = other._root;
			_last = other._last;
			return (*this);
		}

		operator tree_iterator<const T, const node<T> >() const {
			return (tree_iterator<const T, const Node>(this->_node, this->_root, this->_last));
		}

		Node &operator*() {
			return *_node;
		}

		Node *operator->() {
			return _node;
		}

		tree_iterator &operator++() {
			if (_node != _last) {
				if (_node->_right_kid) {
					//node has right kid
					_node = _node->_right_kid;
					while (_node->_left_kid) {
						_node = _node->_left_kid;
					}
				} else if (!_node->_parent) {
					_node = _last;
				} else if (_node->_parent->_left_kid == _node) {
					// node is left_kid
					_node = _node->_parent;
				} else {
					// node is right kid
					// move while node is right kid and has parent
					while (_node->_parent && _node->_parent->_right_kid == _node) {
						_node = _node->_parent;
					}
					if (_node->_parent) {
						_node = _node->_parent;
					} else {
						_node = _last;
					}
				}
			}
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator tmp(*this);
			operator++();
			return tmp;
		}

		tree_iterator &operator--() {
			if (_node != _last) {
				if (_node->_left_kid) {
					//node has left kid
					_node = _node->_left_kid;
					while (_node->_right_kid) {
						_node = _node->_right_kid;
					}
				} else if (!_node->_parent) {
					_node = _last;
				} else if (_node->_parent->_right_kid == _node) {
					// node is right kid
					_node = _node->_parent;
				} else {
					// node is left kid
					// move while node is left kid and has parent
					while (_node->_parent && _node->_parent->_left_kid == _node) {
						_node = _node->_parent;
					}
					if (_node->_parent) {
						_node = _node->_parent;
					} else {
						_node = _last;
					}
				}
			} else {
				_node = _root;
				while (_node->_right_kid)
					_node = _node->_right_kid;
			}
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator tmp(*this);
			operator--();
			return tmp;
		}

//		tree_iterator operator+(std::size_t step) const {
//			return tree_iterator(_pointer + step);
//		}

//		tree_iterator operator-(std::size_t step) const {
//			return tree_iterator(_pointer - step);
//		}

//		long int operator-(const tree_iterator &other) const {
//			return (_pointer - other._pointer);
//		}

//		tree_iterator operator+=(std::size_t step) {
//			_pointer += step;
//			return *this;
//		}

//		tree_iterator operator-=(std::size_t step) {
//			_pointer -= step;
//			return *this;
//		}

//		T &operator[](std::size_t offset) {
//			return *(_pointer + offset);
//		}

		Node *getNode() const {
			return _node;
		}
	};

	template <class T>
	bool operator==(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getNode() == second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getNode() == second.getNode();
	}

	template <class T>
	bool operator!=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getNode() != second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getNode() != second.getNode();
	}

	template <class T>
	bool operator<(const tree_iterator<T> first,
					const tree_iterator<T> second)
	{
		return first.getNode() < second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second)
	{
		return first.getNode() < second.getNode();
	}

	template <class T>
	bool operator>(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getNode() > second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getNode() > second.getNode();
	}

	template <class T>
	bool operator<=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getNode() <= second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator<=(const tree_iterator<T_F> first,
			   const tree_iterator<T_S> second) {
		return first.getNode() <= second.getNode();
	}

	template <class T>
	bool operator>=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getNode() >= second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator>=(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getNode() >= second.getNode();
	}

	template <class T>
	long int operator-(const tree_iterator<T> first,
							const tree_iterator<T> second) {
		return first.getNode() - second.getNode();
	}

	// for non-const and const
	template<class T_F, class T_S>
	long int operator-(const tree_iterator<T_F> first,
							const tree_iterator<T_S> second)
	{
		return first.getNode() - second.getNode();
	}

	template<class T>
	tree_iterator<T> operator+(std::size_t step, tree_iterator<T> &iterator) {
		return tree_iterator<T>(iterator + step);
	}

}
#endif //CONTAINERS_DIRECT_TREE_ITERATOR_HPP

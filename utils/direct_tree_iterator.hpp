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
	template<class T, class Node = node<T> >
	class tree_iterator : public iterator_base<bidirectional_iterator_tag, T> {
	private:
		Node *_current;
		Node *_root;
		Node *_last;
	public:
		explicit tree_iterator(Node *node = NULL, Node *root = NULL, Node *last = NULL)
			: _current(node), _root(root), _last(last) {}

		tree_iterator(const tree_iterator &other)
			: _current(other._current), _root(other._root), _last(other._last) {}

		tree_iterator &operator=(tree_iterator const &other) {
			if (this == &other)
				return (*this);
			_current = other._current;
			_root = other._root;
			_last = other._last;
			return (*this);
		}

		operator tree_iterator<const T, node<T> >() const {
			return (tree_iterator<const T, Node>(this->_current, this->_root, this->_last));
		}

		Node *getCurrent() const {
			return _current;
		}

		Node *getLast() const {
			return _last;
		}

		Node *getRoot() const {
			return _root;
		}

		Node &operator*() const {
			return *_current;
		}

		Node *operator->() const {
			return _current->_value;
		}

		tree_iterator &operator++() {
			if (_current != _last) {
				if (_current->_right_kid) {
					//node has right kid
					_current = _current->_right_kid;
					while (_current->_left_kid) {
						_current = _current->_left_kid;
					}
				} else if (!_current->_parent) {
					_current = _last;
				} else if (_current->_parent->_left_kid == _current) {
					// node is left_kid
					_current = _current->_parent;
				} else {
					// node is right kid
					// move while node is right kid and has parent
					while (_current->_parent && _current->_parent->_right_kid == _current) {
						_current = _current->_parent;
					}
					if (_current->_parent) {
						_current = _current->_parent;
					} else {
						_current = _last;
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
			if (_current != _last) {
				if (_current->_left_kid) {
					//node has left kid
					_current = _current->_left_kid;
					while (_current->_right_kid) {
						_current = _current->_right_kid;
					}
				} else if (!_current->_parent) {
					_current = _last;
				} else if (_current->_parent->_right_kid == _current) {
					// node is right kid
					_current = _current->_parent;
				} else {
					// node is left kid
					// move while node is left kid and has parent
					while (_current->_parent && _current->_parent->_left_kid == _current) {
						_current = _current->_parent;
					}
					if (_current->_parent) {
						_current = _current->_parent;
					} else {
						_current = _last;
					}
				}
			} else {
				_current = _root;
				while (_current->_right_kid)
					_current = _current->_right_kid;
			}
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator tmp(*this);
			operator--();
			return tmp;
		}

	};

	template <class T>
	bool operator==(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getCurrent() == second.getCurrent();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator==(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getCurrent() == second.getCurrent();
	}

	template <class T>
	bool operator!=(const tree_iterator<T> first,
					const tree_iterator<T> second) {
		return first.getCurrent() != second.getCurrent();
	}

	// for non-const and const
	template<class T_F, class T_S>
	bool operator!=(const tree_iterator<T_F> first,
					const tree_iterator<T_S> second) {
		return first.getCurrent() != second.getCurrent();
	}
}
#endif //CONTAINERS_DIRECT_TREE_ITERATOR_HPP

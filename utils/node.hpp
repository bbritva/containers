//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_NODE_HPP
#define CONTAINERS_NODE_HPP

#include <cstring>
#include "pair.hpp"

namespace ft {
	typedef enum e_color {
		RED,
		black
	} t_color;

	template <class T>
	class node
	{
	public:
		typedef T	value_type;

	public:
		value_type	_value;
		t_color		_color;
		node		*_parent;
		node		*_left_kid;
		node		*_right_kid;

		explicit node(const T &value = T(), t_color color = RED, node<T> *parent = NULL
				, node<T> *left_kid = NULL, node<T> *right_kid = NULL) :
			_value(value),
			_color(color),
			_parent(parent),
			_left_kid(left_kid),
			_right_kid(right_kid) {
		};

		explicit node(node<T> *leaf, const T &value = T()) :
			_value(value),
			_color(RED),
			_parent(leaf),
			_left_kid(leaf),
			_right_kid(leaf) {};

		node(const node &other) :
			_value(other._value),
			_color(other._color),
			_parent(other._parent),
			_left_kid(other._left_kid),
			_right_kid(other._right_kid)
			 {};
		~node() {};

		node& operator=(node const& other) {
			if (this == &other)
				return *this;
			_value = other._value;
			_color = other._color;
			_parent = other._parent;
			_left_kid = other._left_kid;
			_right_kid = other._right_kid;
			return *this;
		};

		node const *getSuccessor() const {
			node const *successor = this;
			if (isLeaf())
				return getMin(_parent);
			if (!_right_kid->isLeaf()) {
				return getMin(_right_kid);
			} else {
				while (!successor->_parent->isLeaf()
					   && successor->_parent->_left_kid != successor) {
					successor = successor->_parent;
				}
				return successor->_parent;
			}
		}

		node *getSuccessor() {
			node *successor = this;
			if (isLeaf())
				return getMin(_parent);
			if (!_right_kid->isLeaf()) {
				return getMin(_right_kid);
			} else {
				while (!successor->_parent->isLeaf()
					   && successor->_parent->_left_kid != successor) {
					successor = successor->_parent;
				}
				return successor->_parent;
			}
		}

		node *getPredecessor() {
			node *successor = this;
			if (isLeaf())
				return getMax(_parent);
			if (!_left_kid->isLeaf()) {
				return getMax(_left_kid);
			} else {
				while (!successor->_parent->isLeaf()
					   && successor->_parent->_right_kid != successor) {
					successor = successor->_parent;
				}
				return successor->_parent;
			}
		}

		node const *getPredecessor() const {
			node const *successor = this;
			if (isLeaf())
				return getMax(_parent);
			if (!_left_kid->isLeaf()) {
				return getMax(_left_kid);
			} else {
				while (!successor->_parent->isLeaf()
					   && successor->_parent->_right_kid != successor) {
					successor = successor->_parent;
				}
				return successor->_parent;
			}
		}

		static node *getMin(node *_root) {
			node *min = _root;
			while (!min->_left_kid->isLeaf())
				min = min->_left_kid;
			return min;
		}

		static node *getMax(node *_root) {
			node *max = _root;
			while (!max->_right_kid->isLeaf())
				max = max->_right_kid;
			return max;
		}

		bool operator==(node const& other) {
			return _value == other._value;
		};

		bool isLeaf() const {
			return (this == _right_kid);
		}

	};

	template <class T>
	bool isBlack(node<T> *node) {
		return !node || node->color == black;
	}

	template <class T>
	bool isRed(node<T> *node) {
		return !isBlack(node);
	}

	template <class T>
	int swap_color(node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr)
			return 1;
		(*node_ptr)->_color = ((*node_ptr)->_parent) ? RED : black;
		(*node_ptr)->_right_kid->color = black;
		(*node_ptr)->_left_kid->color = black;
		return 0;
	}

	template <class T>
	int right_turn(node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr || !(*node_ptr)->_left_kid)
			return 1;
		node<T> *_node = *node_ptr;
		node<T> *parent = _node->_parent;
		node<T> *new_node = _node->_left_kid;
		new_node->_color = _node->_color;
		_node->_color = RED;
		_node->_left_kid = new_node->_right_kid;
		if (_node->_left_kid)
			_node->_left_kid->_parent = _node;
		_node->_parent = new_node;
		new_node->_right_kid = _node;
		new_node->_parent = parent;
		*node_ptr = new_node;
		return 0;

	}

	template <class T>
	int leftTurn(node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr || !(*node_ptr)->_right_kid)
			return 1;
		node<T> *_node = *node_ptr;
		node<T> *parent = _node->_parent;
		node<T> *new_node = _node->_right_kid;
		new_node->_color = _node->_color;
		_node->_color = RED;
		_node->_right_kid = new_node->_left_kid;
		if (_node->_right_kid)
			_node->_right_kid->_parent = _node;
		_node->parent = new_node;
		new_node->left_kid = _node;
		new_node->parent = parent;
		*node_ptr = new_node;
	}
}

#endif //CONTAINERS_NODE_HPP

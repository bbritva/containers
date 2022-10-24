//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_NODE_HPP
#define CONTAINERS_NODE_HPP

#include "pair.hpp"

namespace ft {
	typedef enum e_color {
		RED,
		black
	} t_color;

	template <class T>
	class Node
	{
	public:
		T		_value;
		t_color	_color;
		Node	*_parent;
		Node	*_left_kid;
		Node	*_right_kid;


		explicit Node(T &value = T(), t_color color = RED, T *parent = NULL, T *left_kid = NULL, T *right_kid = NULL)
			: _parent(parent), _left_kid(left_kid), _right_kid(right_kid), _color(color), _value(value) {};

		Node(Node &other)
			: _parent(other._parent), _left_kid(other._left_kid), _right_kid(other._right_kid),
			_color(other._color), _value(other._value) {};
		~Node() {};

		Node& operator=(Node const& other) {
			if (this == &other)
				return *this;
			_value = other._value;
			_color = other._color;
			_parent = other._parent;
			_left_kid = other._left_kid;
			_right_kid = other._right_kid;
			return *this;
		};

		bool operator==(Node const& other) {
			return _value == other._value;
		};
	};

	template <class T>
	bool isBlack(Node<T> *node) {
		return !node || node->color == black;
	}

	template <class T>
	bool isRed(Node<T> *node) {
		return !isBlack(node);
	}

	template <class T>
	int swap_color(Node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr)
			return 1;
		(*node_ptr)->_color = ((*node_ptr)->_parent) ? RED : black;
		(*node_ptr)->_right_kid->color = black;
		(*node_ptr)->_left_kid->color = black;
		return 0;
	}

	template <class T>
	int right_turn(Node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr || !(*node_ptr)->_left_kid)
			return 1;
		Node<T> *node = *node_ptr;
		Node<T> *parent = node->_parent;
		Node<T> *new_node = node->_left_kid;
		new_node->_color = node->_color;
		node->_color = RED;
		node->_left_kid = new_node->_right_kid;
		if (node->_left_kid)
			node->_left_kid->_parent = node;
		node->_parent = new_node;
		new_node->_right_kid = node;
		new_node->_parent = parent;
		*node_ptr = new_node;
		return 0;

	}

	template <class T>
	int leftTurn(Node<T> **node_ptr) {
		if (!node_ptr || !*node_ptr || !(*node_ptr)->_right_kid)
			return 1;
		Node<T> *node = *node_ptr;
		Node<T> *parent = node->_parent;
		Node<T> *new_node = node->_right_kid;
		new_node->_color = node->_color;
		node->_color = RED;
		node->_right_kid = new_node->_left_kid;
		if (node->_right_kid)
			node->_right_kid->_parent = node;
		node->parent = new_node;
		new_node->left_kid = node;
		new_node->parent = parent;
		*node_ptr = new_node;
	}
}

#endif //CONTAINERS_NODE_HPP

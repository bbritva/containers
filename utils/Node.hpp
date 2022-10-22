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
	private:
		T		_value;
		t_color	_color;
		Node	*_parent;
		Node	*_left_kid;
		Node	*_right_kid;

	public:
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
}

#endif //CONTAINERS_NODE_HPP

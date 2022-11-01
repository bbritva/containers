//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include "node.hpp"

namespace ft {
	template <class T, class Compare>
	class rb_tree
	{
	private:
		node<T>		*_root;
		node<T>		*_last;
		Compare		_comparator;

	public:
		explicit rb_tree(Compare const &comparator)
				: _comparator(comparator) {
			_root = NULL;
			_last = new node<T>();
		};

		~rb_tree() {};

		rb_tree& operator=(const rb_tree& other) {
			if (this == &other)
				return *this;
			_comparator = other._comparator;
			_root = other._root;
			_last = other._last;
			return *this;
		};

		void insert (node<T>* new_node){
			insert_node(new_node, &_root, NULL);
		};

		bool empty() {
			return !_root;
		}

		void clear() {
			eraseNode(_root);
			_root = NULL;
		};

		bool operator==(rb_tree const& other) {
			return _root == other._root;
		};

		std::size_t size() const {
			return size(_root);
		}

		node<T> *getRoot() {
			return _root;
		}
		node<T> *getFirst() {
			node<T> *first = _root;
			while (first->_left_kid)
				first = first->_left_kid;
			return first;
		}
		node<T> *getLast() {
			return _last;
		}


	private:

		std::size_t size(node<T> *node) const {
			if (!node)
				return 0;
			return size(node->_right_kid) + size(node->_left_kid) + 1;
		}

		void eraseNode(node<T> *node) {
			if (!node)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
		};

		void insert_node(node<T> *new_node, node<T> **place, node<T> *new_parent) {
			if (!place || !new_node)
				return;
			if (!*place) {
				*place = new_node;
				(*place)->_parent = new_parent;
				if (!new_parent)
					(*place)->_color = black;
				return;
			} else if (_comparator( new_node->_value, (*place)->_value)) {
				insert_node(new_node, &((*place)->_left_kid), *place);
			} else if (_comparator( (*place)->_value, new_node->_value)) {
				insert_node(new_node, &((*place)->_right_kid), *place);
			} else {
				std::cout << "Key exists\n";
			}
		};
	};


}

#endif //CONTAINERS_RED_BLACK_TREE_HPP


//ft::rb_tree
//<
//	ft::pair
//	<
//		int, std::__cxx11::basic_string<char>
//	>,
//	std::less<int>,
//	std::allocator
//	<
//		ft::node
//		<
//			ft::pair<int, std::__cxx11::basic_string<char> >
//		>
//	>
//>
//::rb_tree
//(
//	ft::rb_tree
//	<
//		ft::pair
//		<
//			int, std::__cxx11::basic_string<char>
//		>,
//		std::less<int>,
//		std::allocator
//		<
//			ft::pair<int, std::__cxx11::basic_string<char> >
//		>
//	>
//)
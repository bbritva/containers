//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include "node.hpp"

namespace ft {
	template <class T,
			class Compare,
			class Allocator = std::allocator<node<T> > >
	class rb_tree
	{
	private:
		node<T>		*_root;
		Compare		_comparator;
		Allocator	_alloc;

	public:
		explicit rb_tree(const std::allocator<T>& allocator = std::allocator<T>(),
		        const Compare& comparator = Compare())
				: _root(NULL), _alloc(allocator), _comparator(comparator){};

		rb_tree(const rb_tree &other) : _root(other._root), _alloc(other._alloc),
			_comparator(other._comparator) {};
		~rb_tree() {};

		rb_tree& operator=(const rb_tree& other) {
			if (this == &other)
				return *this;
			_alloc = other._alloc;
			_comparator = other._comparator;
			_root = other._root;
			return *this;
		};

		void insert (const node<T>& new_node){
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

	private:
		void eraseNode(node<T> *node) {
			if (!node)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
			_alloc.destroy(node);
			_alloc.deallocate(node, sizeof(::ft::node<T>));
		};

		void insert_node(const node<T>& new_node, node<T> **place, node<T> *new_parent) {
			if (!place || !new_node)
				return;
			if (!*place) {
				*place = new_node;
				(*place)->parent = new_parent;
				if (!new_parent)
					(*place)->color = black;
				return;
			} else if (new_node->data > (*place)->data) {
				insert_node(&((*place)->_right_kid), new_node, *place);
			} else {
				insert_node(&((*place)->_left_kid), new_node, *place);
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
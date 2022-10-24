//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include "Node.hpp"

namespace ft {
	template <class T,
			class Compare,
			class Allocator = std::allocator<Node<T> > >
	class rb_tree
	{
	private:
		Node<T>		*_root;
		Compare		_compare;
		Allocator	_alloc;

	public:
		explicit rb_tree(const std::allocator<T>& allocator = std::allocator<T>())
				: _root(NULL), _alloc(allocator) {};

		rb_tree(rb_tree &other) : _root(other._root), _alloc(other._alloc) {};
		~rb_tree() {};

		rb_tree& operator=(rb_tree const& other) {
			if (this == &other)
				return *this;
			_alloc = other._alloc;
			_root = other._root;
			return *this;
		};

		void insert (const Node<T>& new_node){
			_tree.insert(value);
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
		void eraseNode(Node<T> *node) {
			if (!node)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
			_alloc.destroy(node);
			_alloc.deallocate(node, sizeof(Node<T>));
		};
	};


}

#endif //CONTAINERS_RED_BLACK_TREE_HPP

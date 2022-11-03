//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include "node.hpp"

namespace ft {
	template <class T, class Compare, class Allocator>
	class rb_tree
	{
	private:
		node<T>		*_root;
		node<T>		*_last;
		Compare		_comparator;

	public:
		explicit rb_tree(Compare const &comparator, node<T> *last)
				: _comparator(comparator) {
			_root = NULL;
			_last = last;
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

		void clear(Allocator &allocator) {
			eraseNode(_root, allocator);
			_root = NULL;
		};

		bool operator==(rb_tree const& other) {
			return _root == other._root;
		};

		std::size_t size() const {
			return size(_root);
		};

		node<T> *getRoot() {
			return _root;
		};
		node<T> *getFirst() {
			node<T> *first = _root;
			while (first->_left_kid)
				first = first->_left_kid;
			return first;
		};

		node<T> *getLast() {
			return _last;
		};

		node<T> *findByKey(const T& key, node<T> *node) {
			if (!node)
				return NULL;
			if (_comparator(key, node->_value))
				return findByKey(key, node->_left_kid);
			if (_comparator(node->_value, key))
				return find(key, node->_right_kid);
			return node;
		};

		node<T> *delete_node(const T& key) {
			node<T> *curr_node = findByKey(key, _root);
			node<T> *ret;
			if (curr_node) {
				ret = curr_node;
				if (curr_node->_right_kid) {
					if (curr_node->_left_kid) {
						replaceNode(*curr_node, getSuccessor(curr_node));
					} else {
						replaceNode(*curr_node, curr_node->_right_kid);
					}
				} else {
					if (curr_node->_left_kid) {
						replaceNode(*curr_node, curr_node->_right_kid);
					} else {
						replaceNode(*curr_node, NULL);
					}
				}
			}
			return ret;
		};


	private:

		std::size_t size(node<T> *node) const {
			if (!node)
				return 0;
			return size(node->_right_kid) + size(node->_left_kid) + 1;
		}

		void eraseNode(node<T> *node, Allocator &allocator) {
			if (!node)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
			allocator.destroy(node);
			allocator.deallocate(node, 1);
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

		void replaceNode(node<T> **curr_node, node<T> *new_node) {
			node<T> *tmp = *curr_node;
			node<T> *left_kid = tmp->_left_kid;
			node<T> *right_kid = tmp->_right_kid;
			new_node->_color = tmp->_color;
			new_node->_parent = tmp->_parent;
			new_node->_left_kid = tmp->_left_kid;
			new_node->_right_kid = tmp->_right_kid;
			*curr_node = new_node;
			if (right_kid)
				insert_node(right_kid, &_root, NULL);
			if (left_kid)
				insert_node(left_kid, &_root, NULL);
		};

		node<T> *getSuccessor(node<T> *curr_node) {
			if (!curr_node || !curr_node->_right_kid)
				return NULL;
			curr_node = curr_node->_right_kid;
			while (curr_node->_left_kid)
				curr_node = curr_node->_left_kid;
			return curr_node;
		};

	};


}

#endif //CONTAINERS_RED_BLACK_TREE_HPP

//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include "node.hpp"
#include "direct_tree_iterator.hpp"

namespace ft {
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<node<T> > >
	class rb_tree
	{
	private:
		typedef typename Allocator::template rebind<node<T> >::other	node_allocator;
	public:
		typedef T							value_type;
		typedef Allocator					allocator_type;
		typedef Compare						key_compare;
		typedef node<T>						node_type;
		typedef tree_iterator<node_type>	iterator;
//		typedef map_citerator<node_type>    const_iterator;

	private:
		allocator_type	_allocator;
		node_allocator	_node_allocator;
		node_type		*_root;
		node_type		*_last;
		key_compare		_comparator;

	public:
		explicit rb_tree(const allocator_type &alloc = allocator_type(), const key_compare &comparator = key_compare())
				: _allocator(alloc), _comparator(comparator) {
			_root = NULL;
			_last = _node_allocator(1);
			_node_allocator.construct(_last, node_type(T(), black, _last, _last, _last));
		};

		~rb_tree() {
			clear();
		};

		rb_tree(const rb_tree& other) : _allocator(other._allocator), _node_allocator(other._node_allocator),
										_comparator(other._comparator) {
			iterator it = other.getMin();
			_last = _node_allocator(1);
			_node_allocator.construct(_last, node_type(T(), black, _last, _last, _last));
			_root = NULL;
			while (it != other._last) {
				insertNode(*it);
				++it;
			}
		}

		rb_tree& operator=(const rb_tree& other) {
			if (this == &other)
				return *this;
			clear();
			this = rb_tree(other);
			return *this;
		};

		void swap(rb_tree& other)
		{
			rb_tree tmp(other);
			other = *this;
			*this = tmp;
//			node_type *tmp = _last;
//			_last = other._last;
//			other._last = tmp;
//			tmp = _root;
//			_root = other._root;
//			other._root = tmp;
		}

		void insert (node_type *new_node, node_type *pos) {
			pos = (pos) ? pos : _root;
			insert_node(new_node, &pos, NULL);
		};

		bool empty() {
			return !_root;
		}

		void clear() {
			eraseNode(_root);
			_root = NULL;
			_node_allocator.destroy(_last);
			_node_allocator.deallocate(_last, 1);
		};

		bool operator==(rb_tree const& other) {
			return _root == other._root;
		};

		std::size_t size() const {
			return size(_root);
		};

		std::size_t maxSize() const {
			return _node_allocator.max_size();
		};

		node_type *getRoot() { return _root ? _root : _last; };
		node_type *getMin() { return _root->TreeMin(); }
		node_type *getMax() { return _root->TreeMax(); }
		node_type *getLast() { return _last; };

		node_type *findByKey(const T& key, node_type *node) {
			if (!node)
				return NULL;
			if (_comparator(key, node->_value))
				return findByKey(key, node->_left_kid);
			if (_comparator(node->_value, key))
				return findByKey(key, node->_right_kid);
			return node;
		};

		node_type *delete_node(const T& key) {
			node_type *curr_node = findByKey(key, _root);
			node_type *ret;
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

		void rotateLeft(node_type *point) {
			node_type *tmp = point->_right_kid;
			point->_right_kid = tmp->_left_kid;
			if (tmp->_left_kid != _last)
				tmp->_left_kid->_parent = point;
			tmp->_parent = point->_parent;
			if (point->_parent == _last)
				_root = tmp;
			else if (point == point->_parent->_left_kid)
				point->_parent->_left_kid = tmp;
			else
				point->_parent->_right_kid = tmp;
			tmp->_left_kid = point;
			point->_parent = tmp;
		}

		void rotateRight(node_type *point )
		{
			node_type* tmp = point->_left_kid;
			point->_left_kid = tmp->_right_kid;
			if (tmp->_right_kid != _last)
				tmp->_right_kid->_parent = point;
			tmp->_parent = point->_parent;
			if (point->_parent == _last)
				_root = tmp;
			else if (point == point->_parent->_right_kid)
				point->_parent->_right_kid = tmp;
			else
				point->_parent->_left_kid = tmp;
			tmp->_right_kid = point;
			point->_parent = tmp;
		}

		std::size_t size(node_type *node) const {
			if (!node)
				return 0;
			return size(node->_right_kid) + size(node->_left_kid) + 1;
		}

		void eraseNode(node_type *node) {
			if (!node)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		};

		void insert_node(node_type *new_node, node_type **place, node_type *new_parent) {
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

		void replaceNode(node_type **curr_node, node_type *new_node) {
			node_type *tmp = *curr_node;
			node_type *left_kid = tmp->_left_kid;
			node_type *right_kid = tmp->_right_kid;
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

		node_type *getSuccessor(node_type *curr_node) {
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

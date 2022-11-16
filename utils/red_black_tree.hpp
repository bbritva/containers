//
// Created by grvelva on 10/22/22.
//

#ifndef CONTAINERS_RED_BLACK_TREE_HPP
#define CONTAINERS_RED_BLACK_TREE_HPP

#include <iostream>
#include <limits>
#include "node.hpp"
#include "direct_tree_iterator.hpp"

namespace ft {
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<node<T> > >
	class rb_tree
	{
	private:
		typedef typename Allocator::template rebind<node<T> >::other	node_allocator;
	public:
		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef Compare							key_compare;
		typedef node<T>							node_type;
		typedef tree_iterator<node_type>		iterator;
		typedef tree_iterator_const<node_type>	const_iterator;

	private:
		node_allocator	_node_allocator;
		node_type		*_root;
		node_type		*_leaf;
		key_compare		_comparator;

	public:
		explicit rb_tree(const allocator_type &alloc = allocator_type(),
						 const key_compare &comparator = key_compare())
			: _node_allocator(alloc), _comparator(comparator)
		{
			_leaf = _node_allocator.allocate(1);
			_node_allocator.construct(_leaf, node_type(T(), black, _leaf, _leaf, _leaf));
			_root = _leaf;
		};

		~rb_tree() {
			clear();
			_node_allocator.destroy(_leaf);
			_node_allocator.deallocate(_leaf, 1);
		};

		rb_tree(const rb_tree& other)
			: _node_allocator(other._node_allocator), _comparator(other._comparator)
		{
			iterator it = iterator(other.getMin());
			iterator ite = iterator(other.getLast());
			_leaf = _node_allocator.allocate(1);
			_node_allocator.construct(_leaf, node_type(T(), black, _leaf, _leaf, _leaf));
			_root = _leaf;
			while (it != ite) {
				insert(*it);
				++it;
			}
		}

		rb_tree& operator=(const rb_tree& other) {
			if (this == &other)
				return *this;
			clear();

			iterator it = iterator(other.getMin());
			iterator ite = iterator(other.getLast());
			while (it != ite)
				insert(*it++);
			return *this;
		};


		void swap(rb_tree& other)
		{
			node_allocator	tmp_node_allocator = other._node_allocator;
			other._node_allocator = _node_allocator;
			_node_allocator = tmp_node_allocator;

			key_compare tmp_comparator = other._comparator;
			other._comparator = _comparator;
			_comparator = tmp_comparator;

			node_type *tmp = _leaf;
			_leaf = other._leaf;
			other._leaf = tmp;

			tmp = _root;
			_root = other._root;
			other._root = tmp;
		}

		bool insert (value_type value) {
			node_type *new_node = _node_allocator.allocate(1);
			_node_allocator.construct(new_node, node_type(_leaf, value));
//			return insert_node(new_node, &_root, _leaf);
			return insert_node2(new_node, _root);
		};

		bool insert (value_type value, node_type *pos) {
			if (pos == _leaf)
				return insert(value);
			node_type *new_node = _node_allocator.allocate(1);
			_node_allocator.construct(new_node, node_type(_leaf, value));
//			return insert_node(new_node, &pos, pos->_parent);
			return insert_node2(new_node, pos);
		};

		bool empty() const {
			return _root == _leaf;
		}

		void clear() {
			eraseNode(_root);
			_root = _leaf;
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

		node_type *getRoot() const { return _root; }
		node_type *getMin() const { return node_type::getMin(_root); }
		node_type *getMax() const { return node_type::getMax(_root); }
		node_type *getLast() const { return _leaf; }

		void deleteNode(node_type *to_delete) {
			node_type *to_clear = to_delete;
			if (to_delete != _leaf) {
				if (to_delete->_right_kid != _leaf) {
					if (to_delete->_left_kid != _leaf) {
						replaceNode(to_delete, to_delete->getSuccessor());
					} else {
						replaceByKid(to_delete, false);
					}
				} else {
					if (to_delete->_left_kid) {
						replaceByKid(to_delete, true);
					} else {
						replaceNode(to_delete, _leaf);
					}
				}
				if (to_clear->_color == black)
					balanceDelete(to_delete);
				_node_allocator.destroy(to_clear);
				_node_allocator.deallocate(to_clear, 1);
				_leaf->_parent = _root;
			}
		};

		node_type *findByKey(const value_type &key, node_type *node) const {
			if (node == _leaf)
				return _leaf;
			if (_comparator(key, node->_value))
				return findByKey(key, node->_left_kid);
			if (_comparator(node->_value, key))
				return findByKey(key, node->_right_kid);
			return node;
		};

	private:

		void rotateLeft(node_type *point) {
			node_type *tmp = point->_right_kid;
			point->_right_kid = tmp->_left_kid;
			if (tmp->_left_kid != _leaf)
				tmp->_left_kid->_parent = point;
			tmp->_parent = point->_parent;
			if (point->_parent == _leaf)
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
			if (tmp->_right_kid != _leaf)
				tmp->_right_kid->_parent = point;
			tmp->_parent = point->_parent;
			if (point->_parent == _leaf)
				_root = tmp;
			else if (point == point->_parent->_right_kid)
				point->_parent->_right_kid = tmp;
			else
				point->_parent->_left_kid = tmp;
			tmp->_right_kid = point;
			point->_parent = tmp;
		}

		std::size_t size(node_type *node) const {
			if (node == _leaf)
				return 0;
			return size(node->_right_kid) + size(node->_left_kid) + 1;
		}

		void eraseNode(node_type *node) {
			if (node == _leaf)
				return;
			eraseNode(node->_left_kid);
			eraseNode(node->_right_kid);
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		};

		bool insert_node(node_type *new_node, node_type **place, node_type *new_parent) {
			if (!place || !*place || !new_node)
				return false;
			if (*place == _leaf) {
				new_node->_parent = new_parent;
				*place = new_node;
				if (new_parent == _leaf) {
					(*place)->_color = black;
					_leaf->_parent = new_node;
				}
			} else if (_comparator( new_node->_value, (*place)->_value)) {
				insert_node(new_node, &((*place)->_left_kid), *place);
			} else if (_comparator( (*place)->_value, new_node->_value)) {
				insert_node(new_node, &((*place)->_right_kid), *place);
			} else {
				return false;
			}
			balanceNode(*place);
			return true;
		};

		bool insert_node2(node_type *new_node, node_type *current) {
			if (!current || !new_node)
				return false;
			if (current == _leaf) {
				_root = new_node;
				_leaf->_parent = _root;
				_root->_parent = _leaf;
			} else if (_comparator( new_node->_value, current->_value)) {
				if (current->_left_kid == _leaf) {
					current->_left_kid = new_node;
					current->_left_kid->_parent = current;
				} else {
					insert_node2(new_node, current->_left_kid);
				}
			} else if (_comparator( current->_value, new_node->_value)) {
				if (current->_right_kid == _leaf) {
					current->_right_kid = new_node;
					current->_right_kid->_parent = current;
				} else {
					insert_node2(new_node, current->_right_kid);
				}
			} else {
				_node_allocator.destroy(new_node);
				_node_allocator.deallocate(new_node, sizeof(new_node));
				return false;
			}
//			balanceNode(current);
			return true;
		};

		void replaceNode(node_type *curr_node, node_type *new_node) {
			//set left kid to new node
			new_node->_left_kid = curr_node->_left_kid;
			new_node->_left_kid->_parent = new_node;

			if (curr_node->_right_kid != new_node) {
				// replace new_node's right kid to new_node's parent
				new_node->_right_kid->_parent = new_node->_parent;
				new_node->_parent->_left_kid = new_node->_right_kid;

				//set right kid to new node
				new_node->_right_kid = curr_node->_right_kid;
				new_node->_right_kid->_parent = new_node;
			}
			new_node->_parent = curr_node->_parent;
			if (curr_node == _root) {
				//Node is ROOT
				_leaf->_parent = new_node;
				_root = new_node;
			} else {
				//Node is NOT ROOT
				if (curr_node->_parent->_left_kid == curr_node)
					curr_node->_parent->_left_kid = new_node;
				else
					curr_node->_parent->_right_kid = new_node;
			}
		};

		void replaceByKid(node_type *curr_node, bool isLeft) {
			node_type *parent = curr_node->_parent;
			if (parent != _leaf) {
				if (isLeft) {
					curr_node->_left_kid->_parent = parent;
					if (parent->_left_kid == curr_node)
						parent->_left_kid = curr_node->_left_kid;
					else
						parent->_right_kid = curr_node->_left_kid;
				} else {
					curr_node->_right_kid->_parent = parent;
					if (parent->_left_kid == curr_node)
						parent->_left_kid = curr_node->_right_kid;
					else
						parent->_right_kid = curr_node->_right_kid;
				}
			} else {
				if (isLeft) {
					_root = curr_node->_left_kid;
				} else {
					_root = curr_node->_right_kid;
				}
				_root->_parent = _leaf;
				_leaf->_parent = _root;
			}
		}



		void balanceDeleteRightKid(node_type **point_ptr) {
			node_type * tmp;
			node_type * point = *point_ptr;

			tmp = point->_parent->_left;
			if (tmp->_color == RED)
			{
				tmp->_color = black;
				point->_parent->_color = RED;
				rightRotation(point->_parent);
				tmp = point->_parent->_left_kid;
			}
			if (tmp->_left_kid->_color == black && tmp->_right_kid->_color == black)
			{
				tmp->_color = RED;
				*point_ptr = point->_parent;
			}
			else
			{
				if (tmp->_left_kid->_color == black)
				{
					tmp->_right_kid->_color = black;
					tmp->_color = RED;
					leftRotation(tmp);
					tmp = point->_parent->_left_kid;
				}
				tmp->_color = point->_parent->_color;
				point->_parent->_color = black;
				tmp->_left_kid->_color = black;
				rightRotation(point->_parent);
				*point_ptr = _root;
			}
		}

		void balanceDeleteLeftKid(node_type **point_ptr) {
			node_type * tmp;
			node_type * point = *point_ptr;

			tmp = point->_parent->_right_kid;
			if (tmp->_color == RED)
			{
				tmp->_color = black;
				point->_parent->_color = RED;
				leftRotation(point->_parent);
				tmp = point->_parent->_right_kid;
			}
			if (tmp->_left_kid->_color == black && tmp->_right_kid->_color == black)
			{
				tmp->_color = RED;
				*point_ptr = point->_parent;
			}
			else
			{
				if (tmp->_right_kid->_color == black)
				{
					tmp->_left_kid->_color = black;
					tmp->_color = RED;
					rightRotation(tmp);
					tmp = point->_parent->_right_kid;
				}
				tmp->_color = point->_parent->_color;
				point->_parent->_color = black;
				tmp->_right_kid->_color = black;
				leftRotation(point->_parent);
				*point_ptr = _root;
			}
		}

		void balanceDelete(node_type *point)
		{
			node_type * tmp;
			while (point != _root && point->_color == black)
			{
				if (point == point->_parent->_left_kid) {
					// node is left kid
//					balanceDeleteLeftKid(&point);
					tmp = point->_parent->_right_kid;
					if (tmp->_color == RED) {
						tmp->_color = black;
						point->_parent->_color = RED;
						rotateLeft(point->_parent);
						tmp = point->_parent->_right_kid;
					}
					if (tmp->_left_kid->_color == black && tmp->_right_kid->_color == black) {
						tmp->_color = RED;
						point = point->_parent;
					} else {
						if (tmp->_right_kid->_color == black) {
							tmp->_left_kid->_color = black;
							tmp->_color = RED;
							rotateRight(tmp);
							tmp = point->_parent->_right_kid;
						}
						tmp->_color = point->_parent->_color;
						point->_parent->_color = black;
						tmp->_right_kid->_color = black;
						rotateLeft(point->_parent);
						point = _root;
					}
				}
				else
				{
					// node is right kid
//					balanceDeleteRightKid(&point);
					tmp = point->_parent->_left_kid;
					if (tmp->_color == RED) {
						tmp->_color = black;
						point->_parent->_color = RED;
						rotateRight(point->_parent);
						tmp = point->_parent->_left_kid;
					}
					if (tmp->_left_kid->_color == black && tmp->_right_kid->_color == black) {
						tmp->_color = RED;
						point = point->_parent;
					} else {
						if (tmp->_left_kid->_color == black)
						{
							tmp->_right_kid->_color = black;
							tmp->_color = RED;
							rotateLeft(tmp);
							tmp = point->_parent->_left_kid;
						}
						tmp->_color = point->_parent->_color;
						point->_parent->_color = black;
						tmp->_left_kid->_color = black;
						rotateRight(point->_parent);
						point = _root;
					}
				}
			}
			point->_color = black;
		}

		void balanceNode(node_type *point) {
			if (point->_right_kid->_color == RED
				&& point->_left_kid->_color == black) {
				rotateLeft(point);
			}
			if (point->_left_kid->_color == RED
				&& point->_left_kid->_left_kid->_color == RED) {
				rotateRight(point);
			}
			if (point->_left_kid->_color == RED
				&& point->_right_kid->_color == RED) {
				swap_color(point);
			}
		}

		void swap_color(node_type *point) {
			point->_color = (point->_parent == _leaf) ? RED : black;
			point->_right_kid->_color = black;
			point->_left_kid->_color = black;
		}

	};


}

#endif //CONTAINERS_RED_BLACK_TREE_HPP

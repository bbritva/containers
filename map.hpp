#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "direct_vector_iterator.hpp"
# include "reverse_vector_iterator.hpp"
# include "red_black_tree.hpp"
# include "sfinae.hpp"
# include "pair.hpp"

namespace ft {
	template<typename Key, typename Value,
			typename Compare = std::less<Key>,
			typename A = std::allocator< node<ft::pair<Key, Value> > > >
	class map {
	public:
		typedef std::size_t						size_type;
		typedef pair<Key, Value>				pair_type;
		typedef node<ft::pair<Key, Value> >		node_type;

	private:
		rb_tree<pair_type, std::less<Key> >		_tree;
//		A										_allocator;
		std::allocator<node_type>				_allocator;
		size_type								_size;

	public:

		//constructors

		explicit map(const A& allocator = A()) {
			_allocator = allocator;
			_tree = rb_tree<pair_type, std::less<Key> >();
			_size = 0;
		};

		map(map const &other, const A &allocator = A()) {
			_allocator = allocator;
			_tree = other._tree;
			_size = other._size;
		}

		~map() {}

		map &operator=(const map &other) {
			if (this == &other)
				return (*this);
//			clear();
			_tree = other._tree;
			_size = other._size;
			return (*this);
		}

		void insert (pair_type & new_pair) {
			node_type *new_node = _allocator.allocate(1);
			_allocator.construct(new_node, node_type (new_pair));
//			new_node->_value = new_pair;
			_tree.insert(new_node);
		};

		const std::allocator<node_type>& get_allocator() const {
			return _allocator;
		}

		std::size_t size() const {
			return (_size);
		}

		std::size_t max_size() const {
			return _allocator.max_size();
		}

		void clear() {
			_tree.clear();
		}
	};
	//class end
}
#endif//MAP_HPP
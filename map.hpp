#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "pair.hpp"
# include "direct_tree_iterator.hpp"
# include "reverse_iterator.hpp"
# include "red_black_tree.hpp"
# include "sfinae.hpp"

namespace ft {
	template<typename Key, typename Value,
			typename Compare = std::less<Key>,
			typename A = std::allocator< node<ft::pair<Key, Value> > > >
	class map {
	public:
		typedef std::size_t						size_type;
		typedef pair<Key, Value>				pair_type;
		typedef node<ft::pair<Key, Value> >		node_type;

		typedef ft::tree_iterator<node_type>			iterator;
		typedef ft::tree_iterator<node_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		class comparator : public std::binary_function<pair_type , pair_type , bool>
		{
			friend class map;

		protected:
			Compare _comp;
			comparator(Compare c) : _comp(c) {}

		public:
			bool operator()(const pair_type &first, const pair_type &second) const {
				return _comp(first.first, second.first);
			}
		};

	private:
		rb_tree<pair_type, comparator, A>			_tree;
//		A										_allocator;
		std::allocator<node_type>				_allocator;

	public:

		//constructors

		explicit map(const Compare& comp = Compare(), const A& allocator = A())
					 : _tree(comparator(comp), _allocator.allocate(1)) {
			_allocator = allocator;
		};

		map(map const &other) {
			_allocator = other._allocator;
			_tree = other._tree;
		}

		~map() {}

		map &operator=(const map &other) {
			if (this == &other)
				return (*this);
			clear();
			_allocator = other._allocator;
			_tree = other._tree;
			return (*this);
		}

		// iterators

		iterator begin()
		{ return iterator (_tree.getFirst(), _tree.getRoot(), _tree.getLast());}

		iterator end()
		{ return iterator (_tree.getLast(), _tree.getRoot(), _tree.getLast()); }

		const_iterator begin() const
		{ return const_iterator (_tree.getFirst(), _tree.getRoot(), _tree.getLast()); }

		const_iterator end() const
		{ return const_iterator (_tree.getLast(), _tree.getRoot(), _tree.getLast()); }

		reverse_iterator rbegin()
		{ return reverse_iterator(begin()); }

		reverse_iterator rend()
		{ return reverse_iterator(end()); }

		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(begin()); }

		const_reverse_iterator rend() const
		{ return const_reverse_iterator(end()); }

		// element access

		Value&	operator[](const Key& key) {
			insert(ft::make_pair(key, Value()));
			return find(key)->_value._second;
		}

		pair<iterator, bool> insert (const pair_type &new_pair) {
			iterator it = find(new_pair.first);
			if (it == end()) {
				node_type *new_node = _allocator.allocate(1);
				_allocator.construct(new_node, node_type(new_pair));
				_tree.insert(new_node, NULL);
				return ft::make_pair(find(new_pair.first), true);
			}
			return ft::make_pair(it, false);
		};

		iterator insert (iterator pos, const pair_type &new_pair) {
			if (pos == end())
				insert(new_pair);
			else {
				node_type *new_node = _allocator.allocate(1);
				_allocator.construct(new_node, node_type(new_pair));
				_tree.insert(new_node, pos.getCurrent());
			}
			return find(new_pair.first);
		};

		template <class InputIt>
		void insert(InputIt begin, InputIt end) {
			while (begin != end) {
				insert(*begin);
				begin++;
			}
		}

		iterator find(const Key& key) {
			return iterator(_tree.findByKey(ft::make_pair(key, Value()), _tree.getRoot()),
							_tree.getRoot(), _tree.getLast());
		}

		const_iterator find(const Key& key) const {
			return const_iterator(	_tree.findByKey(ft::make_pair(key, Value()), _tree.getRoot()),
									_tree.getRoot(), _tree.getLast());
		}

		size_type count(const Key& k) const {
			return (find(k) != end());
		}

		iterator upper_bound(const Key& key) {
			iterator it = begin();
			pair_type pair = ft::make_pair(key, Value());
			while (key_comp(*it, pair) && it != end())
				it++;
			return it;
		}

		const_iterator	upper_bound(const Key& key) const {
			return const_iterator(upper_bound(key));
		}

		iterator lower_bound(const Key& key) {
			iterator it = end();
			pair_type pair = ft::make_pair(key, Value());
			while (key_comp(*it, pair) && it != begin())
				it--;
			return it;
		}

		const_iterator	lower_bound(const Key& key) const {
			return const_iterator(lower_bound(key));
		}

		ft::pair<iterator, iterator> equal_range(const Key& key) {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		// capacity
		bool empty() const {
			return size() == 0;
		}

		std::size_t size() const {
			return _tree.size();
		}

		std::size_t max_size() const {
			return _allocator.max_size();
		}

		void clear() {
			_tree.clear(_allocator);
		};

		// observers:
		Compare key_comp() const {
			return Compare();
		}

		comparator	value_comp() const {
			return comparator(key_comp());
		}

		const std::allocator<node_type>& get_allocator() const {
			return _allocator;
		};
	};
	//class end
}
#endif//MAP_HPP
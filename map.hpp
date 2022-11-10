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
			typename A = std::allocator< ft::pair<const Key, Value> > >
	class map {
	private:
		typedef typename A::template rebind<Value>::other						pair_alloc_type;
		typedef rb_tree<ft::pair<const Key, Value>, Compare, pair_alloc_type>	tree_type;

	public:
		typedef Key								key_type;
		typedef Value							value_type;
		typedef pair<const Key, Value>			pair_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef A								allocator_type;
		typedef value_type &					reference;
		typedef const value_type &				const_reference;
		typedef typename A::pointer             pointer;
		typedef typename A::const_pointer       const_pointer;

		typedef typename tree_type::iterator			iterator;
		typedef typename tree_type::const_iterator		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		class comparator : public std::binary_function<pair_type, pair_type, bool>
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
		tree_type			_tree;
		allocator_type		_allocator;
		comparator			_comparator;
//		key_compare			_key_comp;
		size_type			_size;

	public:

		//constructors
		explicit map(const key_compare& comp = Compare(),
					 const allocator_type& allocator = allocator_type())
					 : _comparator(comp), _allocator(allocator),
//					 _key_comp(key_comp),
					 _size(0) {};

		map(const map<Key, Value, Compare, A> &other)
			:_comparator(other._key_comp),
			_allocator(other._allocator),
//			_key_comp(other._key_comp),
			_size(other._size),
			_tree(other._tree) {}


		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare & key_comp = key_compare(),
			const allocator_type &allocator = allocator_type())
				: _comparator(key_comp), _allocator(allocator),
//				_key_comp(key_comp),
				_size(0)
		{ insert(first, last); }

		~map() { clear(); }

		map &operator=(const map &other) {
			if (this == &other)
				return (*this);
			clear();
			_allocator = other._allocator;
			_tree = other._tree;
			_comparator = other._comparator;
			_size = other._size;
			return (*this);
		}

		// iterators
		iterator begin()
		{ return iterator (_tree.getFirst());}
		iterator end()
		{ return iterator (_tree.getLast()); }
		const_iterator begin() const
		{ return const_iterator (_tree.getFirst()); }
		const_iterator end() const
		{ return const_iterator (_tree.getLast()); }

		reverse_iterator rbegin()
		{ return reverse_iterator(begin()); }
		reverse_iterator rend()
		{ return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(begin()); }
		const_reverse_iterator rend() const
		{ return const_reverse_iterator(end()); }

		// element access

		reference operator[](const key_type &key) {
			insert(make_pair(key, Value()));
			return find(key)->_value._second;
		}

		reference at(const key_type &key) {
			iterator it = find(key);
			if (find(key) == end())
				throw std::out_of_range("ft::map::at");
			return (find(key)->second);
		}

		const_reference at(const key_type& key) const	{
			iterator it = find(key);
			if (find(key) == end())
				throw std::out_of_range("ft::map::at");
			return (find(key)->second);
		}

		// modifiers
		pair<iterator, bool> insert (const pair_type &new_pair) {
			iterator it = find(new_pair.first);
			if (it == end()) {
				_size++;
				_tree.insert(new_pair, NULL);
				return ft::make_pair(find(new_pair.first), true);
			}
			return ft::make_pair(it, false);
		};

		iterator insert (iterator pos, const pair_type &new_pair) {
			if (pos == end())
				insert(new_pair);
			else {
				_tree.insert(new_pair, pos.getCurrent());
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
			return _size;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
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
#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "utils/pair.hpp"
# include "utils/direct_tree_iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/red_black_tree.hpp"
# include "utils/sfinae.hpp"
# include "utils/compare_utils.hpp"

namespace ft {
	template<typename Key, typename Value,
			typename Compare = std::less<Key>,
			typename A = std::allocator< ft::pair<const Key, Value> > >
	class map {
	private:
		typedef typename A::template rebind<ft::pair<const Key, Value> >::other	pair_alloc_type;

	public:
		typedef Key								key_type;
		typedef pair<const Key, Value>			value_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef A								allocator_type;
		typedef Value &							reference;
		typedef const Value &					const_reference;
		typedef typename A::pointer             pointer;
		typedef typename A::const_pointer       const_pointer;

		class comparator : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

		protected:
			key_compare _comp;
			comparator(key_compare comp) : _comp(comp) {}

		public:
			bool operator()(const value_type &first, const value_type &second) const {
				return _comp(first.first, second.first);
			}
		};

		typedef rb_tree<value_type, comparator, pair_alloc_type>	tree_type;
		typedef typename tree_type::iterator			iterator;
		typedef typename tree_type::const_iterator		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		pair_alloc_type		_allocator;
		comparator			_comparator;
		tree_type			_tree;
//		key_compare			_key_comp;

	public:

		//constructors
		explicit map(const key_compare& comp = Compare(),
					 const allocator_type& allocator = allocator_type())
						: _allocator(allocator), _comparator(comp),
						_tree(_allocator, _comparator)
//						_key_comp(key_comp),
						{};

		map(const map<Key, Value, Compare, A> &other)
			: _allocator(other._allocator),
			_comparator(other._comparator),
			//			_key_comp(other._key_comp),
			_tree(other._tree) {}


		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare & key_comp = key_compare(),
			const allocator_type &allocator = allocator_type())
				: _allocator(allocator), _comparator(key_comp),
				_tree(_allocator, _comparator)
//				_key_comp(key_comp),
		{ insert(first, last); }

		~map() { clear(); }

		map &operator=(const map &other) {
			if (this == &other)
				return (*this);
			clear();
			_allocator = other._allocator;
			_tree = other._tree;
			_comparator = other._comparator;
			return (*this);
		}

		// iterators
		iterator begin()
		{ return iterator (_tree.getMin());}
		iterator end()
		{ return iterator (_tree.getLast()); }
		const_iterator begin() const
		{ return const_iterator (_tree.getMin()); }
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
			return insert(ft::make_pair(key, Value())).first->second;
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
		pair<iterator, bool> insert(const value_type &new_pair) {
			iterator it = find(new_pair.first);
			if (it == end()) {
				_tree.insert(new_pair);
				return ft::make_pair(find(new_pair.first), true);
			}
			return ft::make_pair(it, false);
		};

		iterator insert(iterator pos, const value_type &new_pair) {
			if (pos == end())
				insert(new_pair);
			else {
				if (_comparator(new_pair, *pos)) {
					_tree.insert(new_pair, lower_bound(new_pair.first).getCurrent());
				}
				else if (_comparator(*pos, new_pair)) {
					_tree.insert(new_pair, upper_bound(new_pair.first).getCurrent());
				}
				else
					_tree.insert(new_pair);
			}
			return find(new_pair.first);
		};

		template <class InputIt>
		void insert(InputIt begin, InputIt end, typename enable_if<!is_integral<InputIt>::value>::type = 0) {
			while (begin != end) {
				insert(*begin);
				begin++;
			}
		}

		void erase(iterator pos) {
			if (pos != end()) {
				_tree.deleteNode(pos.getCurrent());
			}
		}

		size_type erase(const key_type& key) {
			iterator it = find(key);
			if (it != end()) {
				erase(it);
				return true;
			}
			return false;
		}

		void erase(iterator first, iterator last) {
			while (first != last) {
				iterator tmp = first;
				++first;
				erase(tmp);
			}
		}

		iterator find(const key_type &key) {
			return iterator(_tree.findByKey(value_type(key, Value()), _tree.getRoot()));
		}

		const_iterator find(const key_type& key) const {
			return const_iterator(_tree.findByKey(value_type(key, Value()), _tree.getRoot()));
		}

		size_type count(const key_type &key) const {
			return (find(key) != end());
		}

		iterator upper_bound(const Key& key) {
			iterator it = begin();
			value_type pair = ft::make_pair(key, Value());
			while (!_comparator(pair, *it) && it != end())
				it++;
			return it;
		}

		const_iterator	upper_bound(const Key& key) const {
			const_iterator it = begin();
			value_type pair = ft::make_pair(key, Value());
			while (!_comparator(pair, *it) && it != end())
				it++;
			return it;
		}

		iterator lower_bound(const Key& key) {
			iterator it = begin();
			value_type pair = ft::make_pair(key, Value());
			while (_comparator(*it, pair) && it != end())
				it++;
			return it;
		}

		const_iterator	lower_bound(const Key& key) const {
			const_iterator it = begin();
			value_type pair = ft::make_pair(key, Value());
			while (_comparator(*it, pair) && it != end())
				it++;
			return it;
		}

		ft::pair<iterator, iterator> equal_range(const Key& key) {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		// capacity
		bool empty() const {
			return _tree.empty();
		}

		size_type size() const {
			return _tree.size();
		}

		size_type max_size() const {
			return _tree.maxSize();
		}

		void clear() {
			_tree.clear();
		};

		// observers:
		Compare key_comp() const {
			return Compare();
		}

		comparator	value_comp() const {
			return comparator(key_comp());
		}

		const allocator_type &get_allocator() const {
			return _allocator;
		};
	};
	//class end

	template <class Key, class Value, class Compare, class Allocator>
	void swap(map<Key, Value, Compare, Allocator> &first,
			  map<Key, Value, Compare, Allocator> &second)
	{ first.swap(second); }

	template <class Key, class Value, class Compare, class Allocator>
	bool operator==(const map<Key, Value, Compare, Allocator> &first,
					const map<Key, Value, Compare, Allocator> &second)
	{
		return (first.size() == second.size()
			&& equal(first.begin(), first.end(), second.begin()));
	}

	template <class Key, class Value, class Compare, class Allocator>
	bool operator<(	const map<Key, Value, Compare, Allocator> &first,
					const map<Key, Value, Compare, Allocator> &second)
	{
		return ft::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
	}

	template <class Key, class Value, class Compare, class Allocator>
	bool operator!=(const map<Key ,Value ,Compare, Allocator> &first,
					const map<Key ,Value ,Compare, Allocator> &second)
	{ return (!(first == second)); }

	template <class Key, class Value, class Compare, class Allocator>
	bool operator>(const map<Key, Value, Compare, Allocator> &first,
				   const map<Key, Value, Compare, Allocator> &second)
	{ return (!(first <= second)); }

	template <class Key, class Value, class Compare, class Allocator>
	bool operator>=(const map<Key, Value, Compare, Allocator> &first,
					const map<Key, Value, Compare, Allocator> &second)
	{ return (first > second || first == second); }

	template <class Key, class Value, class Compare, class Allocator>
	bool operator<=(const map<Key, Value, Compare, Allocator> &first,
					const map<Key, Value, Compare, Allocator> &second)
	{ return (first < second || first == second);}

}
#endif//MAP_HPP
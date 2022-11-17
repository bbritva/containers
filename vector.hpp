#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "utils/direct_vector_iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/sfinae.hpp"
# include "utils/compare_utils.hpp"

namespace ft {
	template<typename T, typename A = std::allocator<T> >
	class vector {
	private:
		typedef typename A::template rebind<T>::other _T_alloc;
	public:
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef const T*								const_pointer;
		typedef const T&								const_reference;
		typedef A										allocator_type;
		typedef std::ptrdiff_t							difference_type;
		typedef std::size_t								size_type;
		typedef ft::random_access_iterator<T>			iterator;
		typedef ft::random_access_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		allocator_type	_allocator;
		size_type		_capacity;
		size_type		_size;
		pointer			_arr;

	public:

		//constructors
		explicit vector(const allocator_type allocator = allocator_type())
				: _allocator(allocator),
				  _capacity(0),
				  _size(0),
				  _arr(_allocator.allocate(_capacity)) {};

		explicit vector(size_type size, const_reference value = T(), const allocator_type& allocator = allocator_type())
				: _allocator(allocator),
				  _capacity(0),
				  _size(0),
				  _arr(_allocator.allocate(_capacity)) {
			reserve(size);
			for (size_type i = 0; i < size; ++i) {
				push_back(value);
			}
		};

		vector(vector const &other)
				: _allocator(other._allocator),
				_capacity(other._capacity),
				_size(other._size),
				_arr(_allocator.allocate(_capacity)) {
			for (size_type i = 0; i < other._size; ++i)
				_allocator.construct(&_arr[i], other._arr[i]);
		}

		template< class InputIterator >
		vector( InputIterator first, InputIterator last, const allocator_type& allocator = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
				: _allocator(allocator),
				  _capacity(0),
				  _size(0),
				  _arr(_allocator.allocate(_capacity)) {
			while (first != last)
				push_back(*first++);
		}

		~vector() {
			clear();
			_allocator.deallocate(_arr, _capacity);
		}

		vector &operator=(const vector &other) {
			if (this == &other)
				return (*this);
			clear();
			if (_capacity < other._capacity) {
				_allocator.deallocate(_arr, _capacity);
				_arr = _allocator.allocate(other._capacity);
				_capacity = other._capacity;
			}
			for (size_type i = 0; i < other._size; ++i)
				_allocator.construct(&_arr[i], other._arr[i]);
			_size = other._size;
			return (*this);
		}

		// Iterators

		iterator begin() {
			return iterator(&_arr[0]);
		}

		iterator end() {
			return iterator(&_arr[_size]);
		}

		const_iterator begin() const {
			return const_iterator(&_arr[0]);
		}

		const_iterator end() const {
			return const_iterator(&_arr[_size]);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(iterator(&_arr[_size]));
		}

		reverse_iterator rend() {
			return reverse_iterator(iterator(&_arr[0]));
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(const_iterator(&_arr[_size]));
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(const_iterator(&_arr[0]));
		}

		// Allocator

		const allocator_type& get_allocator() const {
			return _allocator;
		}

		// Element access
		reference operator[](size_type index) {
			return _arr[index];
		}
		const_reference operator[](size_type index) const {
			return _arr[index];
		}

		reference at( size_type index ) {
			if (index < _size)
				return _arr[index];
			throw std::out_of_range("out_of_range");
		}

		const_reference at( size_type index ) const {
			if (index < _size)
				return _arr[index];
			throw std::out_of_range("out_of_range");
		}

		reference front() { return _arr[0]; }
		const_reference front() const { return _arr[0]; }

		reference back() { return _arr[_size - 1]; }
		const_reference back() const { return _arr[_size - 1]; }

		pointer data() {
			return _arr;
		}

		// Capacity

		size_type size() const { return (_size); }
		size_type max_size() const { return _allocator.max_size(); }
		size_type capacity() const { return (_capacity); }
		bool empty() const { return (_size == 0); }

		void resize(size_type count, value_type value = value_type()) {
			while (_size < count)
				push_back(value);
			while (_size > count)
				pop_back();
		}

		void reserve(size_type new_cap) {
			if (new_cap <= _capacity)
				return;
			if (new_cap > max_size())
				throw std::length_error("vector::reserve");
			pointer new_arr = _allocator.allocate(new_cap);
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(&new_arr[i], _arr[i]);
				_allocator.destroy(&_arr[i]);
			}
			_allocator.deallocate(_arr, _capacity);
			_capacity = new_cap;
			_arr = new_arr;
		}

		// Modifiers

		void assign (size_type n, const_reference value) {
			clear();
			reserve(n);
			while (n--) {
				push_back(value);
			}
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) {
			clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		void push_back(T new_el) {
			if (_size + 1 > _capacity)
				reserve(_capacity ? _capacity * 2 : 1);
			_allocator.construct(&_arr[_size++], new_el);
		}

		void pop_back() {
			_size--;
			_allocator.destroy(&_arr[_size]);
		}

		iterator insert (iterator position, const_reference value)
		{
			if (position == end()) {
				push_back(value);
				return end() - 1;
			} else {
				size_type index = position - begin();
				push_back(back());
				position = iterator(&_arr[index]);
				iterator it = end() - 1;
				while (it != position) {
					_allocator.destroy(it.getPtr());
					_allocator.construct(it.getPtr(), *(it - 1));
					it--;
				}
				*it = value;
				return position;
			}
		}

		iterator insert (iterator position, size_type n, const_reference value)
		{
			position = move(position, n);
			iterator ret = position;
			for (size_type i = 0; i < n; ++i) {
				_allocator.construct(position.getPtr(), value);
				position++;
			}
			_size += n;
			return ret;
		}

		template <class InputIterator>
		iterator insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
		{
			size_type n = ft::distance(first, last);
			if (_capacity <= _size + n) {
				size_type index = position - begin();
				reserve(_size + n);
				position = iterator(&_arr[index]);
			}
			iterator it = end() + n - 1;
			while (it != position + n - 1) {
				_allocator.construct(it.getPtr(), *(it - n));
				_allocator.destroy((it - n).getPtr());
				it--;
			}
			iterator ret = position;
			while (first != last) {
				_allocator.construct(position.getPtr(), *first);
				position++;
				first++;
			}
			_size += n;
			return ret;
		}

		void swap(vector& other) {
			pointer arr = _arr;
			size_type capacity = _capacity;
			size_type size = _size;
			allocator_type allocator = _allocator;
			_arr = other._arr;
			_capacity = other._capacity;
			_size = other._size;
			_allocator = other._allocator;
			other._arr = arr;
			other._capacity = capacity;
			other._size = size;
			other._allocator = allocator;
		}

		void clear() {
			for (size_type i = 0; i < _size; ++i) {
				_allocator.destroy(&_arr[i]);
			}
			_size = 0;
		}

		iterator erase(iterator pos) {
			iterator it = pos;
			if (it != end()) {
				while (it < end() - 1) {
					_allocator.destroy(it.getPtr());
					_allocator.construct(it.getPtr(), *(it + 1));
					it++;
				}
				_allocator.destroy(it.getPtr());
				--_size;
			}
			return pos;
		}

		iterator erase(iterator first, iterator last) {
			iterator ret = first;
			iterator it_end = end();
			while (last < it_end) {
				_allocator.destroy(first.getPtr());
				_allocator.construct(first.getPtr(), *last);
				last++;
				first++;
			}
			while (first < it_end) {
				_allocator.destroy(first.getPtr());
				first++;
				_size--;
			}
			return ret;
		}

		void show() {
			std::cout << std::endl << "Content is:" << std::endl;
			iterator it = begin();
			for (; it != end(); ++it)
				std::cout << "- " << *it << std::endl;
		}
	private:
		iterator move(iterator position, size_type n) {
			if (_capacity <= _size + n) {
				size_type index = position - begin();
				reserve(_size + n);
				position = iterator(&_arr[index]);
			}
			iterator it = end() + n - 1;
			iterator ite = position + n - 1;
//			while (it != (end() - 1) && it != ite) {
//				_allocator.construct(it.getPtr(), *(it - n));
//				_allocator.destroy((it - n).getPtr());
//				it--;
//			}
			while (it != ite) {
				_allocator.construct(it.getPtr(), *(it - n));
				_allocator.destroy((it - n).getPtr());
				it--;
			}
			return position;
		}
	};
	//class end



	template <class T>
	void swap (ft::vector<T> &first, ft::vector<T> &second) {
		first.swap(second);
	}

	template<class T, class Allocator>
	bool operator==(const vector<T, Allocator> &first,
					const vector<T, Allocator> &second) {
		return first.size() == second.size() &&
				ft::equal(first.begin(), first.end(), second.begin());
	}

	template<class T, class Allocator>
	bool operator!=(const vector<T, Allocator> &first,
					const vector<T, Allocator> &second) {
		return !(first == second);
	}

	template<class T, class Allocator>
	bool operator<(const vector<T, Allocator> &first,
				   const vector<T, Allocator> &second) {
		return lexicographical_compare(first.begin(), first.end(),
									   second.begin(), second.end());
	}

	template<class T, class Allocator>
	bool operator<=(const vector<T, Allocator> &first,
					const vector<T, Allocator> &second) {
		return !(second < first);
	}

	template<class T, class Allocator>
	bool operator>(const vector<T, Allocator> &first,
					const vector<T, Allocator> &second) {
		return second < first;
	}

	template<class T, class Allocator>
	bool operator>=(const vector<T, Allocator> &first,
					const vector<T, Allocator> &second) {
		return !(first < second);
	}
}
#endif//VECTOR_HPP
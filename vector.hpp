#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "direct_vector_iterator.hpp"
# include "reverse_vector_iterator.hpp"
# include "sfinae.hpp"

namespace ft {
	template<typename T, typename A = std::allocator<T> >
	class vector {
	public:
		typedef std::size_t									size_type;
		typedef ft::random_access_iterator<T>				iterator;
		typedef ft::random_access_iterator<const T>			const_iterator;
		typedef ft::reverse_iterator<T>						reverse_iterator;
		typedef ft::reverse_iterator<const T>				const_reverse_iterator;

	private:
		T *_arr;
		std::size_t _capacity;
		std::size_t _size;
		std::allocator<T> _allocator;
	public:

		//constructors

		explicit vector(const std::allocator<T>& allocator = std::allocator<T>()) {
			_size = 0;
			_capacity = 0;
			_allocator = allocator;
		};

		explicit vector(std::size_t size, const T& value = T(), const std::allocator<T>& allocator = std::allocator<T>()) {
			_allocator = allocator;
			_size = 0;
			_capacity = 0;
			reserve(size);
			for (std::size_t i = 0; i < size; ++i) {
				push_back(value);
			}
		};

		vector(vector const &other, const std::allocator<T>& allocator = std::allocator<T>()) {
			_allocator = allocator;
			_arr = _allocator.allocate(other._capacity);
			for (std::size_t i = 0; i < other._size; ++i)
				_arr[i] = other._arr[i];
			_capacity = other._capacity;
			_size = other._size;
		}

		template< class InputIterator >
		vector( InputIterator first, InputIterator last, const std::allocator<T>& allocator = std::allocator<T>(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) {
			_capacity = 0;
			_allocator = allocator;
			_size = 0;
			while (first != last)
				push_back(*first++);
		}

		~vector() {
			clear();
			if (_capacity)
				_allocator.deallocate(_arr, _capacity);
		}

		vector &operator=(const vector &other) {
			if (this == &other)
				return (*this);
			clear();
			if (_capacity < other._capacity) {
				if (_capacity)
					_allocator.deallocate(_arr, _capacity);
				_arr = _allocator.allocate(other._capacity);
			}
			for (std::size_t i = 0; i < other._size; ++i)
				_allocator.construct(&_arr[i], other._arr[i]);
			_capacity = other._capacity;
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
			return reverse_iterator(&_arr[_size]);
		}

		reverse_iterator rend() {
			return reverse_iterator(&_arr[0]);
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(&_arr[_size]);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(&_arr[0]);
		}

		// Allocator

		const std::allocator<T>& get_allocator() const {
			return _allocator;
		}

		// Element access

		T &operator[](std::size_t index) {
			return _arr[index];
		}

		T &at( std::size_t index ) const {
			if (index < _size)
				return _arr[index];
			throw std::out_of_range("out_of_range");
		}

		T &front() const {
			return _arr[0];
		}

		T &back() const {
			return _arr[_size - 1];
		}

		T *data() {
			return _arr;
		}

		// Capacity

		std::size_t size() const {
			return (_size);
		}

		std::size_t max_size() const {
			return _allocator.max_size();
		}

		void resize(std::size_t count, T value = T()) {
			while (_size < count)
				push_back(value);
			while (_size > count)
				pop_back();
		}

		std::size_t capacity() const {
			return (_capacity);
		}

		bool empty() const {
			return (_size == 0);
		}

		void reserve(std::size_t new_cap) {
			if (new_cap <= _capacity) {
				return;
			}
			std::size_t old_capacity = _capacity;
			_capacity = (_capacity) ? _capacity : 1;
			while (_capacity < new_cap)
				_capacity *= 2;
			T *new_arr = _allocator.allocate(_capacity);
			for (std::size_t i = 0; i < _size; ++i) {
				_allocator.construct(&new_arr[i], _arr[i]);
				_allocator.destroy(&_arr[i]);
			}
			if (old_capacity)
				_allocator.deallocate(_arr, old_capacity);
			_arr = new_arr;
		}

		// Modifiers

		void assign (std::size_t n, const T& value) {
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
			if (_size + 1 >= _capacity)
				reserve(_capacity + 1);
			_allocator.construct(&_arr[_size++], new_el);
		}

		void pop_back() {
			_size--;
			_allocator.destroy(&_arr[_size]);
		}

		iterator insert (iterator position, const T& value)
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

		iterator insert (iterator position, std::size_t n, const T& value)
		{
			if (_capacity <= _size + n) {
				size_type index = position - begin();
				reserve(_size + n);
				position = iterator(&_arr[index]);
			}
			iterator ret = position;
			iterator it = end() + n - 1;
			iterator ite = position + n - 1;
			while (it != ite) {
				_allocator.destroy(it.getPtr());
				_allocator.construct(it.getPtr(), *(it - n));
				it--;
			}
			for (std::size_t i = 0; i < n; ++i) {
				_allocator.destroy(position.getPtr());
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
			std::size_t n = ft::distance(first, last);
			if (_capacity <= _size + n) {
				size_type index = position - begin();
				reserve(_size + n);
				position = iterator(&_arr[index]);
			}
			iterator it = end() + n - 1;
			while (it != position + n - 1) {
				*it = *(it - n);
				it--;
			}
			iterator ret = position;
			while (first != last) {
				*position++ = *first++;
			}
			_size += n;
			return ret;
		}

		void swap(vector& other) {
			T *arr = _arr;
			std::size_t capacity = _capacity;
			std::size_t size = _size;
			std::allocator<T> allocator = _allocator;
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
			for (std::size_t i = 0; i < _size; ++i) {
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
				equal(first.begin(), first.end(), second.begin());
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

	template<class T, class U>
	bool lexicographical_compare(T first1, T last1, U first2, U last2) {
		while (first1 != last1 && first2 != last2) {
			if (first2 == last2 || *first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			first1++;
			first2++;
		}
		return first2 != last2;
	}

	template<class T, class U>
	bool equal(T first1, T last1, U first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}
#endif//VECTOR_HPP
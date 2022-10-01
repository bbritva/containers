#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterators.hpp"
# include "sfinae.hpp"

namespace ft {

	template <class T>
	class random_access_iterator : public ft::iterator_base<ft::random_access_iterator_tag, T>
	{
	protected:
		T* _pointer;
	public:
		random_access_iterator() : _pointer(NULL) {}

		explicit random_access_iterator(T* x) : _pointer(x) {}

		random_access_iterator(const random_access_iterator& other) : _pointer(other._pointer) {}

		random_access_iterator &operator=(random_access_iterator &other) {
			if (this == &other)
				return (*this);
			_pointer = ft::random_access_iterator<T>(other._pointer)._pointer;
			return (*this);
		}

		operator random_access_iterator<const T> () const {
			return (random_access_iterator<const T>(this->_pointer));
		}

		virtual random_access_iterator& operator++() {
			++_pointer;
			return *this;
		}

		virtual random_access_iterator operator++(int) {
			random_access_iterator tmp(*this);
			operator++();
			return tmp;
		}

		virtual random_access_iterator& operator--() {
			--_pointer;
			return *this;
		}

		virtual random_access_iterator operator--(int) {
			random_access_iterator tmp(*this);
			operator--();
			return tmp;
		}

		virtual random_access_iterator operator+(std::size_t step) const {
			return random_access_iterator(_pointer + step);
		}

		virtual random_access_iterator operator-(std::size_t step) const {
			return random_access_iterator(_pointer - step);
		}

		virtual random_access_iterator operator+=(std::size_t step) {
			_pointer += step;
			return *this;
		}

		virtual random_access_iterator operator-=(std::size_t step) {
			_pointer -= step;
			return *this;
		}

		virtual T& operator[](std::size_t offset) {
			return *(_pointer + offset);
		}

		bool operator==(const random_access_iterator& other) const {
			return _pointer == other._pointer;
		}
		bool operator!=(const random_access_iterator& other) const {
			return _pointer != other._pointer;
		}

		virtual bool operator>(const random_access_iterator & other) const {
			return _pointer > other._pointer;
		}

		bool operator<(const random_access_iterator & other) const {
			return _pointer < other._pointer;
		}

		bool operator>=(const random_access_iterator & other) const {
			return _pointer >= other._pointer;
		}

		bool operator<=(const random_access_iterator & other) const {
			return _pointer <= other._pointer;
		}

		T& operator*() {
			return *_pointer;
		}

		T* operator->() {
			return _pointer;
		}

	};

	template <class T>
	class reverse_iterator : public ft::random_access_iterator<T>
	{
	public:
		reverse_iterator& operator++() {
			--random_access_iterator<T>::_pointer;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			operator--();
			return tmp;
		}

		reverse_iterator& operator--() {
			++random_access_iterator<T>::_pointer;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			operator++();
			return tmp;
		}

		reverse_iterator operator+(std::size_t step) const {
			return reverse_iterator(random_access_iterator<T>::_pointer - step);
		}

		reverse_iterator operator-(std::size_t step) const {
			return reverse_iterator(random_access_iterator<T>::_pointer + step);
		}

		reverse_iterator operator+=(std::size_t step) {
			random_access_iterator<T>::_pointer -= step;
			return *this;
		}

		reverse_iterator operator-=(std::size_t step) {
			random_access_iterator<T>::_pointer += step;
			return *this;
		}

		T& operator[](std::size_t offset) {
			return *(random_access_iterator<T>::_pointer - offset);
		}


		bool operator>(const reverse_iterator& other) const {
			return random_access_iterator<T>::_pointer < other._pointer;
		}

		bool operator<(const reverse_iterator& other) const {
			return random_access_iterator<T>::_pointer > other._pointer;
		}

		bool operator>=(const reverse_iterator& other) const {
			return random_access_iterator<T>::_pointer <= other._pointer;
		}

		bool operator<=(const reverse_iterator& other) const {
			return random_access_iterator<T>::_pointer >= other._pointer;
		}
	};

	template<typename T>
	class vector {
	public:
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
			if (_capacity)
				_allocator.deallocate(_arr, _capacity);
		}

		vector &operator=(const vector &other) {
			if (this == &other)
				return (*this);
			if (_capacity < other._capacity) {
				_allocator.deallocate(_arr, _capacity);
				_arr = _allocator.allocate(other._capacity);
			}
			for (std::size_t i = 0; i < _capacity; ++i)
				_arr[i] = other._arr[i];
			_capacity = other._capacity;
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

		const_iterator rend() {
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

		T &at( std::size_t index ) {
			if (index < _size)
				return _arr[index];
			throw std::out_of_range("out_of_range");
		}

		T &front() {
			return _arr[0];
		}

		T &back() {
			return _arr[_size - 1];
		}

		T *data() {
			return _arr;
		}

		// Capacity

		std::size_t size() {
			return (_size);
		}

		std::size_t max_size() {
			return _allocator.max_size();
		}

		void resize(std::size_t count, T value = T()) {
			while (_size < count)
				push_back(value);
			while (_size > count)
				pop_back();
		}

		std::size_t capacity() {
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
			reserve(last - first);
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

		void insert (iterator position, const T& value) {
			push_back(back());
			iterator it = end() - 1;
			while (it != (position)) {
				*it = *(it - 1);
				it--;
			}
			*it = value;
		}

		void insert (iterator position, std::size_t n, const T& value) {
			if (_capacity <= _size + n)
				reserve(_size + n);
			iterator it = end() + n - 1;
			while (it != position + n - 1) {
				*it = *(it - n);
				it--;
			}
			for (std::size_t i = 0; i < n; ++i) {
				*position = value;
				position++;
			}
			_size += n;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) {
			std::size_t n = last - first;
			std::cout << n << "\n";
			if (_capacity <= _size + n)
				reserve(_size + n);
			iterator it = end() + n - 1;
			while (it != position + n - 1) {
				*it = *(it - n);
				it--;
			}
			while (first != last) {
				*position++ = *first++;
			}
			_size += n;
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

		iterator erase( iterator pos ) {
			iterator it = pos;
			if (it != end()) {
				while (it < end() - 1) {
					_allocator.destroy(*it);
					_allocator.construct(*it, *(it + 1));
					it++;
				}
				_allocator.destroy(*(it));
				--_size;
			}
			return pos;
		}

		iterator erase(iterator first, iterator last) {
			iterator it = last;
			if (it != end()) {
				while (first != last && it < end()) {
					_allocator.destroy(*first);
					_allocator.construct(*first, *it);
					it++;
					first++;
				}
				while (first != last) {
					_allocator.destroy(*first);
					first++;
				}
			}
			return first;
		}
	};
	//class end



	template <class T>
	void swap (ft::vector<T> &first, ft::vector<T> &second)
	{
		first.swap(second);
	}

}
#endif//VECTOR_HPP
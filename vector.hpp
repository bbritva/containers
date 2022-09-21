#ifndef VECTOR_HPP
# define VECTOR_HPP

# define BASIC_SIZE 10

# include <iostream>
# include "iterators.hpp"

namespace ft {
	template<typename T>
	class vector {
	private:
		T *_arr;
		std::size_t _capacity;
		std::size_t _size;
		std::allocator<T> _allocator;
	public:
		explicit vector(const std::allocator<T>& allocator = std::allocator<T>()) {
			_size = 0;
			_capacity = BASIC_SIZE;
			_allocator = allocator;
			_arr = _allocator.allocate(BASIC_SIZE);
		};

		explicit vector(std::size_t size, const std::allocator<T>& allocator = std::allocator<T>()) {
			size = (BASIC_SIZE > size) ? BASIC_SIZE : size;
			_capacity = size;
			_size = 0;
			_allocator = allocator;
			_arr = _allocator.allocate(size);
		};

		vector(vector const &other, const std::allocator<T>& allocator = std::allocator<T>()) {
			_allocator = allocator;
			_arr = _allocator.allocate(other._capacity);
			for (std::size_t i = 0; i < other._size; ++i)
				_arr[i] = other._arr[i];
			_capacity = other._capacity;
			_size = other._size;
		}

		~vector() {
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

		const std::allocator<T>& get_allocator() const {
			return _allocator;
		}

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

		std::size_t max_size() {
			return _allocator.max_size();
		}

		void reserve(std::size_t new_cap) {
			if (new_cap <= _capacity)
				return;
			T *new_arr = _allocator.allocate(new_cap);
			for (std::size_t i = 0; i < _size; ++i) {
				_allocator.construct(&new_arr[i], _arr[i]);
				_allocator.destroy(&_arr[i]);
			}
			_allocator.deallocate(_arr, _capacity);
			_capacity = new_cap;
			_arr = new_arr;
		}

		void resize(std::size_t count, T value = T()) {
			while (_size < count)
				push_back(value);
			while (_size > count)
				pop_back();
		}

		void push_back(T new_el) {
			if (_size + 1 >= _capacity)
				reserve(_capacity << 1);
			_allocator.construct(&_arr[_size++], new_el);
		}

		void pop_back() {
			_size--;
			_allocator.destroy(&_arr[_size]);
		}

		std::size_t size() {
			return (_size);
		}
		bool empty() const {
			return (_size == 0);
		}
		std::size_t capacity() {
			return (_capacity);
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

	};
	//class end

	template <class Category, class T>
	class iterator : public ft::iterator_base<ft::random_access_iterator_tag, T>
	{
		T* ptr;
	public:
		iterator(T* x) : ptr(x) {}
		iterator(const iterator& other) : ptr(other.p) {}
		iterator& operator++() {
			++ptr;
			return *this;
		}

		iterator operator++(int) {
			iterator tmp(*this);
			operator++();
			return tmp;
		}
		bool operator==(const iterator& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const iterator& other) const {
			return ptr != other.ptr;
		}
		T& operator*() {return *ptr;}
	};

	template <class T>
	void swap (ft::vector<T> &first, ft::vector<T> &second)
	{
		first.swap(second);
	}

}
#endif//VECTOR_HPP
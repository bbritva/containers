#ifndef VECTOR_HPP
# define VECTOR_HPP

# define BASIC_SIZE 10

# include <iostream>
# include "iterators.hpp"

namespace ft {

	template <class T>
	class random_access_iterator : public ft::iterator_base<ft::random_access_iterator_tag, T>
	{
		T* _pointer;
	public:
		random_access_iterator() : _pointer(NULL) {}
		explicit random_access_iterator(T* x) : _pointer(x) {}
		random_access_iterator(const random_access_iterator& other) : _pointer(other._pointer) {}
		random_access_iterator &operator=(const random_access_iterator &other) {
			if (this == &other)
				return (*this);
			_pointer = other._pointer;
			return (*this);
		}

		random_access_iterator& operator++() {
			++_pointer;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator tmp(*this);
			operator++();
			return tmp;
		}

		random_access_iterator operator+=(std::size_t step) {
			_pointer += step;
			return *this;
		}

		bool operator==(const random_access_iterator& other) const {
			return _pointer == other._pointer;
		}
		bool operator!=(const random_access_iterator& other) const {
			return _pointer != other._pointer;
		}
		T& operator*() {return *_pointer;}
	};

	template<typename T>
	class vector {
	public:
		typedef ft::random_access_iterator<T> iterator;

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

		// Iterators


		iterator begin() {
			return iterator(&_arr[0]);
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

		// TODO: shrink_to_fit ??

		// Modifiers

		// TODO: assign ??

		void push_back(T new_el) {
			if (_size + 1 >= _capacity)
				reserve(_capacity << 1);
			_allocator.construct(&_arr[_size++], new_el);
		}

		void pop_back() {
			_size--;
			_allocator.destroy(&_arr[_size]);
		}

		// TODO: insert ??
		// TODO: erase ??

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

		// TODO: emplace ??
		// TODO: emplace_back ??
	};
	//class end



	template <class T>
	void swap (ft::vector<T> &first, ft::vector<T> &second)
	{
		first.swap(second);
	}

}
#endif//VECTOR_HPP
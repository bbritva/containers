#ifndef VECTOR_HPP
# define VECTOR_HPP

# define BASIC_SIZE 10

# include <iostream>

namespace ft {
    template<typename T>
    class vector {
    private:
        T *_arr;
        unsigned int _size;
        unsigned int _index;
		std::allocator<T> _allocator;
    public:
        explicit vector(const std::allocator<T>& allocator = std::allocator<T>()) {
			_index = 0;
			_size = BASIC_SIZE;
			_allocator = allocator;
			_arr = _allocator.allocate(BASIC_SIZE);
		};

        explicit vector(unsigned int size, const std::allocator<T>& allocator = std::allocator<T>()) {
            size = (BASIC_SIZE > size) ? BASIC_SIZE : size;
            _size = size;
			_index = 0;
			_allocator = allocator;
			_arr = _allocator.allocate(size);
		};

        vector(vector const &other, const std::allocator<T>& allocator = std::allocator<T>()) {
			_allocator = allocator;
            _arr = _allocator.allocate(other._size);
            for (unsigned int i = 0; i < other._size; ++i)
                _arr[i] = other._arr[i];
            _size = other._size;
			_index = other._index;
        }

        ~vector() {
            _allocator.deallocate(_arr, _size);
        }

        vector &operator=(const vector &other) {
            if (this == &other)
                return (*this);
            if (_size < other._size) {
                _allocator.deallocate(_arr, _size);
                _arr = _allocator.allocate(other._size);
            }
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = other._arr[i];
            _size = other._size;
            return (*this);
        }

        T &operator[](unsigned int index) {
            if (index < _index)
                return _arr[index];
            throw std::exception();
        }

        void push_back(T new_el){
            if (_index + 1 >= _size)
            {
                T *new_arr = _allocator.allocate(_size << 1);
                for (unsigned int i = 0; i < _size; ++i) {
					_allocator.construct(&new_arr[i], _arr[i]);
                }
				_allocator.deallocate(_arr, _size);
				_size = _size << 1;
                _arr = new_arr;
            }
            _allocator.construct(&_arr[_index++], new_el);
        }

        void pop_back(){
			_index--;
			_allocator.destroy(&_arr[_index]);
        }

        unsigned int size() {
            return (_index);
        }
        unsigned int capacity() {
            return (_size);
        }

	};

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator
	{
	public:
		/* Type of elements pointed. */
		typedef T           value_type;

		/* Type to represent the difference between two iterators. */
		typedef Distance    difference_type;

		/* Type to represent a pointer to an element pointed */
		typedef Pointer     pointer;

		/* Type to represent a reference to an element pointed */
		typedef Reference   reference;

		/* Category of the iterator. */
		typedef Category    iterator_category;
	};

	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>{

	};
}
#endif//VECTOR_HPP
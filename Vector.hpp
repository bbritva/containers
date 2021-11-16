#ifndef VECTOR_HPP
# define VECTOR_HPP

# define BASIC_SIZE 100

# include <iostream>

namespace ft {
    template<typename T>
    class Vector {
    private:
        T *_arr;
        unsigned int _size;
        unsigned int _len;
    public:
        Vector() {
            _arr = new T[BASIC_SIZE];
            _len = 0;
            _size = BASIC_SIZE;
        };

        explicit Vector(unsigned int size) {
            size = (BASIC_SIZE > size) ? BASIC_SIZE : size;
            _arr = new T[size];
            _size = size;
            _len = 0;
        };

        Vector(Vector const &other) {
            _arr = new T[other._size];
            for (unsigned int i = 0; i < other._size; ++i)
                _arr[i] = other._arr[i];
            _size = other._size;
            _len = other.length();
        }

        ~Vector() {
            delete[] _arr;
        }

        Vector &operator=(const Vector &other) {
            if (this == &other)
                return (*this);
            if (_size < other.size()) {
                delete[] _arr;
                _arr = new T[other._size];
            }
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = other._arr[i];
            _size = other._size;
            return (*this);
        }

        T &operator[](unsigned int index) {
            if (index < _size)
                return _arr[index];
            throw std::exception();
        }

        void push_back(T new_el){
            _len++;
            if (_len > _size)
            {
                T *new_arr = new T[_size << 1];
                for (unsigned int i = 0; i < _size; ++i) {
                    new_arr[i] = _arr[i];
                }
                _size = _size << 1;
                delete[] _arr;
                _arr = new_arr;
            }
            _arr[_len] = new_el;
        }

        unsigned int size() {
            return (_size);
        }
        unsigned int length() {
            return (_len);
        }


    };
}
#endif//VECTOR_HPP
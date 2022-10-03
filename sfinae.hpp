//
// Created by grvelva on 9/27/22.
//

#ifndef CONTAINERS_SFINAE_HPP
#define CONTAINERS_SFINAE_HPP

namespace ft {

	template <bool B>
	struct enable_if {};

	template <>
	struct enable_if<true> { typedef int type; };

	template <typename T> struct is_integral {
		static const bool value = false;
	};

	template <> struct is_integral<bool> {
		static const bool value = true;
	};

	template <> struct is_integral<char> {
		static const bool value = true;
	};

	template <> struct is_integral<short> {
		static const bool value = true;
	};

	template <> struct is_integral<int> {
		static const bool value = true;
	};

	template <> struct is_integral<long> {
		static const bool value = true;
	};

	template <> struct is_integral<long long> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned char> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned short> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned int> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned long> {
		static const bool value = true;
	};

	template <> struct is_integral<unsigned long long> {
		static const bool value = true;
	};

	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type dist = 0;
		while (first++ != last)
			dist++;
		return dist;
	}

} // namespace ft

#endif //CONTAINERS_SFINAE_HPP

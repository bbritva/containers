//
// Created by grvelva on 9/18/22.
//

#ifndef CONTAINERS_ITERATOR_TRAITS_HPP
#define CONTAINERS_ITERATOR_TRAITS_HPP

namespace ft {

	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator
	{
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	template <class Category, class T>
	class MyIterator : public ft::iterator<random_access_iterator_tag, T>
	{
		T* p;
	public:
		MyIterator(T* x) :p(x) {}
		MyIterator(const MyIterator& mit) : p(mit.p) {}
		MyIterator& operator++() {++p;return *this;}
		MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
		bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
		bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
		int& operator*() {return *p;}
	};
}

#endif //CONTAINERS_ITERATOR_TRAITS_HPP

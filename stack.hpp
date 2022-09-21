//
// Created by grvelva on 9/14/22.
//

#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP

namespace ft {
	template<typename T, class Container = ft::vector<T> >
	class stack {
	private:
		Container _data;

	public:
		explicit stack(const Container& cont = Container()) : _data(cont){
		};

		T& top() {
			return _data.back();
		}

		bool empty() const {
			return _data.empty();
		}

		std::size_t size() const {
			return _data.size();
		}

		void push(const T element) {
			_data.push_back(element);
		}

		void pop() {
			_data.pop_back();
		}
	};
}

#endif //CONTAINERS_STACK_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:39:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/10/28 14:14:33 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <stack>
#include <stdexcept>
#include <string>

void check(bool condition, const char* message) {
	if (!condition)
		throw std::runtime_error(message);
	std::cout << "PASS: " << message << '\n';
}

int main() {
	try {
		MutantStack<int> stack;
		check(stack.empty() && stack.begin() == stack.end(),
			"default construction produces an empty range");

		// The stack operations are inherited from std::stack.
		stack.push(5);
		stack.push(17);
		check(stack.top() == 17 && stack.size() == 2,
			"push updates the top and size");
		stack.pop();
		check(stack.top() == 5 && stack.size() == 1,
			"pop removes the newest value");

		stack.push(3);
		stack.push(5);
		stack.push(737);
		stack.push(0);
		check(stack.size() == 5 && stack.top() == 0,
			"the demonstration stack contains five values");

		std::cout << "Bottom to top:";
		for (MutantStack<int>::iterator it = stack.begin();
				it != stack.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		// Four-iterator equal checks both the values and the range lengths.
		std::list<int> reference = {5, 3, 5, 737, 0};
		check(std::equal(stack.begin(), stack.end(),
				reference.begin(), reference.end()),
			"forward iteration matches the expected list");
		check(stack.size() == 5 && stack.top() == 0,
			"reading through iterators preserves the stack");

		// A const reference selects the const begin/end overloads.
		const MutantStack<int>& readOnly = stack;
		check(std::equal(readOnly.begin(), readOnly.end(),
				reference.cbegin(), reference.cend()),
			"const iteration reads the same sequence");
		const auto found = std::find(readOnly.begin(), readOnly.end(), 737);
		check(found != readOnly.end() && *found == 737,
			"std::find can search the const range");
		check(std::accumulate(readOnly.begin(), readOnly.end(), 0) == 750,
			"std::accumulate can sum the range");

		// A mutable iterator accesses the actual stored value.
		*stack.begin() = 42;
		reference.front() = 42;
		check(std::equal(stack.begin(), stack.end(),
				reference.begin(), reference.end())
				&& *readOnly.begin() == 42,
			"mutable iteration changes the underlying storage");

		MutantStack<int> copied(stack);
		MutantStack<int> assigned;
		assigned.push(-1);
		assigned = stack;
		check(std::equal(copied.begin(), copied.end(),
				stack.begin(), stack.end())
				&& std::equal(assigned.begin(), assigned.end(),
					stack.begin(), stack.end()),
			"copy construction and assignment copy the whole sequence");

		// Distinct changes must remain local to each object.
		stack.top() = 99;
		copied.pop();
		assigned.push(123);
		check(stack.size() == 5 && stack.top() == 99
				&& copied.size() == 4 && copied.top() == 737
				&& assigned.size() == 6 && assigned.top() == 123,
			"copies have independent storage");

		// The alias deliberately refers to the same object during assignment.
		MutantStack<int>& sameObject = assigned;
		assigned = sameObject;
		check(assigned.size() == 6 && assigned.top() == 123
				&& *assigned.begin() == 42,
			"self-assignment preserves the values");

		std::stack<int> ordinary(stack);
		ordinary.pop();
		check(ordinary.size() == 4 && ordinary.top() == 737
				&& stack.size() == 5 && stack.top() == 99,
			"an ordinary std::stack can copy the base state independently");

		while (!copied.empty())
			copied.pop();
		check(copied.begin() == copied.end(),
			"popping every value restores an empty range");
		const MutantStack<int>& emptyView = copied;
		check(emptyView.begin() == emptyView.end(),
			"const iteration also represents an empty range");

		// T is the element type: the class also works with strings.
		MutantStack<std::string> words;
		words.push("first");
		words.push("last");
		const MutantStack<std::string>& wordView = words;
		check(words.top() == "last" && *wordView.begin() == "first",
			"the template works with std::string elements");

		std::cout << "All MutantStack checks passed.\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Unexpected failure: " << e.what() << '\n';
		return 1;
	}
	return 0;
}

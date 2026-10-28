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
#include <stack>
#include <stdexcept>

int main() {
	try {
		// 1. Run the subject's stack and iterator example.
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "MutantStack:\n" << mstack.top() << '\n';
		mstack.pop();
		std::cout << mstack.size() << '\n';

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		if (it != mstack.begin())
			throw std::runtime_error("Iterator did not return to begin");
		while (it != ite) {
			std::cout << *it << '\n';
			++it;
		}

		// 2. Repeat the same operations with a list.
		std::list<int> reference;
		reference.push_back(5);
		reference.push_back(17);
		std::cout << "std::list:\n" << reference.back() << '\n';
		reference.pop_back();
		std::cout << reference.size() << '\n';

		reference.push_back(3);
		reference.push_back(5);
		reference.push_back(737);
		reference.push_back(0);
		for (std::list<int>::iterator lit = reference.begin();
				lit != reference.end(); ++lit)
			std::cout << *lit << '\n';

		if (!std::equal(mstack.begin(), mstack.end(),
				reference.begin(), reference.end()))
			throw std::runtime_error("Stack and list sequences differ");
		std::cout << "Iterator/list comparison passed.\n";

		// 3. Check copy construction and assignment on MutantStack itself.
		MutantStack<int> copied(mstack);
		MutantStack<int> assigned;
		assigned.push(-1);
		assigned = mstack;
		if (!std::equal(copied.begin(), copied.end(),
				mstack.begin(), mstack.end())
				|| !std::equal(assigned.begin(), assigned.end(),
					mstack.begin(), mstack.end()))
			throw std::runtime_error("Copy or assignment changed the sequence");

		copied.pop();
		assigned.top() = 99;
		if (mstack.size() != 5 || mstack.top() != 0
				|| copied.size() != 4 || copied.top() != 737
				|| assigned.size() != 5 || assigned.top() != 99)
			throw std::runtime_error("MutantStack copies are not independent");
		std::cout << "Copy construction and assignment passed.\n";

		// 4. Copy the base state into an ordinary stack, as in the subject.
		std::stack<int> ordinary(mstack);
		ordinary.pop();
		if (ordinary.size() != 4 || ordinary.top() != 737
				|| mstack.size() != 5 || mstack.top() != 0)
			throw std::runtime_error("The ordinary stack copy is not independent");
		std::cout << "Ordinary stack copy passed.\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << '\n';
		return 1;
	}
	return 0;
}

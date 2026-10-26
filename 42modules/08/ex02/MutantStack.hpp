/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:39:29 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/20 15:38:32 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	using container_type = typename std::stack<T>::container_type;
	using iterator = typename container_type::iterator;
	using const_iterator = typename container_type::const_iterator;

	MutantStack() = default;
	MutantStack(const MutantStack& copy) = default;
	MutantStack& operator=(const MutantStack& other) = default;
	~MutantStack() = default;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}
};

#endif

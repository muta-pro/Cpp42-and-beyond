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
			MutantStack() : std::stack<T>() {}
			MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
			MutantStack &operator=(const MutantStack &assign) {
				if (this != assign) {
					std::stack<T>::operator=(assign); }
					return *this;
			}
			~MutantStack() {}
	private:
};

#endif
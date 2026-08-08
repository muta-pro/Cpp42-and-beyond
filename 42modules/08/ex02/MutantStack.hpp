/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:39:29 by imutavdz          #+#    #+#             */
/*   Updated: 2026/08/08 19:29:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

class MutantStack {
	public:
			MutantStack();
			MutantStack(const MutantStack &copy);
			MutantStack &operator=(const MutantStack &assign);
			~MutantStack();
	private:
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:27:13 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/11 12:20:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
			Cat();
			Cat(const Cat &copy);
			Cat &operator=(const Cat &assign);
			~Cat();

			void makeSound() const;
			void setIdea(int indx, const std::string &idea);
			void getIdea(int indx) const;
	private:
			Brain* _brain; //composition - has-A relationship
			//holds a pointer to ideas
};

#endif
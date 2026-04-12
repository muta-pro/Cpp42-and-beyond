/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:24:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/09 18:16:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal &copy);
			WrongAnimal &operator=(const WrongAnimal &assign);
			~WrongAnimal();

			void makeSound() const;
			std::string getType() const;

	protected:
		std::string _type;
};
 
 #endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:50:05 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/23 17:53:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}


//pointer to memeber function
void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	//storing pointers in array
	void (Harl::*actions[4])();
	//assign for each index address of fucntion
	actions[0] = &Harl::debug;
	actions[1] = &Harl::info;
	actions[2] = &Harl::warning;
	actions[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << "Unknown complain level." << std::endl;
}

void Harl::debug(void)
{
	std::cout << "This is a debug message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "This is a info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is a WARNING message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is an error message" << std::endl;
}

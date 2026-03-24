/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:45:39 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/23 17:58:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}
//But here we want cascading behavior.
//use fallthrough: after executing the case, continue next
void Harl::warning(void)
{
	std::cout << "[WARNING]\n";
	std::cout << "This is a warning message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "This is an info message" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "This is a debug message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]\n";
	std::cout << "This is an error message" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "WARNING", "INFO", "ERROR"};
	void (Harl::*actions[4])() = {
		&Harl::debug,
		&Harl::warning,
		&Harl::info,
		&Harl::error
	};
	int i = 0;

	while (i < 4 && levels[i] != level)
		i++;

	switch (i)
	{
	case 0:
		(this->*actions[0])();
	case 1:
		(this->*actions[1])();
	case 2:
		(this->*actions[2])();
	case 3:
		(this->*actions[3])();
		break;
	default:
		std::cout << "[insignificant message]" << std::endl;
	}
}

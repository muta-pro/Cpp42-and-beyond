/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:50:05 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/21 20:44:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.h"

void (Harl::*actions[4])();

actions[0] = &Harl::debug;
actions[1] = &Harl::info;
actions[2] = &Harl::warning;
actions[3] = &Harl::error;

void (Harl::*)complain(std::string level)
{

}

void (Harl::*)debug(void)
{

}

void (Harl::*)info(void)
{

}

void (Harl::*)warning(void)
{

}

void (Harl::*)error(void)
{

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:45:39 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/23 17:40:56 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
// convert the string level → integer index, then use switch.
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Err. usage: ./harlFiler LEVEL\n";
		return (1);
	}
	Harl h;
	h.complain(argv[1]);
	return (0);
}
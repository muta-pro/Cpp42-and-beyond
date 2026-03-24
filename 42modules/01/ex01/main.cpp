/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:25:20 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/10 08:08:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 3;

	Zombie* z = zombieHorde(N, "Sauron");
	if (z == NULL)
	{
		std::cout << "invalid N input" << std::endl;
		return 1;
	}
	for(int i = 0; i < N; i++)
		z[i].announce();

	delete[] z;
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:52:07 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/27 17:58:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
	int i;
	size_t j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		std::string s(argv[i]);
		j = 0;
		while (j < s.size())
		{
			std::cout << (char)std::toupper((unsigned char)s[j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}

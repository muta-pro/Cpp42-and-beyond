/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:34:21 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/14 20:09:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceAll(const std::string &content,
						const std::string &s1,
						const std::string &s2)
{
	if (s1.empty())
		return content;
	std::string result;
	std::string::size_type pos = 0;
	std::string::size_type found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	return result;
}

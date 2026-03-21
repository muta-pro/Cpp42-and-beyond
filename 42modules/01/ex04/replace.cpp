/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 19:34:21 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/21 20:30:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
/*
Building a new modified string:
find next match
copy the text before the match
append replacement text
continue after the matched part
at the end, append whatever remains
passing reference to a string, avoid copy and no modification
so function reads content: read-only reference*/
std::string replaceAll(const std::string& content,
						const std::string& s1,
						const std::string& s2)
{
	if (s1.empty()) //important -empy string is at every pos.
		return content; //returns a string obj
	std::string result; //empty str for the output
	//defining type inside string class- return type of: find(), size()
	std::string::size_type pos = 0;
	std::string::size_type found;
	//assignment itself is an expression in C++. until not found
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();//returns num chars in s1
	}
	result += content.substr(pos);//after loop copy the rest
	return result;
}

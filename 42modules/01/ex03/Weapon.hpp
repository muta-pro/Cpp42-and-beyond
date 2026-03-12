/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:16:22 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/11 09:23:21 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#pragma once

class Weapon
{
public:
	Weapon(const std::string& type);
	~Weapon();
	
	const std::string& getType() const;
	void setType(const std::string& nType);
private:
	std::string type;
};

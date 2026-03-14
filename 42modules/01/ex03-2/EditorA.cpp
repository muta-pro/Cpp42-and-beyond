/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditorA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:31:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 17:20:43 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EditorA.hpp"
#include <iostream>

EditorA::EditorA(Document& doc, const std::string& name) : _doc(doc), _name(name) {};

EditorA::~EditorA() {};

void EditorA::review() const
{
	std::cout << _name << " reviews docs " << _doc.getTitle() << std::endl; 
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditorB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:31:46 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 17:20:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EditorB.hpp"
#include <iostream>

EditorB::EditorB(const std::string& name) : _doc(NULL), _name(name) {}

EditorB::~EditorB() {}
void EditorB::setDoc(Document& doc) {_doc = &doc;}

void EditorB::review() const
{
	if(!_doc)
		std::cout << _name << " no Document" << std::endl;
	else
		std::cout << _name << " has Document " << _doc->getTitle() << std::endl;
}

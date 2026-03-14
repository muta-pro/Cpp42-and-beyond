/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditorA.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:31:15 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 17:01:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITORA_HPP
#define EDITORA_HPP
#include "Document.hpp"

class EditorA
{
public:
	EditorA(Document& doc, const std::string& name);
	~EditorA();
	void review() const;

private:
	Document& _doc;
	std::string _name;	
};

#endif
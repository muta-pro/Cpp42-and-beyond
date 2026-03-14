/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EditorB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:31:32 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 17:05:48 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "Document.hpp"
#include <string>

class EditorB
{
public:
	EditorB(const std::string& name);
	~EditorB();
	void review() const;
	void setDoc(Document& doc);
private:
	Document* _doc;
	std::string _name;
};

#endif
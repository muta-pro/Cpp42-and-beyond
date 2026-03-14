/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Document.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:32:31 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 18:10:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Document.hpp"

Document::Document(const std::string& title) : _title(title) {}

Document::~Document() {}

const std::string& Document::getTitle() const 
	{return _title;}

void Document::setTitle (const std::string& title) {_title = title;}

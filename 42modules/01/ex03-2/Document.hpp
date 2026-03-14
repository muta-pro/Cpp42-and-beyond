/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Document.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:32:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 16:53:46 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#pragma once
#include <string>

class Document
{
public:
	Document(const std::string& title);
	~Document();
	const std::string& getTitle() const;
	void setTitle(const std::string& newTitle);

private:
	std::string _title;
};

#endif
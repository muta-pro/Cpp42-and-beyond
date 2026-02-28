/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:54:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/25 15:13:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();

	void run();
	void add();
	void search();

private:
	static const int _max_size = 8;
	Contact _contacts[_max_size]; //internal var: n contacts
	int _count;

	void append(const Contact &contact);
};

#endif
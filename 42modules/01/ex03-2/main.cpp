/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:32:52 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/12 19:26:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
alternative version for the ex03 for comprehensive purposes*/

#include "Document.hpp"
#include "EditorA.hpp"
#include "EditorB.hpp"

int main()
{
	{
		//allocate mem for report, call doc construct with "Draft 1"
		//Docuent::Document("Draft 1") and init private member _title with it
		Document report("Draft 1");
		//new obj creation and construct call assign doc and name
		EditorA Alice(report, "Alice");
		//method call of obj alice
		Alice.review();
		report.setTitle("Final report");
		Alice.review();
	}

	{
		Document notes("Notes");
		EditorB Bob("Bob");
		Bob.review();
		Bob.setDoc(notes);
		Bob.review();
		notes.setTitle("Updated notes");
		Bob.review();
	}
	return 0;
}

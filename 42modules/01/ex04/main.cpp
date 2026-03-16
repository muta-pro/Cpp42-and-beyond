/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:27:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/03/16 19:16:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"


int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <str1> <str2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];//managed string object
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (filename.empty())
	{
		std::cerr << "Err: empty filename" << std::endl;
		return 1;
	}
	if (s1.empty())//the object answers questions about itself
	{
		std::cerr << "Err: empty str1" << std::endl;
		return 1;
	}
	//constructing the object that tries opening a file
	// ifstream ~input file stream class - creates input file stream in
	std::ifstream in(filename.c_str()); //const char *c_str() const;
	//pr can use filename.data() ~ const char *data() const;
	//file stream constructors often expect a const char *, not a std::string
	if (!in)
	{
		std::cerr << "Err: could not open inp file" << std::endl;
		return 1;
	}
	std::string content;
	std::string line;
	while (std::getline(in, line))
	{
		content += line;
		if (!in.eof())
			content+= '\n';
	}
	if (in.bad())
	{
		std::cerr << "Err: failed reading file" << std::endl;
		return 1;
	}
	std::string replaced = replaceAll(content, s1, s2);
	std::ofstream out((filename + ".replace").c_str());
	if (!out)
	{
		std::cerr << "Err: file not created" << std::endl;
		return 1;
	}
	out << replaced;
	if (!out)
	{
		std::cerr << "Err: failed writing output file" << std::endl;
		return 1;
	}
	return 0;
}

/*So when you design tests, you are asking:

does it work in the normal case?
mala nisam
de a - overlaping behaviour
does it work if nothing matches?
x z 
does it work if the file is empty?
mala "" can work as deletion
does it work if arguments are wrong?

what if s2 is empty?
mala "" can work as deletion
what if s1 is empty?
"" x - error message - can match everywhere, 
can act as undefined behaviour*/
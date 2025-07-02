/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:53:42 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 17:37:33 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(std::string& currentLine, std::string& s1, std::string& s2)
{
	std::string output;
	size_t		pos = 0;
	size_t		found;

	while ((found = currentLine.find(s1, pos)) != std::string::npos){
		output += currentLine.substr(pos, found - pos);
		output += s2;
		pos = found + s1.length();
	}
	output += currentLine.substr(pos);
	return (output);
}

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Please, use the following format: ./ex04 <filename> s1 s2 \n";
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()){
		std::cerr << "s1 can't be empty. \n";
		return (1);
	}

	std::ifstream infile(filename.c_str());
	std::ofstream outfile((filename + ".replace").c_str());

	if (!infile.is_open()){
		std::cerr << "Error when opening: " << filename << "\nPlease, introduce a valid file\n";
		return (1);
	}

	if (!outfile.is_open()){
		std::cerr << "Error when opening: " << filename << ".replace" << "\nPlease, introduce a valid file\n";
		return (1);
	}

	std::string line;
	bool		needsNewline = false;
	
	while (std::getline(infile, line)){
		if (needsNewline)
			outfile << "\n";
		outfile << ft_replace(line, s1, s2);
		needsNewline = true;
	}

	infile.close();
	outfile.close();
	
	return (0);
}
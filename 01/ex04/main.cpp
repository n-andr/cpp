/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:21:10 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/07 01:35:03 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>



// sed = “stream editor”
// sed 's/<s1>/<s2>/g' <filename> > <filename>.replace
// forbiden to use std::string::replace


//std::ifstream input(path);  A C++ input file stream class. It owns the OS file descriptor and closes it automatically when the object is destroyed (RAII).

static bool readFile(const char *path, std::string& content){
	
	
	std::ifstream input(path); 
	
	if (!input){
		std::cerr << "Error opening file " << std::endl;
		return false;
	}

	std::string line;

	while (std::getline(input, line)) {
		content += line;
		if (!input.eof())
			content += '\n';
	}
	
	//input.close();
	return true;
}

// If the substring is found, you get its starting index (0, 1, 2, …).
// If it isn’t found, the function returns std::string::npos, a special constant meaning “no position”

//Function modifyes original string using reference to it (std::string &content)
static void replaceContent(std::string &content, const std::string &replaceThat, const std::string &replaceWith){

	std::size_t position = content.find(replaceThat);
	
	while (position != std::string::npos)
	{
		content.erase(position, replaceThat.length());
		content.insert(position, replaceWith);
		position += replaceWith.length();
		position = content.find(replaceThat, position);
	}
}

//c_str() - convert sting into const char*
static bool writeFile(const std::string& path, const std::string& content){
	std::ofstream output((path + ".replace").c_str());
	if (!output){
		std::cerr << "Error: output file.\n";
		return false;
	}
	output << content;
	return true;
	//output.close();
}

int main(int argc, char *argv[]){
	
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	// std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: <s1> is empty" << std::endl;
		return 1;
	}
	std::string content;
	
	if (!readFile(argv[1], content))
		return 1;
	replaceContent(content, s1, s2);
	if (!writeFile(argv[1], content)) 
		return 1;
	
	return 0;
}
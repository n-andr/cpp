/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:21:10 by nandreev          #+#    #+#             */
/*   Updated: 2025/05/07 00:52:08 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>



// sed = “stream editor”
// sed 's/<s1>/<s2>/g' <filename> > <filename>.replace
// forbiden to use std::string::replace


//std::ifstream input(path);  A C++ input file stream class. It owns the OS file descriptor and closes it automatically when the object is destroyed (RAII).

static std::string readFile(const char *path){
	
	
	std::ifstream input(path); 
	
	if (!input){
		std::cerr << "Error opening file " << std::endl;
		return std::string();
	}
	
	std::string line;
	std::string content;

	while (std::getline(input, line)) {
		content += line;
		if (!input.eof())
			content += '\n';
	}
	
	//input.close();
	return content;
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
	std::string fileContent = readFile(argv[1]);
	if (fileContent.empty())
		return 1;
	replaceContent(fileContent, s1, s2);
	if (!writeFile(argv[1], fileContent)) 
		return 1;
	
	return 0;
}
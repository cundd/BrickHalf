#include <iostream>
#include "MapParser.hpp"

int main(int argc, char ** argv)
{
	std::string inputString;
	char rowDelimiter = ';';
	char pairSeperator = '=';
	
	if (argc < 2) {
		std::getline(std::cin, inputString);
	} else {
		inputString = std::string(argv[1]);
	}

	if (inputString.empty()) {
		std::cerr << "Missing input string" << std::endl;
		return 1;
	}
	MapParser parser(rowDelimiter, pairSeperator);

	std::map<std::string, std::string> parsedMap = parser.parse(inputString);
	for (std::pair<std::string, std::string> pair : parsedMap) {
		std::cout << "'" << pair.first << "' '" << pair.second << "'" << std::endl;
	}
	std::cout << std::endl;
	return 0;
}


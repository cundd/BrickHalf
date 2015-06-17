#include <iostream>
#include "MapParser.hpp"

int main(int argc, char** argv)
{
    int i = 0;
	char rowDelimiter = ';';
    char pairSeperator = '=';

    std::string inputString;
    std::getline(std::cin, inputString);
    if (argc > 1) {
        do {
            std::string arg = std::string(argv[i]);

            // --delimiter
            // --separator
            if (!arg.compare(0, 2, "--")) {
                if (!arg.compare(0, 12, "--delimiter=")) {
                    rowDelimiter = *(arg.substr(12, 1).c_str());
                    // std::cout << rowDelimiter << std::endl;
                }
                if (!arg.compare(0, 12, "--separator=")) {
                    pairSeperator = *(arg.substr(12, 1).c_str());
                    // std::cout << pairSeperator << std::endl;
                }
            }
        } while (++i < argc);
    }

    if (inputString.empty()) {
        std::cerr << "Missing input string" << std::endl;
        
        std::cout << "Usage brickhalf [--seperator=\";\"] [--delimiter=\"=\"]" << std::endl;
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

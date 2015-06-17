#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

class MapParser {
    std::map<std::string, std::string> parameters;
    char rowDelimiter;
    char pairSeperator;

public:
    MapParser(char rowDelimiter, char pairSeperator)
        : rowDelimiter(rowDelimiter)
        , pairSeperator(pairSeperator)
    {
    }
    std::map<std::string, std::string>& parse(std::string input);

    std::vector<std::string> splitToVector(const std::string& string,
        char delimiter);

    std::pair<std::string, std::string> splitToPair(const std::string& rawPair,
        char delimiter);
};

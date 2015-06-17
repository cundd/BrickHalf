#include "MapParser.hpp"

std::pair<std::string, std::string> MapParser::splitToPair(
    const std::string& rawPair, char delimiter)
{
    size_t position = rawPair.find(delimiter);
    if (position != std::string::npos) {
        return std::make_pair(rawPair.substr(0, position),
            rawPair.substr(position + 1));
    }
    return std::make_pair(rawPair, "");
}

std::vector<std::string> MapParser::splitToVector(const std::string& string,
    char delimiter)
{
    std::stringstream stream(string);
    std::vector<std::string> parts;
    std::string currentPart;

    while (std::getline(stream, currentPart, delimiter)) {
        parts.push_back(currentPart);
    }
    return parts;
}

std::map<std::string, std::string>& MapParser::parse(std::string input)
{
    std::stringstream streamParser(input);
    std::vector<std::string> keyValuePairs = splitToVector(input, rowDelimiter);
    for (auto currentKeyValuePair : keyValuePairs) {
        // std::cout << currentKeyValuePair << std::endl;
        parameters.insert(splitToPair(currentKeyValuePair, pairSeperator));
    }
    return parameters;
}

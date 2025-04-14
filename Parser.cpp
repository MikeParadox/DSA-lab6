#include "Parser.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>



std::vector<std::string> Parser::split_line(const std::string& s,
                                            const std::regex& sep_regex)
{
    std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
    std::sregex_token_iterator end;
    return {iter, end};
}

Container Parser::parse(const std::string& path)
{
    Container temp;
    std::ifstream ist{path};
    if (!ist) throw std::runtime_error("Can't open file: " + path);

    std::string line;

    while (std::getline(ist, line))
    {
        auto line_words = split_line(line);

        std::for_each(line_words.begin(), line_words.end(),
                      [&temp](const auto& word) { ++temp[word]; });
    }

    return temp;
}




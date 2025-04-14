//
// Created by mikhail on 12/04/2025.
//

#ifndef LAB6_PARSER_H
#define LAB6_PARSER_H

#include <map>
#include <regex>
#include <string>
#include <vector>

// template<class T, class Compare=std::less<T>, class
// Allocator=std::allocator<T>>
using Container = std::map<std::string, unsigned>;


class Parser
{
public:
    explicit Parser(const std::string& path) : _cont{parse(path)} {}
    //    [[nodiscard]] const Container& container() const { return _cont; }

private:
    Container _cont;

    static Container parse(const std::string& path);
    static std::vector<std::string>
    split_line(const std::string& s,
               const std::regex& sep_regex = std::regex{"\\s+"});
};




#endif // LAB6_PARSER_H

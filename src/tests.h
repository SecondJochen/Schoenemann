#ifndef TESTS_H
#define TESTS_H

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "chess.hpp"

void testSEE(chess::Board &board);

inline void trim(std::string& str)
{
    const size_t first = str.find_first_not_of(" \t\n\r");
    const size_t last  = str.find_last_not_of(" \t\n\r");

    str = first == std::string::npos
        ? ""
        : str.substr(first, last - first + 1);
}

inline std::vector<std::string> splitString(const std::string& str, const char delimiter)
{
    std::vector<std::string> strSplit = { };
    std::stringstream ss(str);
    std::string token;

    while (getline(ss, token, delimiter))
    {
        trim(token);

        if (token != "")
            strSplit.push_back(token);
    }

    return strSplit;
}

#endif
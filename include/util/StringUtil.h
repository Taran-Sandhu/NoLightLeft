
#pragma once

#include <string>
#include <vector>

namespace util {

    std::string trim(const std::string& str);


    std::vector<std::string> split(const std::string& str, char delim);


    std::string toLower(const std::string& str);


    std::string toUpper(const std::string& str);
}
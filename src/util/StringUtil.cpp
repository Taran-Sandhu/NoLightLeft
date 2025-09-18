#include "util/StringUtil.h"
#include <algorithm>
#include <cctype>

namespace util {

    std::string trim(const std::string& str) {
        const auto strBegin = str.find_first_not_of(" \t\n\r");
        if (strBegin == std::string::npos) {
            return "";
        }
        const auto strEnd = str.find_last_not_of(" \t\n\r");
        return str.substr(strBegin, strEnd - strBegin + 1);
    }

    std::vector<std::string> split(const std::string& str, char delim) {
        std::vector<std::string> elems;
        std::string item;
        for (char ch : str) {
            if (ch == delim) {
                elems.push_back(item);
                item.clear();
            } else {
                item += ch;
            }
        }
        elems.push_back(item);
        return elems;
    }

    std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return result;
    }

    std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::toupper(c); });
        return result;
    }

}

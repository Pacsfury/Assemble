#include <cstring>
#include <string>

#include "startswith.hpp"

bool startswith(std::string a, std::string b) {
    if (a.size() < b.size() || (a == "" && b != "")) return false;
    if (a == b || b == "") return true;

    return std::memcmp(a.c_str(), b.c_str(), b.size()) == 0;
}
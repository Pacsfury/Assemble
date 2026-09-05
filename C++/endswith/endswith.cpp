#include <cstring>
#include <string>

#include "endswith.hpp"

bool endswith(std::string a, std::string b) {
    if (a.size() < b.size() || (a == "" && b != "")) return false;
    if (a == b || b == "") return true;

    const char* a_start = a.c_str() + (a.size() - b.size()); 
    
    return std::memcmp(a.c_str(), b.c_str(), b.size()) == 0;
}
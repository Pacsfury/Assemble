#include <string>

#include "before.hpp"

std::string before(const std::string& a, const std::string& b) {
    if (b.empty()) {
        return a;
    }

    if (a.find(b) != std::string::npos) {
        return a.substr(0, a.find(b));
    }

    return "";
}
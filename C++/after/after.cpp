#include <string>

#include "after.hpp"

std::string after(const std::string& a, const std::string& b) {
    if (b.empty()) {
        return a;
    }
    
    size_t max_j = 0;
    size_t j = 0;

    for (size_t i = 0; i < a.size(); i++) {
        j = 0;

        max_j = std::min(a.size() - i, b.size());

        while (j < max_j && a[i + j] == b[j]) {
            j++;
        }
        if (j == b.size()) {
            return a.substr(i + b.size());
        }
    }
    return "";
}

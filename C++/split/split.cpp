#include <string>
#include <vector>

#include "split.hpp"

std::vector<std::string> split(std::string text, char del, size_t max) {
    std::vector<std::string> res;
    if (text.empty()) return res;

    size_t expected_chunks = 1;
    size_t count_pos = text.find(del);
    while (count_pos != std::string::npos) {
        expected_chunks++;
        if (max > 0 && expected_chunks >= max) break;
        count_pos = text.find(del, count_pos + 1);
    }

    res.reserve(expected_chunks);

    std::string temp = "";
    size_t count = 0;

    for (size_t i = 0; i < text.length(); ++i) {
        char actual = text[i];

        if (actual == del && (max == 0 || count < max - 1)) {
            res.push_back(temp);
            temp = "";
            count++;
        } else {
            temp += actual;
        }
    }
    res.push_back(temp);

    return res;
}
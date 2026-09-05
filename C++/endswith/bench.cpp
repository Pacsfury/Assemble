#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cassert>

#include "endswith.hpp"

int main() {
    // 1. Accuracy Checks
    assert((endswith("a,b,c", "a,b")));
    assert((endswith("", "")));
    assert((!endswith("", "a")));
    assert((endswith("a", "a")));
    assert((!endswith("a", "aa")));
    std::cout << "Accuracy tests passed!\n";

    // 2. Time Benchmark
    std::string text = "menur283r ow98euismod,mszuixwazehoe8s nwm9xedus";
    std::string prefix = "s nwm9xedus";
    constexpr int iterations = 100'000;
    size_t total_elements = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        auto res = endswith(text, prefix);
        total_elements += res; // Prevents compiler optimization
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "Time: " << total_us << " us total (" 
              << (double)total_us / iterations << " us/op)\n";
              
    (void)total_elements; // Suppress unused variable warning
}
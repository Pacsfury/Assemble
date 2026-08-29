#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cassert>

#include "split.hpp"

int main() {
    // 1. Accuracy Checks
    assert((split("a,b,c", ',', 0) == std::vector<std::string>{"a", "b", "c"}));
    assert((split("a,b,c", ',', 2) == std::vector<std::string>{"a", "b,c"}));
    assert((split("", ',', 0).empty()));
    std::cout << "Accuracy tests passed!\n";

    // 2. Time Benchmark
    std::string text = "apple,banana,orange,grape,mango,pineapple,strawberry,blueberry";
    constexpr int iterations = 100'000;
    size_t total_elements = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        auto res = split(text, ',', 0);
        total_elements += res.size(); // Prevents compiler optimization
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "Time: " << total_us << " us total (" 
              << (double)total_us / iterations << " us/op)\n";
              
    (void)total_elements; // Suppress unused variable warning
}
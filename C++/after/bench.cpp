#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cassert>

#include "after.hpp"

int main() {
    // 1. Accuracy Checks
    assert((after("a,b,c", "a,b") == ",c"));
    assert((after("gvsiuhf", "siu") == "hf"));
    assert((after("rcwn389", "38") == "9"));
    assert((after("xmo4oxmu98", "mu") == "98"));
    assert((after("2qocwyrn8ixs", "yr") == "n8ixs"));
    std::cout << "Accuracy tests passed!\n";

    // 2. Time Benchmark
    std::string text = "hello, world mtujwxofm";
    std::string prefix = "rld mtu";
    constexpr int iterations = 100'000;
    size_t total_elements = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        auto res = after(text, prefix);
        total_elements += res.size(); // Prevents compiler optimization
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "Time: " << total_us << " us total (" 
              << (double)total_us / iterations << " us/op)\n";
              
    (void)total_elements; // Suppress unused variable warning
}
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cassert>

#include "before.hpp"

int main() {
    // 1. Accuracy Checks
    assert((before("a,b,c", "a,b") == ""));
    assert((before("gvsiuhf", "siu") == "gv"));
    assert((before("rcwn389", "38") == "rcwn"));
    assert((before("xmo4oxmu98", "mu") == "xmo4ox"));
    assert((before("2qocwyrn8ixs", "yr") == "2qocw"));
    std::cout << "Accuracy tests passed!\n";

    // 2. Time Benchmark
    std::string text = "hello, world mtujwxofm";
    std::string prefix = "rld mtu";
    constexpr int iterations = 100'000;
    size_t total_elements = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        auto res = before(text, prefix);
        total_elements += res.size(); // Prevents compiler optimization
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << "Time: " << total_us << " us total (" 
              << (double)total_us / iterations << " us/op)\n";
              
    (void)total_elements; // Suppress unused variable warning
}
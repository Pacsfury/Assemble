# CPP::split
---

Provides a split function:
```c++
std::vector<std::string> split(const std::string& text, char del, size_t max);
```

The benchmark is designed to avoid compiler optimizations.

It has been executed using the `AUTOPY.json` file included here (only cl version available: please send your gcc or clang version in a PR).

## Benchmarks
**No optimizations** _cl *.cpp /EHsc /std:c++17_

```
Accuracy tests passed!
Time: 128664 us total (1.28664 us/op)
```

**Optimization** _cl *.cpp /EHsc /O2 /std:c++17_

```
Accuracy tests passed!
Time: 36999 us total (0.36999 us/op)
```

In both versions the same benchmark has been used.
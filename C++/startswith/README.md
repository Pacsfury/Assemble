# CPP::startswith
---

Provides a startswith function:
```c++
bool startswith(const std::string& a, const std::string& b);
```

The benchmark is designed to avoid compiler optimizations.

It has been executed using the `AUTOPY.json` file included here (only cl version available: please send your gcc or clang version in a PR).

## Benchmarks
**No optimizations** _cl *.cpp /EHsc /std:c++17_

```
Accuracy tests passed!
Time: 12134 us total (0.12134 us/op)
```

**Optimization** _cl *.cpp /EHsc /O2 /std:c++17_

```
Accuracy tests passed!
Time: 873 us total (0.00873 us/op)
```

In both versions the same benchmark has been used.
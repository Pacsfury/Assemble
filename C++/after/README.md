# CPP::after
---

Provides a after function:
```c++
std::string after(const std::string& a, const std::string& b);
```

The benchmark is designed to avoid compiler optimizations.

It has been executed using the `AUTOPY.json` file included here (only cl version available: please send your gcc or clang version in a PR).

## Benchmarks
**No optimizations** _cl *.cpp /EHsc /std:c++17_

```
Accuracy tests passed!
Time: 21623 us total (0.21623 us/op)
```

**Optimization** _cl *.cpp /EHsc /O2 /std:c++17_

```
Accuracy tests passed!
Time: 2109 us total (0.02109 us/op)
```

In both versions the same benchmark has been used.
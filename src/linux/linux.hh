#if defined(__linux__)
#include <print>
inline void greet() { std::print("hello from linux"); }
#endif

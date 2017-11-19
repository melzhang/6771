//const a;         // value can't change
// constexpr b = 1; // evaluated at compile time

#include <iostream>

template <typename T>
T min(T a, T b) { return a < b ? a : b; }

int main() {
   const char *s = "zyx";
   const char *t = "abc";
   std::cout << min(s,t) << std::endl;
   // prints zyx
}
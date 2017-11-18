#include <iostream>
#include <string>

int main() {
   int ia[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
   };

   // for (int (*p)[4] = ia; p != ia + 3; ++p) {
   //    for (int *q = *p; q != *p + 4; ++q) {
   //       std::cout << *q << ' ';
   //    }
   //    std::cout << '\n';
   // }

   for (auto p = ia; p != ia + 3; ++p) {
      for (auto q = *p; q != *p + 4; ++q) {
         std::cout << *q << ' ';
      }
      std::cout << '\n';
   }

   // range based loop:
   std::string s("hello!");
   for (auto &c : s) {
      c = std::toupper(c);
   }
   std::cout << s << '\n';

   // function templates
   template <typename T>
   T min(T a, T b) {
      return a < b ? a : b;
   }

}
#include <iostream>

namespace cs6771 {
   void order3(int *a, int *b, int *c) {
      if (*a < *c) {
         int t = *a;
         *a = *c;
         *c = t;
      }
      if (*a < *b) {
         int t = *a;
         *a = *b;
         *b = t;
      }
      if (*b < *c) {
         int t = *b;
         *b = *c;
         *c = t;
      }
   }

   void order3(unsigned int& a, unsigned int& b, unsigned int& c) {
      if (a > c) {
         int t = a;
         a = c;
         c = t;
      }
      if (b > c) {
         int t = b;
         b = c;
         c = t;
      }
      if (a > b) {
         int t = a;
         a = b;
         b = t;
      }
   }
}

int main(int argc, char* argv[]) {
   std::cout << "Enter three integers: ";
   int a, b, c;
   std::cin >> a >> b >> c;
   std::cout << "Your numbers are: " << a << " " << b << " " << c << "\n";
   cs6771::order3(&a, &b, &c);
   std::cout << "In descending order: " << a << " " << b << " " << c << "\n";
   unsigned int d, e, f;
   d = a;
   e = b;
   f = c;
   cs6771::order3(d, e, f);
   std::cout << "In ascending order: " << d << " " << e << " " << f << "\n";
}
// Problem: Write a program (or function) to find if any value in this vector is in the range 5 to 10.

#include <vector>
#include <iostream>

// function object
class Range{
public:
   Range(int l, int u) : lb(l), ub(u) { }
   bool operator() (int val) {
      return (val >= lb && val <= ub);
   };
private:
   int lb, ub;
};

// template function object
template <class T, T lb, T ub>
struct Range2 {
   bool operator() (T val) {
      return (val >= lb && val <= ub);
   }
};

// function
bool range5to10(int val) {
   return (val >= 5 && val <= 10);
}

// function pointer
bool (*pf)(int) = range5to10;

void f(int a, int b, int c) {
   std::cout << a << " " << b << " " << c << "\n";
}

int main() {
   std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};

   auto range = [](auto &a){ return (a >= 5 && a <= 10); };

   auto result = std::find_if(vec.begin(), vec.end(), Range{5, 10});   
   auto result2 = std::find_if(vec.begin(), vec.end(), range5to10);
   auto result3 = std::find_if(vec.begin(), vec.end(), pf);
   auto result4 = std::find_if(vec.begin(), vec.end(), range);
   auto result5 = std::find_if(vec.begin(), vec.end(), Range2<int, 5, 10>{});

   if (result != vec.end()) {
      std::cout << *result << "\n";
      std::cout << *result2 << "\n";
      std::cout << *result3 << "\n";
      std::cout << *result4 << "\n";
      std::cout << *result5 << "\n";
   }

   // bind switches order of function args
   auto g1 = std::bind(f, std::placeholders::_2, std::placeholders::_1, 100);
   g1(3, 1); // prints 1 3 100
}
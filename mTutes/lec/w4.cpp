// Problem: Write a program (or function) to find if any value in this vector is in the range 5 to 10.

#include <vector>
#include <iostream>

class Range{
public:
   Range(int l, int u) : lb(l), ub(u) { }
   bool operator() (int val) {
      return (val >= lb && val <= ub);
   };
private:
   int lb, ub;
};

bool range5to10(int val) {
   return (val >= 5 && val <= 10);
}

// function pointer
bool (*pf)(int) = range5to10;

int main() {
   std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};

   auto range = [](auto a){ return (a >= 5 && a <= 10); };

   auto result = std::find_if(vec.begin(), vec.end(), Range{5, 10});   
   auto result2 = std::find_if(vec.begin(), vec.end(), range5to10);
   auto result3 = std::find_if(vec.begin(), vec.end(), pf);
   auto result4 = std::find_if(vec.begin(), vec.end(), range);

   if (result != vec.end()) {
      std::cout << *result << "\n";
      std::cout << *result2 << "\n";
      std::cout << *result3 << "\n";
      std::cout << *result4 << "\n";
   }
}
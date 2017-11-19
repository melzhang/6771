#include <iostream>
#include <vector>

template <typename T>
bool printIfWholeNumber(const T&) {
   return false;
}

template <> 
bool printIfWholeNumber<int>(const int& i) {
   std::cout << i;
   return true;
}

// What will this template do if it is given a std::string, a double, or a EuclideanVector?
// return false
// What will this template do if it is given an int?
// print int, return true
// What will this template do if it is given a long?
// return false

template <typename T>
unsigned int printAndCountWholeNumbers(const T& d) {
   if (printIfWholeNumber(d)) {
      std::cout << " ";
      return 1;
   }
   return 0;
}

// What will this template do if it is given a std::string, a double, or a EuclideanVector?
// return false
// What will this template do if it is given an int?
// return true, print int + ' '
// What will this template do if it is given a long?
// return false

template <typename T, typename... U>
unsigned int printAndCountWholeNumbers(T head, U... tail) {
   // call a function to work out if the "head" is a whole number
   bool wHead = printAndCountWholeNumbers(head);
   // call a function to process the tail
   int wTail = printAndCountWholeNumbers(tail...);
   // return the number of whole numbers in the variadic parameters
   return wHead + wTail;
}

template <typename T>
unsigned int printAndCountWholeNumbers(const std::vector<T>& vd) {
   unsigned int count = 0;
   for (auto d : vd) {
      auto dCopy = d;
      // work out if d is a whole number
      dCopy -= static_cast<int>(d);
      if (dCopy == 0) {
         // call: printIfWholeNumber
         printIfWholeNumber(static_cast<int>(d));
         std::cout << " ";
         // and add to count.
         count++;
      }
   }
   return count;
}

int main() {
   // double a = 3.0;
   // long b = 2132;
   // int c = 1;
   // printIfWholeNumber(a);
   // printIfWholeNumber(b);
   // printIfWholeNumber(c);
   // printAndCountWholeNumbers(a);

   auto c = printAndCountWholeNumbers(1, 2.5, 3, 4.5, 5.5, 6, 7.0, -5, "2" );
   std::cout << "count = " << c << std::endl;
   // The numbers 1 3 6 -5 should be printed out. Why is the number 7 not printed? Why is the number 2 not printed? 7.0 is a double, "2" is a string

   std::vector<double> d = {1.2, 32.0, 3.2, 5.30, 5.4, 6, -5};
   auto dc = printAndCountWholeNumbers(d);
   std::cout << "count = " << dc << std::endl;

   std::vector<unsigned int> vui = {65, 343, 21, 3};
   dc = printAndCountWholeNumbers(vui);
   std::cout << "count = " << dc << std::endl;

   // This code will compile and run, but it won't print out the correct number of whole numbers in either vector. Why?
   // because 32.0 was static cast to an int



}




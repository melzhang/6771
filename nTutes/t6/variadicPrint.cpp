#include <iostream>
#include <string>
#include <vector>

// Q: What will this template do if it is given a std::string, a double, or a EuclideanVector?
// A: return false
// Q: What will this template do if it is given an int?
// A: return true
// Q: What will this template do if it is given a long?
// A: return false

template <typename T>
bool printIfWholeNumber(const T&) {
  return false;
}

template <>
bool printIfWholeNumber(const int& i) {
  std::cout << i;
  return true;
}

// Q: What will this template do if it is given a std::string, a double, or a EuclideanVector?
// Q: What will this template do if it is given an int?
// Q: What will this template do if it is given a long?
// A: for int, will printIfWholeNumber, and " " and returns 1, otherwise returns 0
template <typename T>
unsigned int printAndCountWholeNumbers(const T& d) {
  if (printIfWholeNumber(d)) {
    std::cout << " ";
    return 1;
  }
  return 0;
}

// Use the following code to write a recursive variadic template function to print the whole numbers in a variable number of parameters:
template <typename T, typename... U>
unsigned int printAndCountWholeNumbers(T head, U... tail) {
  // call a function to work out if the "head" is a whole number
  // call a function to process the tail
  // return the number of whole numbers in the variadic parameters
  return printAndCountWholeNumbers(head) + printAndCountWholeNumbers(tail...);
}

// vector variadicPrint
template <typename T>
unsigned int printAndCountWholeNumbers(const std::vector<T>& vd) {
  unsigned int count = 0;
  for (auto d : vd) {
    auto dCopy = d;
    // check if int
    dCopy -= static_cast<int>(d);
    if (dCopy == 0) {
      printIfWholeNumber(d);
      count += 1;
    }
  }
  return count;
}

int main() {
  std::string s1 = "test string";
  printIfWholeNumber(s1);
  printAndCountWholeNumbers(s1);

  double d1 = 12.13;
  printIfWholeNumber(d1);
  printAndCountWholeNumbers(d1);

  long l1 = 1234;
  printIfWholeNumber(l1);
  printAndCountWholeNumbers(l1);

  int i1 = 1234;
  printIfWholeNumber(i1);
  printAndCountWholeNumbers(i1);
  std::cout << "== testing recursive ==" << '\n';

  auto c = printAndCountWholeNumbers(1, 2.5, 3, 4.5, 5.5, 6, 7.0, -5, "2" );
  std::cout << "count = " << c << std::endl;
  // Q: The numbers 1 3 6 -5 should be printed out. Why is the number 7 not printed? Why is the number 2 not printed?
  // A:  7 is formated as a float/double, 2 is a string

  // Q: This code will compile and run, but it won't print out the correct number of whole numbers in either vector. Why?
  // A: no case that handles vectors
  std::cout << "== vectors ==" << '\n';
  std::vector<double> d = {1.2, 32.0, 3.2, 5.30, 5.4, 6, -5};
  auto dc = printAndCountWholeNumbers(d);
  std::cout << "count = " << dc << std::endl;

  std::vector<unsigned int> vui = {65, 343, 21, 3};
  dc = printAndCountWholeNumbers(vui);
  std::cout << "count = " << dc << std::endl;

  return 0;
}

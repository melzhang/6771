// Create a main function that creates a std::vector<book>, add a few Book objects into the vector with different isbn numbers and prices

#include "Book.hpp"
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
   std::vector<Book> v;
   Book b{"a", "w", 231, 12.12};
   Book b1{"b", "w", 421, 412.11};
   Book b2{"c", "w", 2, 94.1};
   Book b3{"c", "w", 2, 94.1};

   v.push_back(b);
   v.push_back(b1);
   v.push_back(b2);

   if (b == b1) {
      std::cout << "they equal!"  << "\n";
   } else if (b2 == b3) {
      std::cout << "joke, these equal!"  << "\n";   
   }

   for(auto i : v) {
      std::cout << i;
   }
   std::cout << "\n";


   std::sort(v.begin(), v.end());

   for(auto i : v) {
      std::cout << i;
   }
   std::cout << "\n";

   // Call std::sort again with a lamda function as the predicate that sorts the books by price.
   std::sort(v.begin(), v.end(), [](const Book &b1, const Book &b2) {
      return (b1.getPrice() < b2.getPrice());
   });

   for(auto i : v) {
      std::cout << i;
   }
   std::cout << "\n";
}
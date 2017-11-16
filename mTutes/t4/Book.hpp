#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>

class Book {
public:

   friend bool operator==(const Book&, const Book&);
   friend std::ostream& operator<<(std::ostream&, const Book&);
   friend bool operator<(const Book&, const Book&);

   // Write the function definition for a constructor that takes values for name, author, isbn and price and uses a member initializer list to set the value of each data member.
   Book() : Book{"The Book", "The Writer", 1234, 1.00} {};
   Book(std::string n, std::string auth, int i, double p) : name{n}, author{auth}, isbn{i}, price{p} {};

   operator std::string() const;

  // getters
  int getIsbn() const { return isbn; }
  double getPrice() const  { return price; }
private:
  std::string name;
  std::string author;
  int isbn;
  double price;
};

#endif
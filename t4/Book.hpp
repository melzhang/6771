#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
public:
  // constructor that takes values for name, author, isbn and price and uses a member initializer list to set the value of each data member.
  Book();
  Book(const std::string name, const std::string author, const int isbn, const double price):
    name{name}, author{author}, isbn{isbn}, price{price} {}

  friend bool operator==(const Book& lhs, const Book& rhs);
  friend bool operator!=(const Book& lhs, const Book& rhs);
  friend bool operator<(const Book& lhs, const Book& rhs);
  friend std::ostream& operator<<(std::ostream& out, const Book& book);
  // conversion
  operator std::string() const;

  // getters
  int getIsbn() const { return isbn; }
  double getPrice() const { return price; }

private:
  std::string name;
  std::string author;
  int isbn;
  double price;

};

#endif

#include "Book.hpp"

bool operator==(const Book& lhs, const Book& rhs) {
  return (
    lhs.name == rhs.name
    && lhs.author == rhs.author
    && lhs.isbn == rhs.isbn
    && lhs.price == rhs.price
  );
}

bool operator!=(const Book& lhs, const Book& rhs) {
  return !(lhs == rhs);
}

bool operator<(const Book& lhs, const Book& rhs) {
  return (lhs.isbn < rhs.isbn);
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
  return (
    out << "name: " << book.name << '\n'
    << "author: " << book.author << '\n'
    << "isbn: " << book.isbn << '\n'
    << "price: " << book.price << '\n'
  );
}

// string conversion
Book::operator std::string() const {
  std::string tmp = author;
  tmp += ",";
  tmp += name;
  return tmp;
}

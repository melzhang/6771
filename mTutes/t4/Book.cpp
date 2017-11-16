#include "Book.hpp"

// Write the overloaded == operator to compare if two book objects are identical
bool operator==(const Book& b1, const Book& b2) {
   return (b1.name == b2.name && 
           b1.author == b2.author && 
           b1.isbn == b2.isbn && 
           b1.price == b2.price);
}


// Write the overloaded << operator to print out the name, author, isbn and price of a book using std::cout
std::ostream& operator<<(std::ostream& os, const Book& b) {
   os << "name: " << b.name << " " 
      << " author: " << b.author << " " 
      << " isbn: " << b.isbn << " "
      << " price: " << b.price << "\n";
   return os;
}

// Write the overloaded < operator to allow you to sort books by their isbn number. Test this in your main method using std::sort
bool operator<(const Book& b1, const Book& b2) {
   return (b1.isbn < b2.isbn);
}


// Write the overloaded type conversion operator to enable the conversion of the Book class to a std::string in the form of "author, name"
Book::operator std::string() const {
   std::string n;
   n.append(this->author).append(", ").append(this->name);
   return n;
}



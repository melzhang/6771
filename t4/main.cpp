#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Book.hpp"


int main() {

  // testing Trut false overloading operators
  Book b1{"bName", "bAuth", 1234, 10.99};
  Book b2{"bName", "bAuth", 1234, 10.99};
  Book b3{"bbName", "bAuth", 1234, 10.99};

  std::cout << (b1 == b2 ? "true" : "false") << '\n';
  std::cout << (b1 == b3 ? "true" : "false") << '\n';

  // test == operator
  std::cout << b1 << '\n';
  std::cout << b2 << '\n';
  std::cout << b3 << '\n';

  // test to string conversion
  std::cout << static_cast<std::string>(b1) << '\n';

  // testing sorting
  Book a1{"t1", "t1", 1234, 10.99};
  Book a2{"t2", "t1", 4234, 10.99};
  Book a3{"t3", "t1", 34, 10.99};
  Book a4{"t4", "t1", 51234, 10.99};
  std::vector<Book> v{a1, a2, a3, a4};

  std::cout << "== print curr order ==" << '\n';
  for (auto& i: v) {
    std::cout << i << '\n';
  }

  std::sort(v.begin(), v.end());
  std::cout << "== print sorted order ==" << '\n';
  for (auto& i: v) {
    std::cout << i << '\n';
  }

  // testing lambda function
  Book c1{"t1", "t1", 1234, 10.99};
  Book c2{"t2", "t1", 4234, 1.99};
  Book c3{"t3", "t1", 34, 90.99};
  Book c4{"t4", "t1", 51234, 30.99};
  std::vector<Book> v2{c1, c2, c3, c4};
  // anon function
  std::cout << "== sort by price ==" << '\n';

  // ===== inline lambda
  /*
  std::sort(v2.begin(), v2.end(),
    [](Book& lhs, Book& rhs) {
      return (lhs.getPrice() < rhs.getPrice());
    }
  );
  */
  // === end

  // defined lambda
  // capture list [], is grabs out of scope variables, since lambda funcs, are self-contained
  // [=], automatically find vars to the capture list (by rValue) [&] capture by ref
  auto sortByPrice = [](Book& lhs, Book& rhs) {
    return (lhs.getPrice() < rhs.getPrice());
  };
  // I personally like to define lambda functions
  std::sort(v2.begin(), v2.end(), sortByPrice);

  for (auto& i: v2) {
    std::cout << i << '\n';
  }

  return 0;
};

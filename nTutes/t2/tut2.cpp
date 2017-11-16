#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

int main() {
  std::vector<std::string> v{"one", "two", "three"};
  // auto - local copy, auto & shared var, auto && read-only
  // use auto& when you want to alter
  std::cout << "==vector==" << '\n';
  for (auto item: v) {
    std::cout << "item: " << item << '\n';
  }

  std::cout << "==array==" << '\n';
  std::array<std::string, 3> s = {{ std::string("one"), "two", "three" }};
  for (auto item: s) {
    std::cout << "item: " << item << '\n';
  }

  std::sort(v.begin(), v.end());
  std::sort(s.begin(), s.end());
  std::cout << "==sorted vector==" << '\n';
  for (auto item: v) {
    std::cout << "item: " << item << '\n';
  }
  std::cout << "==sorted array==" << '\n';
  for (auto item: s) {
    std::cout << "item: " << item << '\n';
  }
  // how are vetors diff from arr, vect = resizable

  // list
  std::list<int> l{12,33,2,43,65,57,9,76};
  std::cout << "==list==" << '\n';
  for (auto item: l) {
    std::cout << "item: " << item << '\n';
  }
  // has it's own sort member function
  l.sort();
  std::cout << "==sorted list==" << '\n';
  for (auto item: l) {
    std::cout << "item: " << item << '\n';
  }

  // mapping
  std::map<std::string, int> m;
  // create pairing from vector
  for (unsigned int i = 0; i < v.size(); i++) {
    auto item = std::pair<std::string, int>(v.at(i), i);
    m.insert(item);
  }

  std::cout << "==map==" << '\n';
  for (auto p : m) {
    std::cout << p.first << " " << p.second << std::endl;
  }

}

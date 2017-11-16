#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>
#include <map>
#include <utility>

int main() {
   std::vector<std::string> v = {"one", "two", "three"};
   std::array<int, 3> a { {3, 2, 1} };
   std::sort(v.begin(), v.end());
   std::sort(a.begin(), a.end());
   std::list<int> l;
   std::back_insert_iterator<std::list<int>> iter(l);
   
   for (auto &i : a) {
      *iter++ = i;
   }

   l.sort();

   std::map<std::string, int> m;

   int temp = 0;
   for (auto &i : v) {
      m.insert(std::make_pair(i, temp++));
   }

   for (auto &i : m) {
      std::cout << std::get<0>(i) << " " << std::get<1>(i) << "\n";
   }

}
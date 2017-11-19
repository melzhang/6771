#include <memory>
#include <iostream>

template <typename T>
std::unique_ptr<T> make_unique(T t) {
   return std::unique_ptr<T>(new T(t));
}

template <typename T>
std::unique_ptr<T> make_unique(std::unique_ptr<T>& up) {
   // TODO: create a copy of the ptr data.
   auto copy = *up;
   return make_unique(copy);
   // note the unique_ptr is passed by reference
} 

template <typename T>
T getBase(T t) {
   return t;
}

template <typename T>
auto getBase(T *t) -> decltype(*t) {
   return *t;
}
// these functions get the value of the variable T

template <typename T>
auto getBase(std::unique_ptr<T>& t) {
   return *t;
}

int main() {
   auto dptr = make_unique(3.14);
   std::cout << *dptr << std::endl;
   auto dptr2 = make_unique(dptr);
   std::cout << *dptr2 << std::endl;
   // Can't copy construct a unique_ptr because unique pointers own the obj they point to, this obj can't be owned by 2 unique_ptrs

   int i = 9;
   int* iptr = &i;
   std::cout << getBase(i) << std::endl;
   std::cout << getBase(iptr) << std::endl;
   std::cout << getBase(dptr) << std::endl;
   // doesn't compile because there is no template for getBase for a unique ptr

}
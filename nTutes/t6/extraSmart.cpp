#include <iostream>
#include <memory>

// This function will create a copy of the data passed into it on the heap and return a unique_ptr object around the data.
template <typename T>
std::unique_ptr<T> make_unique(T t) {
	return std::unique_ptr<T>(new T(t));
}

// copy a ptr of data, need to deref then recast
template <typename T>
std::unique_ptr<T> make_unique(std::unique_ptr<T>& up) {
	return make_unique(*up);
}

template <typename T>
T getBase(T t) {
	return t;
}

template <typename T>
auto getBase(T *t) -> decltype(*t) {
	return *t;
}

template <typename T>
auto getBase(std::unique_ptr<T>& t) -> decltype(*t) {
	return *t;
}

int main() {

  auto dptr = make_unique(3.14);
  std::cout << *dptr << std::endl;

  // fails because unique_ptr
  auto dptr2 = make_unique(dptr);
  std::cout << *dptr2 << std::endl;

  // Q: what do these do?
  int i = 9;
  int* iptr = &i;
  std::cout << getBase(i) << std::endl;
  std::cout << getBase(iptr) << std::endl;

  // doesn't pass compiler, need to have smart ptr variationd
  std::cout << getBase(dptr) << std::endl;

  return 0;
}

template <typename T>
bool printIfWholeNumber(const T&) {
   return false;
}

template <> 
bool printIfWholeNumber<int>(const int& i) {
   std::cout << i;
   return true;
}
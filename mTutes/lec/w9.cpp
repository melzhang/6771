#include <iostream>
#include <thread>
#include <mutex>

// int main() {
//    int numIterations = 10;
   
//    auto lamdaFunc = [numIterations]() {
//       for (int i = 0; i < numIterations; ++i) {
//             std::cout << "Thread id: " << std::this_thread::get_id();
//             std::cout << " value = " << i << std::endl;
//       };
//    };

//    std::thread t1{lamdaFunc};
//    numIterations = 5;
//    std::thread t2{lamdaFunc};

//    t1.join();
//    t2.join();
// }

// std::recursive_mutex - if code recursively tries to lock same mutex

int main() {
   int i = 1;
   const long numIterations = 1000000;
   std::mutex iMutex;
   std::thread t1([&] {
      for (int j = 0; j < numIterations; ++j) {
         std::lock_guard<std::mutex> guard(iMutex);
         i++;
      } 
   });
   
   std::thread t2([&] {
      for (int j = 0; j < numIterations; ++j) {
         std::lock_guard<std::mutex> guard(iMutex);
         i--;
      }
   });

   t1.join();
   t2.join();
   std::cout << i << std::endl;
}
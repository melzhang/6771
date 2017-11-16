#ifndef T3_HPP
#define T3_HPP

#include <string>
#include <iostream>

class Car {
public:
   Car(std::string m, unsigned int n) : manufacturer{m}, numSeats{n} {numCars++; };
   Car() : Car{"unknown", 4} {};
   ~Car() { numCars--; };

   // copy constructor
   Car(const Car &c);
   // move constructor
   Car(const Car &&c);
   // copy assignment
   Car& operator=(const Car &c);
   // move assignment
   Car& operator=(const Car &&c);

   const std::string getManufacturer() { return manufacturer; }
   const unsigned int getNumSeats() { return numSeats; }
   static unsigned int getObjectCount() { return numCars; }

private:
   std::string manufacturer;
   unsigned int numSeats;
   static unsigned int numCars;
};

#endif
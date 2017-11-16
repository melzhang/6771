#include "t3.hpp"

unsigned int Car::numCars = 0;

Car::Car(const Car &c) {
   manufacturer = c.manufacturer;
   numSeats = c.numSeats;
   numCars++;
}
   // move constructor
Car::Car(const Car &&c) {
   manufacturer = std::move(c.manufacturer);
   numSeats = std::move(c.numSeats);
   numCars++;
}

Car& Car::operator=(const Car &c) {
   manufacturer = c.manufacturer;
   numSeats = c.numSeats;
   return *this;
}

Car& Car::operator=(const Car &&c) {
   manufacturer = std::move(c.manufacturer);
   numSeats = std::move(c.numSeats);
   return *this;
}


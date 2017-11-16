#include "tut3.h"


// init our static data member
unsigned int Car::num_cars_ = 0;

Car::Car(const std::string& manufacturer, unsigned int numSeats):
  manufacturer_{manufacturer}, numSeats_{numSeats} {
    std::cout << "Create Car" << '\n';
    ++num_cars_;
  };

// default constructor - delegates
Car::Car(): Car("unknown", 4) {};

// copy constructor
Car::Car(const Car& c):
  manufacturer_{c.manufacturer_}, numSeats_{c.numSeats_} {
    std::cout << "Copy Car" << '\n';
    ++num_cars_;
  }

// move constructor
Car::Car(Car&& c):
  manufacturer_{std::move(c.manufacturer_)}, numSeats_{std::move(c.numSeats_)} {
    std::cout << "Move Car" << '\n';
    ++num_cars_;
  }

Car::~Car() {
  std::cout << "Del Car" << '\n';
  --num_cars_;
}

Car& Car::operator=(const Car& c) {
  std::cout << "copy car operator" << '\n';
  manufacturer_ = c.manufacturer_;
  numSeats_ = c.numSeats_;
  return *this;
}

Car& Car::operator=(Car&& c) {
  std::cout << "move car operator" << '\n';
  manufacturer_ = std::move(c.manufacturer_);
  numSeats_ = c.numSeats_;
  return *this;
}

#ifndef TUT3_H
#define TUT3_H

#include <iostream>
#include <string>
/*
 topics to cover:
 - Classes
 - Constructos
 - Copy Control
 - Move semantics
 - Most Vexing pass
*/

class Car {
public:
  // car constructor
  Car();
  Car(const std::string& manufacturer, unsigned int numSeats);
  // Q: Why is it important to use a member initializer list?
  // A: prevents unnecessary call to the deafault constructor, improves efficiency
  // Q: Why is uniform initialisation prefered in C++11?
  // A: solves most vexing pass

  // Create a copy constructor, be sure to increase the object count.
  Car(const Car& c);

  // Create a move constructor
  // Q: should you increase the object count too?
  // A: No, we are not creating a new object
  Car(Car&& c);

  // Create a copy assignment operator
  // Q: should the object count change?
  // A: Yes, we are creating a new object, even if it's the same
  Car& operator=(const Car& c);

  // Create a move assignment operator
  // Q: should the object count change?
  // A: Yes, because we will destroy the prev obj, which results in --num_cars_
  Car& operator=(Car&& c);

  // Create a destructor that decreases the object count when an object is destroyed
  ~Car();

  // Create const member functions to get the manufacturer and number of seats.
  // Q: What does it mean for a class or function to be const correct?
  // A: prevents const objects to be mutated, maintain type safety.
  std::string& getManufacturer() { return manufacturer_; };  // promise not to change *this
  unsigned int getNumSeats() { return numSeats_; };     // promise not to change *this

  // Create a static function to return the object count.
  // Q: What does it mean for an function or data member to be static?
  // A: a static member is a global object for the class
  // Q: Is the static data member part of the object or the class?
  // A: a part of the class
  static unsigned int getNumCars() { return num_cars_; };

private:
  std::string manufacturer_;
  unsigned int numSeats_;

  // Create a static data member to keep count of the number of car objects created.
  // static unbound by class instance, ie. think of it as global to all class instances
  // Q: Do you need to increase the object count in your delegating constructor?
  // A: no because my constructor takes care of the increment. If I did it would double ++
  // Q: Ensure that your static object count is initised to 0, where should you do this, in the header file or the cpp file??? NO??
  // A: in the header, as it is static ??
  static unsigned int num_cars_;
};

#endif

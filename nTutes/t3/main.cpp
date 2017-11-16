#include <iostream>
#include <vector>
#include <array>
#include "tut3.h"

void main_tute3();

int main() {
   main_tute3();
}

void main_tute3()
{

    Car one;
    Car two{"Toyota",5};

    std::cout << two.getManufacturer() << "\n";
    std::cout << two.getNumSeats() << "\n";


    std::cout << Car::getNumCars() << std::endl;



    Car* three = new Car{};
    std::cout << Car::getNumCars() << std::endl;
    delete three;
    std::cout << Car::getNumCars() << std::endl;

    Car four{two};
    std::cout << Car::getNumCars() << std::endl;

    Car five = std::move(one);

    std::cout << Car::getNumCars() << std::endl;

    Car six{std::move(two)};
    std::cout << Car::getNumCars() << std::endl;

    four = six;
    std::cout << Car::getNumCars() << std::endl;

    five = std::move(six);
    std::cout << Car::getNumCars() << std::endl;


/*
    double averageNumberOfSeats = 3.2;
    const char* car_name = "Average_car";
    //Car seven ( std::string("Average Car"), int{averageNumberOfSeats} );
    Car seven ( std::string{car_name}, static_cast<int>(averageNumberOfSeats) );
    std::cout << seven.get_manufacturer() << "\n";

*/

}

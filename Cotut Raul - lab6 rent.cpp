#include <iostream>
#include <string>
#include <type_traits>

class Service {
protected:
    std::string name;

public:
    explicit Service(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }
};

class Car : public Service {
public:
    explicit Car(const std::string& name) : Service(name) {}
};

class Book : public Service {
public:
    explicit Book(const std::string& name) : Service(name) {}
};

template <typename T>
class RentService {
public:
    void rentService(const std::string& personName, const T& service) {
      std::cout << "Renting " << service.getName() << " for " << personName << std::endl;
      if (std::is_same<T, Car>::value ) {
        if (validateDriverLicense(personName)) {
          std::cout << "The car now rented" << std::endl;
        }
        else {
          std::cout << "Sorry, but you can't rent the car" << std::endl;
        }
      }
      else {
        std::cout << "Service rented!" << std::endl;
      }
    }

private:
    bool validateDriverLicense(const std::string& personName) {
      std::string answear;
      std::cout << "Does " << personName << "have a driver License? (yes/no)" <<std::endl;
      std::cin >> answear;
      return answear == "yes";
    }
};

int main() {
    RentService<Car> carRentService;
    RentService<Book> bookRentService;

    Car car("Audi A4");
    Book book("Java programming");

    carRentService.rentService("Cotut Raul", car);
    bookRentService.rentService("Popescu Ioan", book);

    return 0;
}

#include <iostream>
#include <memory>
#include <vector>

class Animal {
public:
  virtual ~Animal() = default;
  virtual std::ostream &operator<<(std::ostream &os) const {
    os << "Animal";
    return os;
  }
};

class Dog : public Animal {
public:
  std::ostream &operator<<(std::ostream &os) const override {
    os << "Dog";
    return os;
  }
};

class Cat : public Animal {
public:
  std::ostream &operator<<(std::ostream &os) const override {
    os << "Cat";
    return os;
  }
};

int main() {
  std::vector<std::shared_ptr<Animal>> animals;
  animals.push_back(std::make_shared<Dog>());
  animals.push_back(std::make_shared<Cat>());
  animals.push_back(std::make_shared<Dog>());

  for (const auto &animal : animals) {
    animal->operator<<(std::cout) << std::endl;
  }

  std::cout << "Kid adopts an animal!" << std::endl;
  std::string desiredAnimal = "Dog";

  for (auto it = animals.begin(); it != animals.end(); ++it) {
    if (dynamic_cast<Dog *>(it->get())) {
          std::cout << "Kid adopts the dog: ";
          (*it)->operator<<(std::cout);
          std::cout << std::endl;
          animals.erase(it);
          break;
        }
    }

    std::cout << "Animals after adoption:" << std::endl;
    for (const auto &animal : animals) {
      animal->operator<<(std::cout) << std::endl;
    }

    return 0;
  }

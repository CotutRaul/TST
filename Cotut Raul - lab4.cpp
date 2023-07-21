#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Container {
private:
    std::vector<T> elements_;

public:
    void add(const T& element) {
        elements_.push_back(element);
    }
    void remove(const T& element) {
        elements_.erase(std::remove(elements_.begin(), elements_.end(), element), elements_.end());
    }

    template <typename UnaryPredicate>
    void applyCondition(UnaryPredicate condition) {
        elements_.erase(std::remove_if(elements_.begin(), elements_.end(), condition), elements_.end());
    }

    auto begin() {
        return elements_.begin();
    }

    auto end() {
        return elements_.end();
    }

    void print() const {
        for (const auto& element : elements_) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
struct IsPositive {
    bool operator()(const T& element) const {
        return element > 0;
    }
};

int main() {
    std::vector<Container<int>> vect;

    Container<int> cont1;
    cont1.add(41);
    cont1.add(-10);
    cont1.add(81);
    vect.push_back(cont1);

    Container<int> cont2;
    cont2.add(-159);
    cont2.add(75);
    cont2.add(-33);
    vect.push_back(cont2);

    for (const auto& cont : vect) {
        cont.print();
    }
    std::cout << "Positive numbers:\n";

    for (auto& cont : vect) {
        auto it = std::find_if(cont.begin(), cont.end(), IsPositive<int>());
        std::cout << *it << " ";
        cont.applyCondition(IsPositive<int>());
    }

    std::cout << std::endl << "Containers: " << std::endl;
    for (const auto& cont : vect) {
        cont.print();
    }

    return 0;
}

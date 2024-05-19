#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class Trit {
public:
    enum Value { Zero = 0, One, Two };

    // конструктор по умолчанию, принимающий значение 0
    Trit(Value value = Zero) : value(value) {
        if (value < Zero || value > Two) {
            throw std::invalid_argument("Invalid Trit value");
        }
    }

    //оператора сложения
    Trit operator+(const Trit& other) const {
        return Trit(static_cast<Value>((value + other.value) % 3));
    }

    //оператора вычитания
    Trit operator-(const Trit& other) const {
        return Trit(static_cast<Value>((value + 3 - other.value) % 3));
    }

    //оператора умножения
    Trit operator*(const Trit& other) const {
        return Trit(static_cast<Value>((value * other.value) % 3));
    }

    //оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Trit& trit) {
        os << static_cast<int>(trit.value);
        return os;
    }

private:
    Value value;
};

class Triit {
public:
    Triit(const std::string& str) {
        for (char c : str) {
            if (c == '0') {
                trits.push_back(Trit(Trit::Zero));
            } else if (c == '1') {
                trits.push_back(Trit(Trit::One));
            } else if (c == '2') {
                trits.push_back(Trit(Trit::Two));
            } else {
                throw std::invalid_argument("Invalid Triit string");
            }
        }
    }

    //оператора сложения
    Triit operator+(const Triit& other) const {
        Triit result = *this;
        for (size_t i = 0; i < std::min(trits.size(), other.trits.size()); ++i) {
            result.trits[i] = result.trits[i] + other.trits[i];
        }
        return result;
    }

    //оператора вычитания
    Triit operator-(const Triit& other) const {
        Triit result = *this;
        for (size_t i = 0; i < std::min(trits.size(), other.trits.size()); ++i) {
            result.trits[i] = result.trits[i] - other.trits[i];
        }
        return result;
    }

    //оператора умножения
    Triit operator*(const Triit& other) const {
        Triit result = *this;
        for (size_t i = 0; i < std::min(trits.size(), other.trits.size()); ++i) {
            result.trits[i] = result.trits[i] * other.trits[i];
        }
        return result;
    }

    //оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Triit& triit) {
        for (const Trit& trit : triit.trits) {
            os << trit;
        }
        return os;
    }
    
private:
    std::vector<Trit> trits;
};

int main() {
    Triit triit1("1122");
    Triit triit2("201");

    Triit sum = triit1 + triit2;
    Triit diff = triit1 - triit2;
    Triit prod = triit1 * triit2;

    std::cout << "triit1: " << triit1 << std::endl;
    std::cout << "triit2: " << triit2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;

    return 0;
}

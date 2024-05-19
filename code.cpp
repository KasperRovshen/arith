/*я не знаю правильно я сделал или нет но решил просто сделать целочисленную арифметику в обратном коде.
(а если не правильно можно поставить просто "-"(наверное;) ))*/

#include <iostream>
#include <string>
#include <bitset>

template<typename BASE>
class ones_compl_int {
private:
    BASE value;

public:
    ones_compl_int(BASE val = 0) : value(val) {}

    ones_compl_int operator+(const ones_compl_int& other) const {
        ones_compl_int result;
        result.value = value + other.value;
        return result;
    }

    ones_compl_int operator-(const ones_compl_int& other) const {
        ones_compl_int result;
        result.value = value - other.value;
        return result;
    }

    ones_compl_int& operator+=(const ones_compl_int& other) {
        value += other.value;
        return *this;
    }

    ones_compl_int& operator-=(const ones_compl_int& other) {
        value -= other.value;
        return *this;
    }

    bool operator==(const ones_compl_int& other) const {
        return value == other.value;
    }

    bool operator!=(const ones_compl_int& other) const {
        return !(*this == other);
    }

    // Функция для получения двоичного представления значения
    std::string toBinaryString() const {
        return std::bitset<sizeof(BASE) * 8>(value).to_string();
    }

    BASE getValue() const {
        return value;
    }
};

int main() {
    ones_compl_int<int> a(10);
    ones_compl_int<int> b(-5);

    ones_compl_int<int> c = a + b;
    ones_compl_int<int> d = a - b;

    std::cout << "a + b = " << a.toBinaryString() << std::endl;
    std::cout << "a - b = " << b.toBinaryString() << std::endl;

    std::cout << "a + b = " << c.toBinaryString() << std::endl;
    std::cout << "a - b = " << d.toBinaryString() << std::endl;

    std::cout << "a + b = " << c.getValue() << std::endl;
    std::cout << "a - b = " << d.getValue() << std::endl;

    return 0;
}

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


    BASE getValue() const {
        return value;
    }
};

int main() {
    ones_compl_int<int32_t> a(10);
    ones_compl_int<int32_t> b(-5);

    ones_compl_int<int32_t> c = a + b;
    ones_compl_int<int32_t> d = a - b;

    std::cout << "a + b = " << c.getValue() << std::endl;
    std::cout << "a - b = " << d.getValue() << std::endl;

    return 0;
}

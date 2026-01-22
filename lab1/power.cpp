#include <iostream>
using namespace std;

int fastPower(int base, int exponent) {

    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    int tempExp = exponent;
    int value = base;
    int result = 1;

    while (tempExp > 1) {

        if (tempExp % 2 == 0) {
            value = value * value;
            tempExp = tempExp / 2;
        }
        else {
            result = result * value;
            tempExp = tempExp - 1;
        }
    }

    return result;
}

int main() {

    int baseNum, powerNum;

    cout << "Enter x and n: ";
    cin >> baseNum >> powerNum;

    cout << "Result = " << fastPower(baseNum, powerNum);

    return 0;
}

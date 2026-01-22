#include <iostream>
using namespace std;

int main() {

    int degree, valueX, answer = 0;

    cout << "Enter degree of polynomial: ";
    cin >> degree;

    int poly[degree + 1];

    cout << "Enter coefficients (highest degree first): ";
    for (int index = 0; index <= degree; index++) {
        cin >> poly[index];
    }

    cout << "Enter value of x: ";
    cin >> valueX;

    answer = poly[0];

    for (int pos = 1; pos <= degree; pos++) {
        answer = answer * valueX + poly[pos];
    }

    cout << "Polynomial value = " << answer;

    return 0;
}

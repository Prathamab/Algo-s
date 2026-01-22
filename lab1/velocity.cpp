#include <iostream>
using namespace std;

int countSteps(double speed) {

    if (speed < 1.0)
        return 0;

    return 1 + countSteps(speed - 0.425 * speed);
}

int main() {

    int velocity;

    cout << "Enter the velocity: ";
    cin >> velocity;

    cout << countSteps(velocity);

    return 0;
}

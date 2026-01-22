#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter n: ";
    cin >> size;

    int numbers[100];

    cout << "Enter elements: ";
    for (int index = 0; index < size; index++)
        cin >> numbers[index];

    int start = numbers[0];
    int end = numbers[size - 1];

    int totalExpected = 0;
    int totalActual = 0;

    for (int num = start; num <= end; num++)
        totalExpected = totalExpected + num;

    for (int pos = 0; pos < size; pos++)
        totalActual = totalActual + numbers[pos];

    int missing = totalExpected - totalActual;

    cout << "Missing number was " << missing;

    return 0;
}

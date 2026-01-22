#include <iostream>
#include <ctime>
using namespace std;

void generatePerm(char str[], int left, int right) {

    if (left == right)
        return;

    for (int pos = left; pos <= right; pos++) {

        swap(str[left], str[pos]);
        generatePerm(str, left + 1, right);
        swap(str[left], str[pos]);
    }
}

int main() {

    cout << "n\tAverageTime(seconds)\n";

    for (int size = 1; size <= 10; size++) {

        char data[10];

        for (int index = 0; index < size; index++)
            data[index] = 'A' + index;

        double sumTime = 0;

        for (int repeat = 0; repeat < 100; repeat++) {

            clock_t begin = clock();
            generatePerm(data, 0, size - 1);
            clock_t finish = clock();

            sumTime += double(finish - begin) / CLOCKS_PER_SEC;
        }

        cout << size << "\t" << sumTime / 100 << endl;
    }

    return 0;
}

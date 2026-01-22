#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSorting(int data[], int size) {

    for (int pass = 0; pass < size - 1; pass++) {

        for (int pos = 0; pos < size - pass - 1; pos++) {

            if (data[pos] > data[pos + 1]) {
                int temp = data[pos];
                data[pos] = data[pos + 1];
                data[pos + 1] = temp;
            }
        }
    }
}

int main() {

    srand(time(0));
    cout << "InputSize\tAverageTime(seconds)\n";

    for (int length = 1000; length <= 20000; length += 1000) {

        double timeSum = 0;

        for (int run = 0; run < 100; run++) {

            int *data = new int[length];

            for (int index = 0; index < length; index++)
                data[index] = rand();

            clock_t begin = clock();
            bubbleSorting(data, length);
            clock_t finish = clock();

            timeSum += double(finish - begin) / CLOCKS_PER_SEC;

            delete[] data;
        }

        cout << length << "\t\t" << timeSum / 100 << endl;
    }

    return 0;
}

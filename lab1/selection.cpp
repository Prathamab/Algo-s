#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void selectSort(int data[], int size) {

    for (int pass = 0; pass < size - 1; pass++) {

        int minIndex = pass;

        for (int pos = pass + 1; pos < size; pos++) {
            if (data[pos] < data[minIndex])
                minIndex = pos;
        }

        int temp = data[pass];
        data[pass] = data[minIndex];
        data[minIndex] = temp;
    }
}

int main() {

    srand(time(0));
    cout << "InputSize\tAverageTime(seconds)\n";

    for (int length = 1000; length <= 20000; length += 1000) {

        double sumTime = 0;

        for (int repeat = 0; repeat < 100; repeat++) {

            int *data = new int[length];

            for (int index = 0; index < length; index++)
                data[index] = rand();

            clock_t begin = clock();
            selectSort(data, length);
            clock_t finish = clock();

            sumTime += double(finish - begin) / CLOCKS_PER_SEC;

            delete[] data;
        }

        cout << length << "\t\t" << sumTime / 100 << endl;
    }

    return 0;
}

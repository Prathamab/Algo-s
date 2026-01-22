#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Sequential Search Function
int seqSearch(int data[], int size, int target) {

    for (int pos = 0; pos < size; pos++) {
        if (data[pos] == target)
            return pos;
    }

    return -1;
}

int main() {

    srand(time(0));

    cout << "InputSize\tAverageTime(seconds)\n";

    // Input size from 1000 to 20000
    for (int length = 1000; length <= 20000; length += 1000) {

        double sumTime = 0.0;

        // Repeat 100 times
        for (int repeat = 0; repeat < 100; repeat++) {

            int *data = new int[length];

            // Fill array with random values
            for (int index = 0; index < length; index++)
                data[index] = rand();

            int target = data[length - 1];   // Worst case

            clock_t begin = clock();
            seqSearch(data, length, target);
            clock_t finish = clock();

            sumTime += double(finish - begin) / CLOCKS_PER_SEC;

            delete[] data;
        }

        double avgTime = sumTime / 100.0;
        cout << length << "\t\t" << avgTime << endl;
    }

    return 0;
}

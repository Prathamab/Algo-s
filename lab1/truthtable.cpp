#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void selectionSorting(int arrValues[], int total) {

    for (int step = 0; step < total - 1; step++) {

        int smallest = step;

        for (int check = step + 1; check < total; check++) {
            if (arrValues[check] < arrValues[smallest])
                smallest = check;
        }

        int swapTemp = arrValues[step];
        arrValues[step] = arrValues[smallest];
        arrValues[smallest] = swapTemp;
    }
}

int main() {

    srand(time(0));
    cout << "InputSize\tAverageTime(seconds)\n";

    for (int inputSize = 1000; inputSize <= 20000; inputSize += 1000) {

        double totalDuration = 0;

        for (int runCount = 0; runCount < 100; runCount++) {

            int *arrValues = new int[inputSize];

            for (int fill = 0; fill < inputSize; fill++)
                arrValues[fill] = rand();

            clock_t startTime = clock();
            selectionSorting(arrValues, inputSize);
            clock_t endTime = clock();

            totalDuration += double(endTime - startTime) / CLOCKS_PER_SEC;

            delete[] arrValues;
        }

        cout << inputSize << "\t\t" << totalDuration / 100 << endl;
    }

    return 0;
}

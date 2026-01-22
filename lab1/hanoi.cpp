#include <iostream>
#include <ctime>
using namespace std;

void hanoiSolve(int disks, char source, char helper, char destination) {

    if (disks == 0)
        return;

    hanoiSolve(disks - 1, source, destination, helper);
    hanoiSolve(disks - 1, helper, source, destination);
}

int main() {

    cout << "Disks\tAverageTime(seconds)\n";

    for (int count = 1; count <= 20; count++) {

        double sumTime = 0.0;

        for (int repeat = 0; repeat < 100; repeat++) {

            clock_t begin = clock();
            hanoiSolve(count, 'A', 'B', 'C');
            clock_t finish = clock();

            sumTime += double(finish - begin) / CLOCKS_PER_SEC;
        }

        cout << count << "\t" << sumTime / 100 << endl;
    }

    return 0;
}

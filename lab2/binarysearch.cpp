#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    srand(time(0));

    cout << fixed << setprecision(8);
    cout << "InputSize\tAverageTime(seconds)\n";

    for (int n = 1000; n <= 10000; n += 1000)
    {
        double totalTime = 0;

        for (int k = 0; k < 100; k++)
        {
            int *arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = rand();

            sort(arr, arr + n);   // Important for binary search

            int key = arr[n - 1];

            clock_t start = clock();

            // Repeat search to increase measurable time
            for (int repeat = 0; repeat < 1000; repeat++)
                binarySearch(arr, n, key);

            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;

            delete[] arr;
        }

        cout << n << "\t\t" << totalTime / 100 << endl;
    }

    return 0;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {

    srand(time(0));

    for (int n = 1000; n <= 20000; n += 1000) {

        int arr[n];   

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        clock_t start, end;

        start = clock();

        quicksort(arr, 0, n - 1);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << "Size: " << n << " -> Time: " << time_taken << " sec" << endl;
    }

    return 0;
}

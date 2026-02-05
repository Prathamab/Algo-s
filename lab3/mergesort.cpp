#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(int arr[], int l, int mid, int r) {

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        b[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {

    srand(time(0));

    for (int n = 1000; n <= 10000; n += 1000) {

        int arr[n];   // Array created according to n (no fixed size)

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        clock_t start, end;

        start = clock();

        mergesort(arr, 0, n - 1);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << "Size: " << n << " -> Time: " << time_taken << " sec" << endl;
    }

    return 0;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int j=1;j<n;j++){
        int key=arr[j];
        int i=j-1;

        while(i>0 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
        }
       arr[i+1]=key;
    }
}

int main() {
    srand(time(0));
    cout << "InputSize\t Avg time(seconds)\n";

    for (int n = 1000; n <= 10000; n += 1000) {
        double totalTime = 0;

    for (int k = 0; k < 100; k++) {
      int *arr = new int[n];
        for (int i = 0; i < n; i++)
         arr[i] = rand();

            clock_t start = clock();
            insertionSort(arr, n);
            clock_t end = clock();

            totalTime += double(end - start) / CLOCKS_PER_SEC;
        }

        cout << n << "\t\t" << totalTime / 100 << endl;
    }
    return 0;
}
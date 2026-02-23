#include <iostream>
#include <algorithm>
using namespace std;

struct Object {
    int profit;
    int weight;
};

bool byProfit(Object a, Object b) {
    return a.profit > b.profit;
}

bool byWeight(Object a, Object b) {
    return a.weight < b.weight;
}

bool byRatio(Object a, Object b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

int calculate(Object arr[], int n, int capacity) {
    int totalProfit = 0;
    int totalWeight = 0;

    cout << "Selected items:\n";

    for (int i = 0; i < n; i++) {
        if (totalWeight + arr[i].weight <= capacity) {
            totalWeight += arr[i].weight;
            totalProfit += arr[i].profit;

            cout << "Profit: " << arr[i].profit
                 << " Weight: " << arr[i].weight << endl;
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
    return totalProfit;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Object item[100];

    cout << "Enter profit and weight:\n";
    for (int i = 0; i < n; i++) {
        cin >> item[i].profit >> item[i].weight;
    }

    cout << "Enter maximum capacity: ";
    cin >> capacity;

    Object temp1[100], temp2[100], temp3[100];

    for (int i = 0; i < n; i++) {
        temp1[i] = item[i];
        temp2[i] = item[i];
        temp3[i] = item[i];
    }

    cout << "\nGreedy by Profit\n";
    sort(temp1, temp1 + n, byProfit);
    int p1 = calculate(temp1, n, capacity);

    cout << "\nGreedy by Weight\n";
    sort(temp2, temp2 + n, byWeight);
    int p2 = calculate(temp2, n, capacity);

    cout << "\nGreedy by Ratio\n";
    sort(temp3, temp3 + n, byRatio);
    int p3 = calculate(temp3, n, capacity);

    int best = max(p1, max(p2, p3));

    cout << "\nBest Profit: " << best << endl;

    if (best == p1)
        cout << "Best Method: Greedy by Profit\n";
    else if (best == p2)
        cout << "Best Method: Greedy by Weight\n";
    else
        cout << "Best Method: Greedy by Ratio\n";

    return 0;
}
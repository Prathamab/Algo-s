#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxVal = INT_MIN;

        for (int j = 0; j < i; j++) {
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        }

        dp[i] = maxVal;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter length of rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    cout << "Maximum Profit: " << rodCutting(price, n) << endl;

    return 0;
}
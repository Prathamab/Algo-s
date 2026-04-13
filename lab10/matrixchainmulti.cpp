#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[20];

    cout << "Enter dimensions:\n";
    cout << "For example, for 3 matrices enter 4 values\n";

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int dp[20][20];

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;

            dp[i][j] = 99999;

            for (int k = i; k < j; k++) {
                int cost;

                cost = dp[i][k] + dp[k + 1][j] +
                       p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of multiplications = "
         << dp[1][n] << endl;

    return 0;
}
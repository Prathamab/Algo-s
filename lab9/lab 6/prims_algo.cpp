#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[100][100];
    int visit[100];
    int total = 0;

    cout << "Enter cost matrix (use 999 for no edge):\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        visit[i] = 0;
    }

    visit[1] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int edge = 1; edge < n; edge++) {
        int min = 999;
        int a = 0;
        int b = 0;

        for (int i = 1; i <= n; i++) {
            if (visit[i] == 1) {
                for (int j = 1; j <= n; j++) {
                    if (visit[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << "  Cost = " << min << endl;

        total = total + min;
        visit[b] = 1;
    }

    cout << "\nTotal Minimum Cost = " << total << endl;

    return 0;
}
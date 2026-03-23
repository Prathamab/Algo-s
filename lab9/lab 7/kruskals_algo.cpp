#include <iostream>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Edge e[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].weight;
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (e[j].weight > e[j + 1].weight) {
                Edge temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    int parent[100];

    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    int count = 0;
    int total = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < m && count < n - 1; i++) {
        int a = e[i].u;
        int b = e[i].v;

        if (parent[a] != parent[b] || parent[a] == 0 || parent[b] == 0) {
            cout << a << " - " << b << "  Cost = " << e[i].weight << endl;

            total = total + e[i].weight;
            count++;

            int value;

            if (parent[a] == 0 && parent[b] == 0) {
                value = a;
                parent[a] = value;
                parent[b] = value;
            }
            else if (parent[a] == 0) {
                parent[a] = parent[b];
            }
            else if (parent[b] == 0) {
                parent[b] = parent[a];
            }
            else {
                value = parent[b];

                for (int j = 1; j <= n; j++) {
                    if (parent[j] == value) {
                        parent[j] = parent[a];
                    }
                }
            }
        }
    }

    cout << "\nTotal Minimum Cost = " << total << endl;

    return 0;
}
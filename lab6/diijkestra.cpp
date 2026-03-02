#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    int graph[100][100];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 9999;
        }
    }

    cout << "Enter edge and weight (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    int distance[100];
    int visited[100];

    for (int i = 1; i <= n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    visited[source] = 1;
    distance[source] = 0;

    for (int count = 1; count < n; count++) {
        int min = 9999;
        int nextNode = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && distance[i] < min) {
                min = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                if (min + graph[nextNode][i] < distance[i]) {
                    distance[i] = min + graph[nextNode][i];
                }
            }
        }
    }

    cout << "\nShortest Distance:\n";
    for (int i = 1; i <= n; i++) {
        cout << "From " << source << " to " << i
             << " = " << distance[i] << endl;
    }

    return 0;
}
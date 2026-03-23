#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n = 6;

    
    int graph[7][7] = {
        {0},
        {0,0,2,1,0,0,0},
        {0,0,0,0,3,2,0},
        {0,0,0,0,6,7,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,0,5},
        {0,0,0,0,0,0,0}
    };

    int cost[7];
    int path[7];

    
    cost[n] = 0;

    
    for(int i = n - 1; i >= 1; i--) {
        cost[i] = INT_MAX;

        for(int j = i + 1; j <= n; j++) {
            if(graph[i][j] != 0) {
                if(graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

    
    cout << "Minimum cost = " << cost[1] << endl;

    cout << "Path: ";
    int i = 1;
    while(i != n) {
        cout << i << " -> ";
        i = path[i];
    }
    cout << n;

    return 0;
}
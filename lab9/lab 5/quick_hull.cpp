#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

Point hull[100];
int hullCount = 0;

int cross(Point a, Point b, Point c) {
    int value;

    value = (b.x - a.x) * (c.y - a.y) -
            (b.y - a.y) * (c.x - a.x);

    return value;
}

void findHull(Point p[], int n, Point a, Point b, int side) {
    int i;
    int index = -1;
    int maxValue = 0;

    for (i = 0; i < n; i++) {
        int value = cross(a, b, p[i]);

        if (side == 1 && value > 0) {
            if (value > maxValue) {
                maxValue = value;
                index = i;
            }
        }

        if (side == -1 && value < 0) {
            if (-value > maxValue) {
                maxValue = -value;
                index = i;
            }
        }
    }

    if (index == -1) {
        hull[hullCount] = a;
        hullCount++;

        hull[hullCount] = b;
        hullCount++;

        return;
    }

    findHull(p, n, p[index], a, -1);
    findHull(p, n, p[index], b, 1);
}

int main() {
    int n;
    int i;
    int left = 0;
    int right = 0;

    cout << "Enter number of points: ";
    cin >> n;

    Point p[100];

    cout << "Enter points (x y):\n";
    for (i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    if (n < 3) {
        cout << "Convex Hull not possible\n";
        return 0;
    }

    for (i = 1; i < n; i++) {
        if (p[i].x < p[left].x) {
            left = i;
        }

        if (p[i].x > p[right].x) {
            right = i;
        }
    }

    findHull(p, n, p[left], p[right], 1);
    findHull(p, n, p[left], p[right], -1);

    cout << "\nConvex Hull Points:\n";

    for (i = 0; i < hullCount; i++) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }

    return 0;
}
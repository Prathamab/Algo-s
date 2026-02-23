#include <iostream>
using namespace std;

struct Coordinate {
    double x, y;
};

double checkDirection(Coordinate p1, Coordinate p2, Coordinate p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) -
           (p2.y - p1.y) * (p3.x - p1.x);
}

bool pointInsideTriangle(Coordinate p1, Coordinate p2,
                         Coordinate p3, Coordinate p) {

    double d1 = checkDirection(p1, p2, p);
    double d2 = checkDirection(p2, p3, p);
    double d3 = checkDirection(p3, p1, p);

    bool positive = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool negative = (d1 < 0) || (d2 < 0) || (d3 < 0);

    return !(positive && negative);
}

int main() {
    int totalPoints;
    cout << "Enter number of points: ";
    cin >> totalPoints;

    Coordinate p[100];

    cout << "Enter points (x y):\n";
    for (int i = 0; i < totalPoints; i++) {
        cin >> p[i].x >> p[i].y;
    }

    bool hullPoint[100];

    for (int i = 0; i < totalPoints; i++) {
        hullPoint[i] = true;
    }

    for (int i = 0; i < totalPoints; i++) {

        for (int j = 0; j < totalPoints; j++) {
            if (j == i) continue;

            for (int k = j + 1; k < totalPoints; k++) {
                if (k == i) continue;

                for (int m = k + 1; m < totalPoints; m++) {
                    if (m == i) continue;

                    if (pointInsideTriangle(p[j], p[k], p[m], p[i])) {
                        hullPoint[i] = false;
                        break;
                    }
                }

                if (!hullPoint[i]) break;
            }

            if (!hullPoint[i]) break;
        }
    }

    cout << "\nConvex Hull Points:\n";

    for (int i = 0; i < totalPoints; i++) {
        if (hullPoint[i]) {
            cout << p[i].x << " " << p[i].y << endl;
        }
    }

    return 0;
}
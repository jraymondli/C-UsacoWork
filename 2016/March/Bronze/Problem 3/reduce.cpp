//43 min
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int n;
    fin >> n;

    vector<int> x(n), y(n);
    int minX = 40005, maxX = 0, minY = 40005, maxY = 0; 
    int minX2 = 40005, maxX2 = 0, minY2 = 40005, maxY2 = 0;
    for (int i=0; i<n; i++) {
        fin >> x[i] >> y[i];

        if (x[i] < minX) {
            minX2 = minX;
            minX = x[i];
        } else if (x[i] < minX2) {
            minX2 = x[i];
        }

        if (x[i] > maxX) {
            maxX2 = maxX;
            maxX = x[i];
        } else if (x[i] > maxX2) {
            maxX2 = x[i];
        }

        if (y[i] < minY) {
            minY2 = minY;
            minY = y[i];
        } else if (y[i] < minY2) {
            minY2 = y[i];
        }

        if (y[i] > maxY) {
            maxY2 = maxY;
            maxY = y[i];
        } else if (y[i] > maxY2) {
            maxY2 = y[i];
        }
    }
    int answer = 2000000000;
    for (int i=0; i<n; i++) {
        int leftX, rightX, topY, bottomY;

        if (x[i] == minX) {
            leftX = minX2;
        } else {
            leftX = minX;
        }

        if (x[i] == maxX) {
            rightX = maxX2;
        } else {
            rightX = maxX;
        }

        if (y[i] == maxY) {
            topY = maxY2;
        } else {
            topY = maxY;
        }

        if (y[i] == minY) {
            bottomY = minY2;
        } else {
            bottomY = minY;
        }

        answer = min(answer, (rightX - leftX) * (topY - bottomY));
    }

    fout << answer << endl;

    return 0;
}
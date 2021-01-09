//24 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, field[2001][2001], min_x = 1000, farmer[2] = {1000, 1000}, t = 0;

int main() {
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    fin >> N;
    for (int i = 0; i < 2000; i++) for (int j = 0; j < 2000; j++) field[i][j] = -1;
    for (int i = 0; i < N; i++) {
        int S = 0;
        char D = ' ';
        fin >> D >> S;
        for (int j = 0; j < S; j++){
            t++;
            if (D == 'N') {
                if (field[farmer[0]][farmer[1]] != -1 & t-field[farmer[0]][farmer[1]] < min_x) {
                    min_x = t-field[farmer[0]][farmer[1]];
                }
                field[farmer[0]][farmer[1]] = t;
                farmer[1]++;
            }
            if (D == 'E') {
                if (field[farmer[0]][farmer[1]] != -1 & t-field[farmer[0]][farmer[1]] < min_x) {
                    min_x = t-field[farmer[0]][farmer[1]];
                }
                field[farmer[0]][farmer[1]] = t;
                farmer[0]++;
            }
            if (D == 'S') {
                if (field[farmer[0]][farmer[1]] != -1 & t-field[farmer[0]][farmer[1]] < min_x) {
                    min_x = t-field[farmer[0]][farmer[1]];
                }
                field[farmer[0]][farmer[1]] = t;
                farmer[1]--;
            }
            if (D == 'W') {
                if (field[farmer[0]][farmer[1]] != -1 & t-field[farmer[0]][farmer[1]] < min_x) {
                    min_x = t-field[farmer[0]][farmer[1]];
                }
                field[farmer[0]][farmer[1]] = t;
                farmer[0]--;
            }
        }
    }
    if (min_x == 1000){
        fout << -1 << "\n";
        return 0;
    }
    fout << min_x << "\n";
    return 0;
}

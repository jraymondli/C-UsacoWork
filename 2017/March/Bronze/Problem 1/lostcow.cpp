/* 23
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin ("lostcow.in");
    ofstream fout ("lostcow.out");
    int x, y;
    fin >> x >> y;

    int ans = 0;
    int by = 1;
    int dir = 1;
    while(true) {
        if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) {
            ans += abs(y-x);
            fout << ans << "\n";
            break;
        } else {
        ans += by*2;
        by *= 2;
        dir *= -1;
        }
    }
}
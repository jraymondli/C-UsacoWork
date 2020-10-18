#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
//time used: 32 min
int main(void)
{
    ifstream fin ("teleport.in");
    ofstream fout ("teleport.out");
    int x, y, a, b;
    fin >> x >> y >> a >> b;
    int xaby = abs(x-a) + abs(y-b), xbay = abs(x-b) + abs(y-a), xy = abs(x-y);
    fout << min(min(xaby, xbay), xy);
    return 0;
}

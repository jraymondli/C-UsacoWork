#include <iostream>
#include <fstream>
using namespace std;
//time used: 32 min
int main(void)
{
    int a, b, c;
    ifstream fin ("herding.in");
    fin >> a >> b >> c;
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    
    ofstream fout ("herding.out");
    if (c == a + 2)
    {
        fout << "0\n";
    } else if (b == a + 2 or c == b + 2)
    {
        fout << "1\n";
    } else 
    {
        fout << "2\n";
    }
    fout << max(b - a, c - b) - 1 << "\n";
    return 0;
}

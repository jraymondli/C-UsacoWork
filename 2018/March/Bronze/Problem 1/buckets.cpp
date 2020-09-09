#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
//time used: 48 min
char data[10][10];
int main(void)
{
    ifstream fin ("buckets.in");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fin >> data[i][j];
        }
    }
    ofstream fout ("buckets.out");
    int b[2], l[2], r[2];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (data[i][j] == 'B')
            {
                b[0] = i;
                b[1] = j;
            } else if (data[i][j] == 'L')
            {
                l[0] = i;
                l[1] = j;
            }   else if (data[i][j] == 'R')
            {
                r[0] = i;
                r[1] = j;
            }
        }
    }
    if ((b[0] == l[0] and l[0] == r[0] and ((b[1] < r[1] and r[1] < l[1]) or (l[1] < r[1] and r[1] < b[1]))) or (b[1] == l[1] and l[1] == r[1] and ((b[0] < r[0] and r[0] < l[0]) or (l[0] < r[0] and r[0] < b[0]))))
    {
        fout << abs(b[0]-l[0])+abs(b[1]-l[1])-1+2 << "\n";
    } else {
        fout << abs(b[0]-l[0])+abs(b[1]-l[1])-1 << "\n";
    }
    return 0;
}
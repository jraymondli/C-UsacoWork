//14 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int X, Y, M, max_amount = 0;
int main(void)
{
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    fin >> X >> Y >> M;
    for (int i = 0; i <= M/X; i++){
        for (int j = 0; j <= M/Y; j++){
            if (X*i+Y*j <= M & X*i+Y*j > max_amount){
                max_amount = X*i+Y*j;
            }
        }
    }
    fout << max_amount;
    return 0;
}
//46 min
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
string A, B;

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    fin >> n;
    fin >> A;
    fin >> B;
    
    int ans = 0;
    bool same = true;

    for(int i = 0; i < n; i++) 
    {
        if (same == true and A[i] != B[i])
        {
            ans++;
        }
        if (A[i] != B[i])
        {
            same = false;
        } else
        {
            same = true;
        }
    }
    fout << ans << "\n";
}
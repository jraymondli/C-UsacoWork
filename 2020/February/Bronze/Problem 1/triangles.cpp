#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n;
    fin >> n;
    vector <int> X(n, 0);
    vector <int> Y(n, 0);
    for(int i = 0; i < n; i++) 
    {
        fin >> X[i] >> Y[i];
    }
    int best = -1;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            for(int k = 0; k < n; k++) {
                if(Y[i] == Y[j] && X[i] == X[k]) {
                    int area = (X[j] - X[i]) * (Y[k] - Y[i]);
                    if(area < 0) { area *= -1; }
                    if(area > best) { best = area;}
                }
            }
        }
    }
    fout << best << "\n";
}
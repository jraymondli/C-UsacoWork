//35 minutes
#include <iostream>
#include <fstream>
using namespace std;

int N, ans = 100000000;

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    fin >> N;
    int rooms[N];
    for (int i = 0; i < N; i++) fin >> rooms[i];
    for (int i = 0; i < N; i++){
        int val = 0;
        for (int j = 0; j < N; j++){
            if (j > i) val += (j-i)*rooms[j];
            if (j < i) val += (N-i+j)*rooms[j];
            cout << val << "\n";
        }
        if (val < ans){
            ans = val;
        }
        cout << "\n";
    }
    fout << ans << "\n";
    return 0;
}
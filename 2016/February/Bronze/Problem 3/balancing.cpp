//21 minutes
#include <iostream>
#include <fstream>
using namespace std;

int N, B, cows[10000][2];

int main() {
    ifstream fin ("balancing.in");
    ofstream fout ("balancing.out");
    fin >> N >> B;
    for (int i = 0; i < N; i++) {
        fin >> cows[i][0] >> cows[i][1];
    }
    int answer = N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int max_sect_val = 0;
            for (int k = 0; k < 4; k++){
                int this_sect = 0;
                for (int l = 0; l < N; l++){
                    if (k == 0 & cows[l][0] <= cows[i][0] & cows[l][1] <= cows[j][1]) this_sect++;
                    if (k == 1 & cows[l][0] <= cows[i][0] & cows[l][1] > cows[j][1]) this_sect++;
                    if (k == 2 & cows[l][0] > cows[i][0] & cows[l][1] <= cows[j][1]) this_sect++;
                    if (k == 3 & cows[l][0] > cows[i][0] & cows[l][1] > cows[j][1]) this_sect++;
                }
                if (this_sect > max_sect_val) max_sect_val = this_sect;
            }
            if (max_sect_val < answer) answer = max_sect_val;
        }
    }
    fout << answer << "\n";
    return 0;
}
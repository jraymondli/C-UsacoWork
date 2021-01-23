//27 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int M, N, K;

int main(void)
{
    ifstream fin ("cowsignal.in");
    ofstream fout ("cowsignal.out");
    fin >> M >> N >> K;
    int signal[M][N];
    string temp;
    for (int i=0; i<M; i++){
        fin >> temp;
        for (int j=0; j<N; j++){
            if (temp[j] == 'X'){
                signal[i][j] = 0;
            } else {
                signal[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) { 
        for (int j = 0; j < K; j++){
            for (int k = 0; k < N; k++) { 
                for (int l = 0; l < K; l++){
                    if (signal[i][k] == 0){
                        fout << "X";
                    } else {
                        fout << ".";
                    }
                }
            }
            fout << "\n";
        }
    }
    return 0;
}

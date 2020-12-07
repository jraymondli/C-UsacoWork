//greater than 1 hr
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int N, cow_array[10][10], temp1;
string temp;
int main(void)
{
    ifstream fin ("cowtip.in");
    ofstream fout ("cowtip.out");
    fin >> N;
    for (int i = 0; i < N; i++){
        fin >> temp;
        for (int j = 0; j < N; j++){
            cout << temp[j];
            stringstream test;
            test << temp[j];
            test >> cow_array[i][j];

        }
    }
    cout << "\n" << cow_array[0][0] << cow_array[1][0] << cow_array[2][0] << cow_array[0][1] << cow_array[1][1] << cow_array[2][1] << cow_array[0][2] << cow_array[1][2] << cow_array[2][2] << "\n";
    int flips = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (cow_array[N-i-1][N-j-1] == 1){
                for (int k = 0; k < N; k++){
                    for (int l = 0; l < N; l++){
                        if (N-k-1 <= N-i-1 & N-l-1 <= N-j-1){
                            cow_array[N-k-1][N-l-1] = 1 - cow_array[N-k-1][N-l-1];
                        }
                    }
                }
                flips++;
            }
        }
    }
    fout << flips;
}
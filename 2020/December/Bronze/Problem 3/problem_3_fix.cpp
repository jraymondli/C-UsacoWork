/*
try to brute force by doing timesteps and ending when all norths are above all easts and all easts are to the right of norths
every step, take in the positions of the cows, move them, and check after if they move into a bad new spot
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, cows[50][5], simple_farm[50][50]; //cows[1] = dir, 0=e 1=n, cows[2/3] = xy pos, cows[4/5] = time, stopped or not
char temp;

int main() {
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> temp;
        if (temp == 'E'){
            cows[i][0] = 0;
        } else {
            cows[i][0] = 1;
        }
        cin >> cows[i][1] >> cows[i][2];
    }
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < N; j++){
            if (cows[j][4] == 0){
                simple_farm[cows[j][1]][cows[j][2]] = 1;
                if (cows[j][0]){
                    cows[j][2]++;
                } else {
                    cows[j][1]++;
                }
                cows[j][3]++;
                if (simple_farm[cows[j][1]][cows[j][2]] == 1){
                    cows[j][4] = 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++){
        if (cows[i][4]){
            cout << cows[i][3] << "\n";
        } else {
            cout << "Infinity\n";
        }
    }
    return 0;
}
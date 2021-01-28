#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, cows[50][3], data[50];
char temp;

int main() {
    for (int i = 0; i < 50; i++){
        data[i] = 1000000000;
    }
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
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i != j){
                if(cows[i][0] == 0){
                    if(cows[j][0] == 0){//east east
                        if (cows[j][1] > cows[i][1] & cows[j][2] == cows[i][2] & abs(cows[j][1] - cows[i][1]) < data[i]) data[i] = abs(cows[j][1] - cows[i][1]);
                    } else {//east north
                        if (abs(cows[i][1] - cows[j][1]) > abs(cows[i][2] - cows[j][2]) & abs(cows[j][1] - cows[i][1]) < data[i]) data[i] = abs(cows[j][1] - cows[i][1]);
                    }
                } else {
                    if(cows[j][0] == 0){//north east
                        if (abs(cows[i][1] - cows[j][1]) < abs(cows[i][2] - cows[j][2]) & abs(cows[j][2] - cows[i][2]) < data[i]) data[i] = abs(cows[j][2] - cows[i][2]);
                    } else {//north north
                        if (cows[j][2] > cows[i][2] & cows[j][1] == cows[i][1] & abs(cows[j][2] - cows[i][2]) < data[i]) data[i] = abs(cows[j][2] - cows[i][2]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++){
        if (data[i] == 1000000000){
            cout << "Infinity\n";
        } else {
            cout << data[i] << "\n";
        }
    }
    return 0;
}
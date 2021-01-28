#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, cows[50], east_cows[50][3], north_cows[50][3], e = 0, n = 0, sorted_east_cows[50][4], sorted_north_cows[50][4]; //[0] = cow_num, [1] = x, [2] = y
char temp;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> temp;
        if (temp == 'E'){
            east_cows[e][0] = i;
            cin >> east_cows[e][1] >> east_cows[e][2];
            e++;
        } else {
            north_cows[n][0] = i;
            cin >> north_cows[n][1] >> north_cows[n][2];
            n++;
        }
    }
    for (int i = 0; i < e; i++){ // east cows sort by min y
        int min_val = 1000000000, min_val_index = 0;
        for (int j = 0; j < e; j++){
            if (east_cows[j][2]<min_val){
                min_val = east_cows[j][2];
                min_val_index = j;
            }
        }
        sorted_east_cows[i][0] = east_cows[min_val_index][0];
        sorted_east_cows[i][1] = east_cows[min_val_index][1];
        sorted_east_cows[i][2] = east_cows[min_val_index][2];
        east_cows[min_val_index][2] = 1000000000;
    }
    for (int i = 0; i < n; i++){ // north cows sort by min x
        int min_val = 1000000000, min_val_index = 0;
        for (int j = 0; j < n; j++){
            if (north_cows[j][1]<min_val){
                min_val = north_cows[j][1];
                min_val_index = j;
            }
        }
        sorted_north_cows[i][0] = north_cows[min_val_index][0];
        sorted_north_cows[i][1] = north_cows[min_val_index][1];
        sorted_north_cows[i][2] = north_cows[min_val_index][2];
        north_cows[min_val_index][1] = 1000000000;
    }
    
    for (int i = 0; i < e; i++){//may need to adapt for same line occurences
        for (int j = 0; j < n; j++){
            if (sorted_east_cows[i][3] == 0 & sorted_north_cows[j][3] == 0){
                
                if (sorted_east_cows[i][1] < sorted_north_cows[j][1] & sorted_east_cows[i][2] > sorted_north_cows[j][2]){
                    if (sorted_north_cows[j][1]-sorted_east_cows[i][1]<sorted_east_cows[i][2]-sorted_north_cows[j][2]){
                        sorted_north_cows[j][3] = 1;
                        cows[sorted_north_cows[j][0]] = sorted_east_cows[i][2]-sorted_north_cows[j][2];
                    } else if (sorted_north_cows[j][1]-sorted_east_cows[i][1]>sorted_east_cows[i][2]-sorted_north_cows[j][2]) {
                        sorted_east_cows[i][3] = 1;
                        cows[sorted_east_cows[i][0]] = sorted_north_cows[j][1]-sorted_east_cows[i][1];
                        break;
                    }
                }
            }
        }
    }

   for (int i = 0; i < N; i++){
       if (cows[i] == 0){
           cout << "Infinity\n";
       } else {
           cout << cows[i] << "\n";
       }
   }
    return 0;
}
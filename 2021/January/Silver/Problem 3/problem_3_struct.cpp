#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, cows[50], e = 0, n = 0; //[0] = cow_num, [1] = x, [2] = y
struct cow{
    int num;
    int stopped;
    int x;
    int y;
} east_cows[50], north_cows[50], sorted_east_cows[50], sorted_north_cows[50];
char temp;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> temp;
        if (temp == 'E'){
            east_cows[e].num = i;
            cin >> east_cows[e].x >> east_cows[e].y;
            e++;
        } else {
            north_cows[n].num = i;
            cin >> north_cows[n].x >> north_cows[n].y;
            n++;
        }
    }
    for (int i = 0; i < e; i++){ // east cows sort by min y
        int min_val = 1000000000, min_val_index = 0;
        for (int j = 0; j < e; j++){
            if (east_cows[j].y<min_val){
                min_val = east_cows[j].y;
                min_val_index = j;
            }
        }
        sorted_east_cows[i].num = east_cows[min_val_index].num;
        sorted_east_cows[i].x = east_cows[min_val_index].x;
        sorted_east_cows[i].y = east_cows[min_val_index].y;
        east_cows[min_val_index].y = 1000000000;
    }
    for (int i = 0; i < n; i++){ // north cows sort by min x
        int min_val = 1000000000, min_val_index = 0;
        for (int j = 0; j < n; j++){
            if (north_cows[j].x<min_val){
                min_val = north_cows[j].x;
                min_val_index = j;
            }
        }
        sorted_north_cows[i].num = north_cows[min_val_index].num;
        sorted_north_cows[i].x = north_cows[min_val_index].x;
        sorted_north_cows[i].y = north_cows[min_val_index].y;
        north_cows[min_val_index].x = 1000000000;
    }
    
    for (int i = 0; i < e; i++){//may need to adapt for same line occurences
        for (int j = 0; j < n; j++){
            if (sorted_east_cows[i].stopped == 0 & sorted_north_cows[j].stopped == 0){
                
                if (sorted_east_cows[i].x < sorted_north_cows[j].x & sorted_east_cows[i].y > sorted_north_cows[j].y){
                    if (sorted_north_cows[j].x-sorted_east_cows[i].x<sorted_east_cows[i].y-sorted_north_cows[j].y){
                        sorted_north_cows[j].stopped = 1;
                        cows[sorted_north_cows[j].num] = sorted_east_cows[i].y-sorted_north_cows[j].y;
                    } else if (sorted_north_cows[j].x-sorted_east_cows[i].x>sorted_east_cows[i].y-sorted_north_cows[j].y) {
                        sorted_east_cows[i].stopped = 1;
                        cows[sorted_east_cows[i].num] = sorted_north_cows[j].x-sorted_east_cows[i].x;
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
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int data[7];

int main() {
    for (int i = 0; i < 7; i++){
        cin >> data[i];
    }
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++){
            for (int k = 0; k < 7; k++){
                int a = 0, b = 0, c = 0, rest_sorted[7] = {0, 0, 0, 0, 0, 0, 0};
                a=data[i];
                b=data[j];
                c=data[k];
                for (int l = 0; l < 7; l++){
                    if (l != i & l != j & l != k){
                        rest_sorted[l] = data[l];
                    }
                }
                sort(rest_sorted, rest_sorted+7);
                if (rest_sorted[3] == a+b & rest_sorted[4] == a+c & rest_sorted[5] == b+c & rest_sorted[6] == a+b+c){
                    cout << a << " " << b << " " << c << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
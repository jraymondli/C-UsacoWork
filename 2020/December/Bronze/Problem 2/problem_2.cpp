#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int flowers[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> flowers[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (j>=i){
                int sum_petal = 0, num_flower = 0, sub_set[j-i], okay = false;
                for (int k = i; k <= j; k++){
                    sum_petal += flowers[k];
                    num_flower++;
                    sub_set[k-i] = flowers[k];
                }
                
                if (sum_petal/num_flower*num_flower == sum_petal){ 
                    for (int m = 0; m <= j-i; m++){

                        if (sub_set[m] == sum_petal/num_flower) {
                            okay = true;
                        }
                    }
                    if (okay) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
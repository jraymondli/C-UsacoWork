//42 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int arr[101];

int main() {
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    fin >> N;
    for (int i = 0; i < N; i++) fin >> arr[i];
    sort(arr, arr + N);
    
    for (int i = 0; i < N; i++){
        int num = 1;
        int center = i, radius = 1;
        while (true){
            int rMost = center;
            int j = center + 1;
            while (arr[j] <= arr[center] + radius && j < N){
                num++;
                rMost = j;
                j++;
            }
            
            if (rMost == center) break;
            else{
                center = rMost;
                radius++;
            }
        }
        
        center = i, radius = 1;
        while (true){
            int lMost = center;
            int j = center - 1;
            while (arr[j] >= arr[center] - radius && j >= 0){
                num++;
                lMost = j;
                j--;
            }
            
            if (lMost == center) break;
            else{
                center = lMost;
                radius++;
            }
        }
        
        ans = max(ans, num);
    }
    
    fout << ans << "\n";
    return 0;
}

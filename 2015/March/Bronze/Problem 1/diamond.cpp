//11 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, K, ans = 0;

int main(void)
{
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");
    fin >> N >> K; int arr[N];
    for (int i = 0; i < N; i++) fin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; i++){
        int num = 0;
        for (int j = i; j < N; j++)
            if (arr[j] - arr[i] <= K) num++;
            
        if (num > ans) ans = num;
    }
    
    fout << ans << "\n";
    return 0;
}

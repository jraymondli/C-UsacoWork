#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
 
using namespace std;
int N = 0, K = 0;
 
int main() {
	cin >> N >> K;
    set<int> uniques[N];
    
	int changed = 1, swaps[K][2], positions[N];
    for (int i = 0; i < K; i++) cin >> swaps[i][0] >> swaps[i][1];
    for (int i = 0; i < N; i++) {
        uniques[i].insert(i+1);
        positions[i] = i+1;
    }
    
    while (changed){
        changed = 0;
        
        for (int i = 0; i < K; i++) {
            
            set<int> a = uniques[positions[swaps[i][0]-1]-1], b = uniques[positions[swaps[i][1]-1]-1];
            int x=positions[swaps[i][0]-1], y=positions[swaps[i][1]-1];

            uniques[positions[swaps[i][0]-1]-1].insert(swaps[i][1]);
            uniques[positions[swaps[i][1]-1]-1].insert(swaps[i][0]);
            if (a.size() != uniques[positions[swaps[i][0]-1]-1].size() or b.size() != uniques[positions[swaps[i][1]-1]-1].size()){
                changed = 1;
            }
            positions[swaps[i][0]-1] = y;
            positions[swaps[i][1]-1] = x;    
        }
    }
    for (int i = 0; i < N; i++) {
        cout << uniques[i].size() << "\n";
    }
}
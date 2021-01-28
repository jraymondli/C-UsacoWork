#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
int N = 0, K = 0;
 
int main() {
	cin >> N >> K;
    cout << N << K;
	int unique_positions[N], swaps[K][2], current_pos, counter = 0;
	for (int i = 0; i < K; i++) cin >> swaps[i][0] >> swaps[i][1];
    for (int i = 0; i < N; i++) {
        unique_positions[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        current_pos = i;
        for (int i = 0; i < K; i++) {
            cout << unique_positions[counter] << " " << swaps[K][0] << " " << swaps[K][1] << " " << "\n";
            if (swaps[K][0] == current_pos+1 and find(unique_positions, unique_positions + N, swaps[K][1]) != unique_positions+N) {
                unique_positions[counter] = swaps[K][1];
                current_pos = swaps[K][1]-1;
                counter++;
            }
            else if (swaps[K][1] == current_pos+1 and find(unique_positions, unique_positions + N, swaps[K][0]) != unique_positions+N){
                unique_positions[counter] = swaps[K][0];
                current_pos = swaps[K][0]-1;
                counter++;
            }
        }
        cout << counter << "\n";
        cout << "\n";
    }

}
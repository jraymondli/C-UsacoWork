//24 minutes
#include <iostream>
#include <fstream>
using namespace std;

int ans = 0, freq[52];
char arr[52];
bool visited[52];

int main() {
    ifstream fin ("circlecross.in");
    ofstream fout ("circlecross.out");
    for (int i = 0; i < 52; i++) fin >> arr[i];
    for (int i = 0; i < 51; i++){
        if (visited[arr[i] - 'A']) continue;
        for (int j = 0; j < 52; j++) freq[j] = 0;
        for (int k = i + 1; k < 52; k++){
            if (arr[k] == arr[i]) break;
            else freq[arr[k] - 'A']++;
        }
        for (int l = 0; l < 52; l++) if (freq[l] == 1) ans++;
        visited[arr[i] - 'A'] = true;
    }
    fout << ans/2 << "\n";
    return 0;
}
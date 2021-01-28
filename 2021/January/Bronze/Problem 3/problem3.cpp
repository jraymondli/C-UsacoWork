#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, pos_stalls = 0;

long long senarios = 1;

int main() 
{
	cin >> N;
	int cows[N], stalls[N];
	for (int i = 0; i < N; i++) cin >> cows[i];
	for (int i = 0; i < N; i++) cin >> stalls[i];
	sort (cows, cows+N, greater<int>());
	sort (stalls, stalls+N, greater<int>());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) if (stalls[j] >= cows[i]) pos_stalls++;
		senarios *= (pos_stalls-i);
		pos_stalls = 0;
	}
	cout << senarios;

	return 0;
}
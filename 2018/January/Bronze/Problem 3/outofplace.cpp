//46 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;

int main()
{
    ifstream fin ("outofplace.in");
    ofstream fout ("outofplace.out");
	fin >> N;
	int A1[N], A2[N], swaps = 0;
	for (int i = 0; i < N; i++){
		fin >> A1[i];
		A2[i] = A1[i];

	}
	sort(A2, A2+N);
	for (int i = 0; i < N; i++){
		if (A1[i] != A2[i]){
			swaps++;
		}
	}
	
	fout << swaps-1;
}

//46 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("outofplace.in");
ofstream fout ("outofplace.out");

int main()
{
    int N;
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

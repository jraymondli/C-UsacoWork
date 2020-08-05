// 54 min
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int K, N;
int X[100000];

int solve(int dist, int minspeed) 
{
	int lhstravel = 0;
	int rhstravel = 0;
	int timeused = 0;
	for(int currspeed = 1;; currspeed++) {
		lhstravel += currspeed;
		timeused++;
		if(lhstravel + rhstravel >= dist) return timeused;
		if(currspeed >= minspeed) {
		rhstravel += currspeed;
		timeused++;
		if(lhstravel + rhstravel >= dist) return timeused;
		}
	}
}

int main() 
{
	ifstream fin("race.in");
	ofstream fout("race.out");
	fin >> K >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> X[i];
	}
	for (int i = 0; i < N; i++)
	{
		fout << solve(K, X[i]) << "\n";
	}
	
	
}
// time: 42 min
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 100000
 
int N;
int A[MAXN];
 
int main()
{
    ifstream fin ("taming.in");
    ofstream fout ("taming.out");
	fin >> N;
	for(int i=0;i<N;i++)
		fin >> A[i];
	if(A[0] > 0)
	{
		fout << -1 << '\n';
		return 0;
	}
	A[0] = 0;
	int t = -1;
	int req = 0;
	int pos = 0;
	for(int i=N-1;i>=0;i--)
	{
		if(t != -1 && A[i] != -1 && A[i] != t)
		{
			fout << -1 << '\n';
			return 0;
		}
		if(t == -1)
			t = A[i];
		if(A[i] == -1)
			A[i] = t;
		if(A[i] == 0)
			req++;
		if(A[i] == -1)
			pos++;
		if(t > -1)
			t--;
	}
	fout << req << ' ' << req+pos << '\n';
}
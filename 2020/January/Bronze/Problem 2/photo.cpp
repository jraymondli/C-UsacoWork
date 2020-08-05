#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int N;
int b[100000], d[100000], ans[100000];
bool used[100000];
 
int main() 
{
	ifstream fin("photo.in");
	ofstream fout("photo.out");
	fin >> N;
	for(int i=0;i<N-1;i++)
	{
		fin >> b[i];
	}
	for(int i=2;i<N;i++)
	{
		d[i] = b[i-1]-b[i-2];
	}
	for(int a=1;a<=N;a++)
	{
		ans[0] = a, ans[1] = b[0] - a;
		for(int i=2;i<N;i++)
			ans[i] = ans[i-2] + d[i];
		for(int i=1;i<=N;i++)
			used[i] = 0;
		bool bad = 0;
		for(int i=0;i<N;i++)
		{
			if(used[ans[i]] || ans[i] <= 0 || ans[i] > N)
			{
				bad = 1;
				break;
			}
			used[ans[i]] = 1;
		}
		if(!bad)
		{
			for(int i=0;i<N;i++)
			{
				fout << ans[i];
				if(i<N-1) fout << ' ';
			}
			fout << '\n';
			return 0;
		}
	}
}
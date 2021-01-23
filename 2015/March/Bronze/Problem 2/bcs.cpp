//11 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, k, temp;

int main(){
  ifstream fin("bcs.in");
  ofstream fout("bcs.out");
  fin >> n >> k;
	int goal[n][n];
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
    fin >> temp; 
    goal[i][j] = temp == '#';
  }
	int grids[k][n][n];
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) for(int l = 0; l < n; l++) {
      fin >> temp; 
      grids[i][j][l] = temp == '#';
    }
	}
	for(int i = 0; i < k; i++) {
		for(int j = i+1; j < k; j++) {
			
		}
	}
	return 0;
}
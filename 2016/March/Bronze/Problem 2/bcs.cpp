//undetermined amount of time
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, k, goal[8][8], grids[10][8][8];

int compare(int a, int b){
  int a_holder[8][8], b_holder[8][8], first_row[8], first_column[8], works = true;
  
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    a_holder[i][j] = grids[a][i][j];
    b_holder[i][j] = grids[b][i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) first_row[j] = a_holder[0][j];
    for (int j = 0; j < n-1; j++) for (int k = 0; k < n; k++) a_holder[j][k] = a_holder[j+1][k];
    for (int j = 0; j < n; j++) a_holder[n-1][j] = first_row[j];

    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) first_column[k] = a_holder[k][0];
      for (int k = 0; k < n; k++) for (int l = 0; l < n-1; l++) a_holder[k][l] = a_holder[k][l+1];
      for (int k = 0; k < n; k++) a_holder[k][n-1] = first_column[k];
      for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) if (a_holder[k][l]+b_holder[k][l] != goal[k][l]) works = false;
    }
  }
  return works;
}

int main(){
  ifstream fin("bcs.in");
  ofstream fout("bcs.out");
  fin >> n >> k;
  string temp;
  for(int i = 0; i < n; i++) {
    fin >> temp;
    for(int j = 0; j < n; j++) {
      goal[i][j] = temp[j] == '#';
    }
  }
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
      fin >> temp; 
      for(int k = 0; k < n; k++) {
        grids[i][j][k] = temp[k] == '#';
      }
	  }
  }
	for(int i = 0; i < k; i++) {
		for(int j = i+1; j < k; j++) {
			if (compare(i, j)){
        fout << i+1 << " " << j+1;
        return 0;
      }
		}
	}
	return 0;
}
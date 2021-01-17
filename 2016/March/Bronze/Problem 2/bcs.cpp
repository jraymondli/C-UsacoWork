//11 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, K;

int main(){
  ifstream fin("bcs.in");
  ofstream fout("bcs.out");
  fin >> N >> K;
  char original[N];
  for (int i = 0; i<N; i++) fin >> original[i];
  char pieces[K][N];
  for (int i = 0; i<K; i++) for (int j = 0; j<N; j++) for (int k = 0; k<N; k++) fin >> pieces[i][j][k];
  for (int i = 0; i<K; i++){
    for (int j = 0; j<K; j++){
      if (i!=j){
        for (int k = 0; k<N; k++){
          for (int l = 0; l<N; l++){
            pieces[i][l]
          }
          for (int l = 0; l<N; l++){
            a
          }
        }
      }
    }
  }
}
//44 minutes
#include <iostream>
#include <fstream>
using namespace std;
 
int N;

int main()
{
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
	fin >> N;
	int A[N][2];
	for (int i = 0; i < N; i++){
		fin >> A[i][0] >> A[i][1];
	}
	int max_val = 0, min_take_time = 0;
	for (int i = 0; i < N; i++){
		 if (min_take_time < A[i][1]){
			 min_take_time = A[i][1];
		 }
	}
	for (int i = 0; i < N; i++){
		int value = 0;
		for (int j = 0; j < min_take_time; j++){
			for (int k = 0; k < N; k++){
				if (A[k][0] <= j and j < A[k][1] and k != i){
					value += 1;
					break;
				}
			}
		}
		if (value > max_val){
			max_val = value;
		}
	}
	fout << max_val;
	return 0;
}

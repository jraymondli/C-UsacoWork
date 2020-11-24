//undetermined
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("outofplace.in");
ofstream fout ("outofplace.out");
int main()
{
    int N, temp = 0, b_index = -1, b_val = -1, swaps, supposed_index, temp1 = 0, temp2 = 0;
	fin >> N;
	int A[N];
	for (int i = 0; i < N; i++){
		fin >> A[i];
	}
	for (int i = 0; i < N; i++){
		if ((temp1 <= A[i]) & (temp2 > A[i] or temp2 < temp1)){
			b_index = i-1;
			b_val = A[i-1];
			break;
		}
		temp1 = temp2;
		temp2 = A[i];
	}
	if (b_index == -1){
		b_index = N-1;
		b_val = A[N];
	}
	temp = 0;
	for (int i = 0; i < N; i++){
		if (b_val >= temp & b_val <= A[i] & i != b_index & i-1 != b_index){
			if (b_index > i) supposed_index = i-1;
			if (b_index < i) supposed_index = i;
			if ((A[i] == b_val) & b_index > i) supposed_index = i;
			if ((temp == b_val) & b_index > i) supposed_index = i-1;
			if ((A[i] == b_val) & b_index < i) supposed_index = i;
			if ((temp == b_val) & b_index < i) supposed_index = i-1;
			break;
		}
		temp = A[i];
	}
	cout << supposed_index << "\n" << b_index << "\n";
	vector<int> used_nums;
	for (int i = 0; i < N; i++){
		if (std::find(used_nums.begin(), used_nums.end(), A[i]) == used_nums.end() & ((i > supposed_index & i < b_index) or (i < supposed_index & i > b_index))){
			used_nums.push_back(A[i]);
		}
	}
	for (int i = 0; i < used_nums.size(); i++){
		cout << used_nums[i] << "\n";
	}
	fout << used_nums.size();
}

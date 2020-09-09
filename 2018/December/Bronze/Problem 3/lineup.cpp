#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("lineup.out");
ifstream fin("lineup.in");

string names[8] = {
	"Beatrice",
	"Belinda",
	"Bella",
	"Bessie",
	"Betsy",
	"Blue",
	"Buttercup",
	"Sue"
};

int n, order[8];
int conditions[7][2];

int getIndex(string a) {
	for (int i = 0; i < 8; i++)
		if (names[i] == a)
			return i;
	return -1;
}

bool works() {
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 7; j++)
			if ((conditions[i][0] == order[j] && conditions[i][1] == order[j+1])
			 || (conditions[i][1] == order[j] && conditions[i][0] == order[j+1])) {
				c++;
				break;
			}
	return (c == n);
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		string temp1, temp2;
		string trash;

		fin >> temp1 >> trash >> trash >> trash >> trash >> temp2;
		conditions[i][0] = getIndex(temp1), conditions[i][1] = getIndex(temp2);
	}
	for (int i = 0; i < 8; i++)
		order[i] = i;

	while (!works()) {
		if (!next_permutation(order, order+8))
			break;
	}

	for (int i = 0; i < 8; i++)
		fout << names[order[i]] << '\n';
	
	return 0;
}
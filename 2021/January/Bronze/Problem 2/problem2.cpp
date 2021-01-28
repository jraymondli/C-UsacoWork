#include <iostream>
#include <fstream>

using namespace std;

int N, E = 0, O = 0, temp, groups = 0, finder = 1;

int main() 
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp % 2 == 0) E ++;
		if (temp % 2 == 1) O ++;
	}

	while (true) {
		if (finder == 1){
			if (E > 0) E -= 1;
			else if (E <= 0) O -= 2;
		} else if (finder == -1){
			O-=1;
		}
		groups ++;
		if (O < 0){
			if (E > 0){
				cout << groups - 1;
				break;
			}
			if (E == 0){
				cout << groups - 2;
				break;
			}
		}
		if (E == 0 and O == 0){
			cout << groups;
			break;
		}
		finder *= -1;
	}

	return 0;
}
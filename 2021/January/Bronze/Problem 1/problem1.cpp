#include <iostream>
#include <fstream>

using namespace std;

int numbered_alphabet[26], numbered_heard[1000], heard_len, counter = 0, matched_letter = 0;

string alphabet, heard;

int main() 
{
	cin >> alphabet >> heard;
	for (int i = 0; i < 26; i++) numbered_alphabet[i] = (alphabet[i]-96);
	heard_len = heard.size();
	for (int i = 0; i < heard_len; i++) numbered_heard[i] = (heard[i]-96);
	while(true){
		for (int i = 0; i < 26; i++){
			if (numbered_alphabet[i] == numbered_heard[matched_letter]){
				matched_letter++;
			}
		}

		counter++;
		if (matched_letter == heard_len) break;
	}
	cout << counter;
	return 0;
}
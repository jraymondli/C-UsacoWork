//71 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
 
int main(void)
{
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    int N;
    fin >> N;
    struct blocks{
        int letters[26];
    } base, sets[N][2];
    for (int i = 0; i<26; i++){
        base.letters[i] = 0;
    }
    for (int i=0; i<N; i++) { 
        for (int j = 0; j < 26; j++){
            sets[i][0].letters[j] = 0;
            sets[i][1].letters[j] = 0;
        }
    }
    string temp1, temp2;
    for (int i=0; i<N; i++){
        fin >> temp1;
        fin >> temp2;
        for (int j=0; j<temp1.length(); j++){
            sets[i][0].letters[temp1[j]-97]++;
            cout << temp1[j]-97 << " ";
        }
        for (int j=0; j<temp2.length(); j++){
            sets[i][1].letters[temp2[j]-97]++;
            cout << temp2[j]-97 << " ";
        }
        cout << "\n";
    }
    for (int i=0; i<N; i++) { 
        for (int j = 0; j < 26; j++){
            cout << sets[i][0].letters[j] << " " << sets[i][1].letters[j] << "   ";
            base.letters[j] += max(sets[i][0].letters[j], sets[i][1].letters[j]);
        }
        cout << "\n";
    }
    for (int i=0; i<26; i++)
        fout << base.letters[i] << "\n";
    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin ("whereami.in");
    ofstream fout ("whereami.out");
    int n;
    string s;
    fin >> n >> s;
    for(int guess = 1; guess <= n; guess++) 
    {
        bool good = true;
        for(int i = 0; i + guess <= n; i++) 
        {
            for(int j = 0; j < i; j++) 
            {
                if(s.substr(i, guess) == s.substr(j, guess)) 
                {
                    good = false;
                }
            }
        }
        if(good) 
        {
            fout << guess << "\n";
            break;
        }
    }
}
//45 minutes
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int cows[100][2], cows_milk[3] = {7, 7, 7}, cows_max[3] = {1, 1, 1};
 
int main(void)
{
    ifstream fin ("measurement.in");
    ofstream fout ("measurement.out");
    int N, temp;
    string cow, value;
    fin >> N;
    for (int i=0; i<N; i++){
        fin >> temp;
        fin >> cow;
        if (cow == "Bessie") cows[temp-1][0] = 1;
        if (cow == "Elsie") cows[temp-1][0] = 2;
        if (cow == "Mildred") cows[temp-1][0] = 3;
        fin >> cows[temp-1][1];
    }
    int changes = 0, max_val;
    for (int i=0; i<100; i++) { 
        if (cows[i][0] != 0){
            int new_max[3] = {0, 0, 0}; 
            cows_milk[cows[i][0]-1] += cows[i][1];
            
            if (cows_milk[0] >= cows_milk[1] & cows_milk[0] >= cows_milk[2]) max_val = cows_milk[0];
            if (cows_milk[1] >= cows_milk[0] & cows_milk[1] >= cows_milk[2]) max_val = cows_milk[1];
            if (cows_milk[2] >= cows_milk[1] & cows_milk[2] >= cows_milk[0]) max_val = cows_milk[2];
            for (int i=0; i<3; i++) { 
                if (cows_milk[i] == max_val) new_max[i] = 1;
            }
            if (new_max[0] != cows_max[0] or new_max[1] != cows_max[1] or new_max[2] != cows_max[2]) {
                cows_max[0] = new_max[0];
                cows_max[1] = new_max[1];
                cows_max[2] = new_max[2];
                changes++;
            }

        }
    }
    fout << changes << "\n";
    return 0;
}

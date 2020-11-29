/* undetermined because of memory issues
needed to set values of all vars before hand
main difference was milk_generated[7]
giving an initial output of {4, 0, 0, -(undetermined large number), ~30000, -(undetermined large number)}
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    string temp_str = "";
    char cows[] = {'B', 'E', 'D', 'G', 'A', 'M', 'H'}, second_mins[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int N = 0, temp_val = 0, milk_generated[7] = {0, 0, 0, 0, 0, 0, 0};
    fin >> N;
    for (int i = 0; i < N; i++){
        fin >> temp_str >> temp_val;
        if (temp_str == "Bessie") milk_generated[0] += temp_val;
        if (temp_str == "Elsie") milk_generated[1] += temp_val;
        if (temp_str == "Daisy") milk_generated[2] += temp_val;
        if (temp_str == "Gertie") milk_generated[3] += temp_val;
        if (temp_str == "Annabelle") milk_generated[4] += temp_val;
        if (temp_str == "Maggie") milk_generated[5] += temp_val;
        if (temp_str == "Henrietta") milk_generated[6] += temp_val;
    }
    
    int first_min = 10000, second_min = 10000, cows_good = 0;
    for (int i = 0; i < 7; i++){
        if(milk_generated[i] < first_min){
            second_min = first_min;
            first_min = milk_generated[i];
        } else if (milk_generated[i] < second_min & milk_generated[i] > first_min){
            second_min = milk_generated[i];
        }
    }
    for (int i = 0; i < 7; i++){
        if (milk_generated[i] == second_min) {
            second_mins[i] = cows[i];
            cows_good++;
        }
    }
    if (cows_good == 1){
        for (int i = 0; i < 7; i++){
            if (second_mins[i] == 'B' or second_mins[i] == 'E' or second_mins[i] == 'D' or second_mins[i] == 'G' or second_mins[i] == 'A' or second_mins[i] == 'M' or second_mins[i] == 'H'){
                if (i == 0) fout << "Bessie";
                if (i == 1) fout << "Elsie";
                if (i == 2) fout << "Daisy";
                if (i == 3) fout << "Gertie";
                if (i == 4) fout << "Annabelle";
                if (i == 5) fout << "Maggie";
                if (i == 6) fout << "Henrietta";
            }
        }
    } else {
        fout << "Tie";
    }
    return 0;
}

//26 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int N, cow_pos[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, temp_pos, temp_id, conf_cross = 0;
int main(void)
{
    ifstream fin ("crossroad.in");
    ofstream fout ("crossroad.out");
    fin >> N;
    for (int i = 0; i < N; i++){
        fin >> temp_id >> temp_pos;
        if (cow_pos[temp_id-1] != temp_pos){
            if (cow_pos[temp_id-1] != -1){
                conf_cross++;
            }
        }
        cow_pos[temp_id-1] = temp_pos;
    }
    fout << conf_cross;
}
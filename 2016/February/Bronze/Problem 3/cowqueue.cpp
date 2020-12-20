//22 minutes
#include <iostream>
#include <fstream>
using namespace std;

int N, data[100][2], sorted_data[100][2], cur_time = 0;

int main() {
    ifstream fin ("cowqueue_bronze_feb17/2.in");
    ofstream fout ("cowqueue.out");
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> data[i][0] >> data[i][1];
    }
    for (int i = 0; i < N; i++){
        int min_num = 1000000, min_num_index = 1000000;
        for (int j = 0; j < N; j++){
            if (data[j][0] < min_num){
                min_num = data[j][0];
                min_num_index = j;
            }
        }
        sorted_data[i][0] = min_num;
        sorted_data[i][1] = data[min_num_index][1];
        data[min_num_index][0] = 1000000;
    }
    for (int i = 0; i < N; i++){
        if (sorted_data[i][0] > cur_time){
            cur_time = sorted_data[i][0]+sorted_data[i][1];
        } else {
            cur_time += sorted_data[i][1];
        }
    }
    fout << cur_time << "\n";
    return 0;
}
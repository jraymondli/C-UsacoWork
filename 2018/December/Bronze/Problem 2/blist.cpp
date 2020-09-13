//35 min
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin ("blist.in");
    ofstream fout ("blist.out");
    int n;
    fin >> n;
    int time_start[n], time_end[n], bused[n];
    for(int i = 0; i < n; i++) 
    {
        fin >> time_start[i] >> time_end[i] >> bused[i];
    }
    int max_buckets;
    for(int i = 1; i < 1001; i++) 
    {
        int curr_b = 0;
        for(int j = 0; j < n; j++) 
        {
            if (i >= time_start[j] & i <= time_end[j])
            {
                curr_b += bused[j];
            }
        }
        if (curr_b > max_buckets)
        {
            max_buckets = curr_b;
        }
    }
    fout << max_buckets << "\n";
}
//43 min
#include <iostream>
#include <fstream>
using namespace std;

int N, x[100], passto[100];

int target(int i)
{
    int left_nbr=-1, left_dist = 1000;
    int right_nbr=-1, right_dist = 1000;                                                                                                 
    for (int j=0; j<N; j++)
        if (x[j] < x[i] and x[i]-x[j] < left_dist) { left_nbr = j; left_dist = x[i]-x[j]; }
    for (int j=0; j<N; j++)
        if (x[j] > x[i] and x[j]-x[i] < right_dist) { right_nbr = j; right_dist = x[j]-x[i]; }

    if (left_dist <= right_dist) return left_nbr;
    return right_nbr;
}

int main(void)
{
    ifstream fin ("hoofball.in");
    ofstream fout ("hoofball.out");
    fin >> N;
    for (int i=0; i<N; i++) fin >> x[i];
    for (int i=0; i<N; i++) passto[target(i)]++;

    int answer = 0;
    for (int i=0; i<N; i++) {
        if (passto[i] == 0) answer++;                                                       
        if (i < target(i) and target(target(i))==i and passto[i]==1 and passto[target(i)]==1)
        answer++;                                                                                  
    }

    fout << answer << "\n";
    return 0;
}

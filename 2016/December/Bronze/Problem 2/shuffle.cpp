#include <iostream>
#include <fstream>
using namespace std;
 
int a[100];
int order[100];
int original_order[100];
 
int main(void)
{
    ifstream fin ("shuffle.in");
    ofstream fout ("shuffle.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++){
        fin >> a[i];
        cout << a[i] << "\n";
    }
    for (int i=0; i<N; i++) {
        fin >> order[i];
        cout << order[i] << "\n";
    }
    for (int i=0; i<3; i++) {    
        for (int j=0; j<N; j++) original_order[j] = order[a[j]-1];
        for (int j=0; j<N; j++) order[j] = original_order[j];
    }
    
    for (int i=0; i<N; i++)
        fout << order[i] << "\n";
    return 0;
}

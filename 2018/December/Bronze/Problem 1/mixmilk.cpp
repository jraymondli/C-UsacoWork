//22 min
#include <iostream>
#include <fstream>
using namespace std;

int buckets[3], buckets_cap[3];
 
int main()
{
    ifstream fin ("mixmilk.in");
    ofstream fout ("mixmilk.out");
    fin >> buckets_cap[0] >> buckets[0] >> buckets_cap[1] >> buckets[1] >> buckets_cap[2] >> buckets[2];
    for (int i = 0; i < 100; i++)
    {
        cout << buckets[0] << "\n" << buckets[1] << "\n" << buckets[2] << "\n";
        if (buckets[i%3] > buckets_cap[(i+1)%3]-buckets[(i+1)%3])
        {
            buckets[i%3] = buckets[i%3] + buckets[(i+1)%3] - buckets_cap[(i+1)%3];
            buckets[(i+1)%3] = buckets_cap[(i+1)%3];
        } else 
        {
            buckets[(i+1)%3] += buckets[i%3];
            buckets[i%3] = 0;
        }
    }
    fout << buckets[0] << "\n" << buckets[1] << "\n" << buckets[2] << "\n";
    return 0;
}

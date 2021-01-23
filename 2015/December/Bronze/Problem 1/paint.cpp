// 19 minutes
#include <iostream>
#include <fstream>
using namespace std;

int a, b, c, d, painted = 0;

int main(void)
{
  ifstream fin ("paint.in");
  ofstream fout ("paint.out");
  
  fin >> a >> b >> c >> d;
  for (int i = 0; i <= 100; i++){
    if ((i >= a and i < b) or (i >= c and i < d)){
      painted++;
    }
  }
  fout << painted;
  return 0;
}

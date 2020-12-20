// 23 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int x1, y1, x2, y2, x3, x4, y3, y4;

int main(void)
{
  ifstream fin ("square.in");
  ofstream fout ("square.out");
  
  fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  fout << max(max(x2, x4)-min(x1, x3), max(y2, y4)-min(y1, y3)) * max(max(x2, x4)-min(x1, x3), max(y2, y4)-min(y1, y3));
 
  return 0;
}

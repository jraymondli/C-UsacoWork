// 48 minutes
#include <iostream>
#include <fstream>
using namespace std;

int area(int r[4])
{
  return (r[2] - r[0]) * (r[3] - r[1]);
}
 
int intersect_area(int p[4], int q[4])
{
  int x_overlap = max(0, min(p[2], q[2]) - max(p[0], q[0]));
  int y_overlap = max(0, min(p[3], q[3]) - max(p[1], q[1]));
  return x_overlap * y_overlap;
}
 
int main(void)
{
  ifstream fin ("billboard.in");
  ofstream fout ("billboard.out");
  
  int a[4], b[4], t[4];  //x1, y1, x2, y2
 
  fin >> a[0] >> a[1] >> a[2] >> a[3];
  fin >> b[0] >> b[1] >> b[2] >> b[3];
  fin >> t[0] >> t[1] >> t[2] >> t[3];
 
  fout << area(a) + area(b) - intersect_area(a,t) - intersect_area(b,t) << "\n";
 
  return 0;
}

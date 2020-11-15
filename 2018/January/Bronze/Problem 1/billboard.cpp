// 46 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;

int covered(int x, int y, int x1, int y1, int x2, int y2){
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int main(){
    ifstream fin ("billboard.in");
    ofstream fout ("billboard.out");
    fin >> ax1 >> ay1 >> ax2>> ay2 >> bx1 >> by1 >> bx2 >> by2;
    int cornerCover = 0;
	if(covered(ax1, ay1, bx1, by1, bx2, by2)) cornerCover++;
	if(covered(ax1, ay2, bx1, by1, bx2, by2)) cornerCover++;
	if(covered(ax2, ay1, bx1, by1, bx2, by2)) cornerCover++;
	if(covered(ax2, ay2, bx1, by1, bx2, by2)) cornerCover++;
    if(cornerCover < 2) {
		fout << abs((ax2-ax1))*abs((ay2-ay1));
	}
	// if all 4 corners are covered, then nothing needs to be covered
	else if(cornerCover == 4) {
		fout << 0;
	}
	else {
		// we only need to cover some portion of the rectangle
		// find the intersection of the two rectangles
		int xL = max(ax1, bx1);
		int xR = min(ax2, bx2);
		int yL = max(ay1, by1);
		int yR = min(ay2, by2);
		// subtract away the area of the intersection
		fout << (ax2-ax1)*(ay2-ay1) - (xR-xL)*(yR-yL);
	}
}
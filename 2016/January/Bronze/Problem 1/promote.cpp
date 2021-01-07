//11 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int bronze[2], silver[2], gold[2], platinum[2], promo[3];

int main(void)
{
    ifstream fin ("promote.in");
    ofstream fout ("promote.out");
    fin >> bronze[0] >> bronze[1] >> silver[0] >> silver[1] >> gold[0] >> gold[1] >> platinum[0] >> platinum[1];
    promo[2] = platinum[1] - platinum[0];
    gold[0] -= platinum[1] - platinum[0];
    promo[1] = gold[1] - gold[0];
    silver[0] -= gold[1] - gold[0];
    promo[0] = silver[1] - silver[0];
    bronze[0] -= silver[1] - silver[0];
    fout << promo[0] << "\n" << promo[1] << "\n" << promo[2] << "\n";
    return 0;
}

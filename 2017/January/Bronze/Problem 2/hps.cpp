//19 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int game_winner(int a, int b, int c, int roll_1, int roll_2){
    int game_key[3] = {a, b, c};
    if (game_key[roll_1-1] == roll_2 or roll_1 == roll_2) {
        return false;
    } else {
        return true;
    }
}

int N;
int main(void)
{
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");
    fin >> N;
    int games[N][2], win_keys[2][3] = {{2, 3, 1}, {3, 1, 2}}, max_games_won = 0;
    for (int i = 0; i < N; i++){
        fin >> games[i][0] >> games[i][1];
    }
    for (int i = 0; i < 2; i++){
        int games_won = 0;
        for (int j = 0; j < N; j++){
            if (game_winner(win_keys[i][0], win_keys[i][1], win_keys[i][2], games[j][0], games[j][1])) games_won++;
        }
        if (games_won > max_games_won) max_games_won = games_won;
    }
    fout << max_games_won;
}
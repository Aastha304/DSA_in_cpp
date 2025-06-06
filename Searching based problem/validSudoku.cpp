#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board){
    bool rows[9][9] = {};
    bool cols[9][9] = {};
    bool boxes[9][9] = {};

    for(int r=0; r<9 ; r++){
        for(int c =0; c<9 ; c++){
            char ch = board[r][c];
            if( ch == '.') continue;

            int num = ch - '1';
            int boxIndex = (r/3)*3 + c/3;

            if( rows[r][num] || cols[c][num] || boxes[boxIndex][num])
            return false;

            rows[r][num] = cols[c][num] = boxes[boxIndex][num] = true;
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board = {
                                 {'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','6','.','.','.','.','2','8','.'}
                                };
    cout<< isValid(board);
    return 0;
}
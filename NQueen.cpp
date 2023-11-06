#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col, int n)
{
    // Up
    for (int i = row - 1; i >= 0; i--){
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    // Diagonally Left
    for (int i = row - 1, j = col -1; i>=0 && j>= 0; i--,j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    // Diagonally Right
    for (int i = row - 1, j = col + 1; i>=0 && j < n; i--,j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool NQueens(vector<vector<char>> &board, int row ,int n){
    if(row == n)
        return true;
    for(int i = 0;i<n;i++){
        if(isSafe(board,row,i,n)){
            board[row][i]='Q';
            if(NQueens(board,row+1,n)){
                return true;
            }
            board[row][i] = '*';
        }
    }
    return false;
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '*'));
    if (NQueens(board, 0, n))
    {
        printSolution(board, n);
    }
    else
    {
        cout << "Solution doesn't exist!\n";
    }
    return 0;
}
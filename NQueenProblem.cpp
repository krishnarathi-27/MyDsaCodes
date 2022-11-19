#include<bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, int n, vector<string> &board){

    int duplicateRow = row;
    int duplicateCol = col;

    while(row>=0 && col >=0)
    {
        if(board[row][col] == 'Q')      return false;
        row--;
        col--;
    }

    row = duplicateRow;
    col = duplicateCol;

    while( col >=0)
    {
        if(board[row][col] == 'Q')      return false;
        col--;
    }

    row = duplicateRow;
    col = duplicateCol;
    
    while(row<n && col>=0)
    {
        if(board[row][col] == 'Q')      return false;
        row++;
        col--;
    }

    return true;
}

void possibleSolution(int col, int n, vector<string> &board)
{
    if(col == n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << board[i][j] << " ";

            cout << endl;
        }

        cout << endl;
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(isSafe(row,col,n,board)){

            board[row][col] = 'Q';
            possibleSolution(col+1,n,board);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;

    cout << "Enter the value of N :- " << endl;
    cin >> n;

    vector<string> board(n);

    string s(n,'.');

    for(int i=0;i<n;i++)
        board[i] = s;

    cout << "The possible positions to place a queen are:- " << endl;

    possibleSolution(0,n,board);

    return 0;
}
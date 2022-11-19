#include<bits/stdc++.h>

using namespace std;

void problemSolution(int col, int n, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
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
        if(leftRow[row]==0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            problemSolution(col+1, n, board, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the value of n :- " << endl;
    cin >> n;

    vector<string> board(n);

    string s(n,'.');

    for(int i=0;i<n;i++)
        board[i] = s;

    vector<int> leftRow(n,0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);

    problemSolution(0, n, board, leftRow, upperDiagonal, lowerDiagonal);

    return 0; 
}
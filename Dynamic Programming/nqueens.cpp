#include<bits/stdc++.h>
using namespace std;

# define n 4

void print(int board[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool issafe(int board[n][n],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(i=row,j=col;j>=0&&i<n;i++,j--)
        if(board[i][j])
        return false;
    return true;
}

bool solveNQ(int board[n][n],int col)
{
    if(col>=n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(issafe(board,i,col))
        {
            board[i][col]=1;
            if(solveNQ(board,col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}

bool NQ()
{
    int board[n][n];
    memset(board,0,sizeof(board));
    if((solveNQ(board,0))==false)
    {
        cout<<"No solution\n";
        return false;
    }
    print(board);
    return true;
}

int main()
{
    //cin>>n;
    NQ();
    return 0;

}

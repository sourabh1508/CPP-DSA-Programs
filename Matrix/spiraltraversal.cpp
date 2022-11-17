#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int mat[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    int row_start = 0, row_end = n-1, col_start = 0, col_end = m-1;

    while (row_start<=row_end && col_start<=col_end)
    {
        for(int c=col_start;c<=col_end;c++)
        {
            cout<<mat[row_start][c]<<" ";
        }
        row_start++;

        for(int r=row_start;r<=row_end;r++)
        {
            cout<<mat[r][col_end]<<" ";
        }
        col_end--;

        if(row_start<=row_end){
            for(int c=col_end;c>=col_start;c--)
            {
                cout<<mat[row_end][c]<<" ";
            }
        }
        row_end--;

        if(col_start<=col_end){
            for(int r=row_end;r>=row_start;r--)
            {
                cout<<mat[r][col_start]<<" ";
            }
        }
        col_start++;
    }

    return 0;   
}
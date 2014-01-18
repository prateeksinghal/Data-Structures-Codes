/* This Program rotates matrix by 90 DEGREE
By: Prateek Singhal */

#include<iostream>
int main()
{
    int i,j,r,c,temp;
    cin >> r >> c;
    int arr[r][c];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin >> arr[i][j];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i<j)
            {
                temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
    
     for(i=0;i<c;i++)
        for(j=0;j<r/2;j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[i][r-j-1];
            arr[i][r-j-1]=temp;
        }

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
    


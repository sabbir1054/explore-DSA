#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
        
    }

    //find max
    int max = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]>max)
            {
                max = arr[i][j];
            }
        }
    }
    //counting array frequency
    int countArr[max + 1] = {0};
         
    for (int i = 0; i < row; i++)
    {
        
        for (int j = 0; j < col; j++)
        {   
            if (countArr[arr[i][j]]==0)
            {
                cout <<" "<< arr[i][j]<<" ";
                countArr[arr[i][j]]++;
            }else
            {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

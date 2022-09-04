#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int row, col, n;
    cin >> n;
    row = n;
    col = n;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int mid = (n / 2);
    int sum = 0;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {

            if (j == mid)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
            else if (i == 0 && j < mid)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
            else if (i < mid && j == col - 1)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
            else if (i == mid)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
            else if (i > mid && j == 0)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
            else if (i == row - 1 && j > mid)
            {
                sum = sum + arr[i][j];
                arr[i][j] = 0;
            }
        }
    }

    cout << sum;

    return 0;
}

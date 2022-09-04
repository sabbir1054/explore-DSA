#include <bits/stdc++.h>
using namespace std;
// array max value finding function
int findMax(int arr[], int size)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int maxVal = findMax(arr, size);
    // frequency array
    int freArr[maxVal + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        freArr[arr[i]]++;
    }
    // array sorting
    sort(arr, arr + size);
    // check for remove duplicate
    int check[maxVal + 1] = {0};
    // display frequency
    for (int i = 0; i < size; i++)
    {

        if (check[arr[i]] == 0)
        {
            cout << arr[i] << " => " << freArr[arr[i]] << endl;
            check[arr[i]]++;
        }
    }

    return 0;
}

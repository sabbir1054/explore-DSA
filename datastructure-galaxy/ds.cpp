#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int num, int lb, int up)
{
    

    if (lb <= up)
    {
        int mid = lb + (up - lb) / 2;
        cout << "Low =" << lb << " High = " << up<<" Mid = "<<mid<<endl;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            return binarySearch(arr, num, mid + 1, up); // right
        }
        else
        {
            return binarySearch(arr, num, lb, mid - 1); // left
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int num;
    cout << "Please input the value you want to find " << endl;
    cin >> num;

    int index;
    index = binarySearch(arr, num, 0, size - 1);

    if (index != -1)
    {
        cout << "Position : " << index + 1;
    }
    else
    {
        cout << "Not found";
    }

    return 0;
}

/*
15
10 20 30 40 50 60 70 80 90 100 110 120 130 140 150

 */
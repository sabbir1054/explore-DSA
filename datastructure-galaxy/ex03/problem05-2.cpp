// #include <bits/stdc++.h>
// using namespace std;

// int binarySearch(int arr[], int num, int lb, int up)
// {
//     int i = 1;

//     while (lb <= up)
//     {
//         cout << "Step : " << i << endl;
//         int mid = lb + (up - lb) / 2;
//         cout << "Lower index : " << lb << " Upper index : " << up << endl;
//         cout << "Desired num :" << num << " --> Not equal " <<"Pos : "<<mid<<"Value :"<< arr[mid] << endl
//              << endl;
//         if (arr[mid] == num)
//         {
//             return mid;
//         }
//         else if (arr[mid] < num)
//         {
//             // lb = mid + 1;
//             lb = mid - 1;
//         }
//         else
//         {
//             // up = mid - 1;
//             up = mid + 1;
//         }
//         i++;
//     }

//     return -1;
// }

// int main(int argc, char const *argv[])
// {
//     int size;
//     cin >> size;
//     int arr[size];
//     for (int i = 0; i < size; i++)
//     {
//         cin >> arr[i];
//     }
//     int num;
//     cout << "Please input the value you want to find " << endl;
//     cin >> num;
//     sort(arr,arr+size);
//     int index;
//     index = binarySearch(arr, num, 0, size - 1);

//     if (index != -1)
//     {
//         cout << "Position : " << index + 1;
//     }
//     else
//     {
//         cout << "Desired number Not found";
//     }

//     return 0;
// }

// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to search if element X
// is present in reverse sorted array
int binarySearch(int arr[], int N, int X)
{
    // Store the first index of the
    // subarray in which X lies
    int start = 0;

    // Store the last index of the
    // subarray in which X lies
    int end = N;

    while (start <= end)
    {
        
        // Store the middle index
        // of the subarray
        int mid = start + (end - start) / 2;
        cout << "Step : "
             << "== " << endl;
        cout << "Lower index : " << start << " Upper index : " << end-1 << endl;
        cout << "Desired num :" << X << " --> Not equal "
             << "Pos : " << mid << "  Value : " << arr[mid] << endl
             << endl;
        // Check if value at middle index
        // of the subarray equal to X
        if (X == arr[mid])
        {

            // Element is found
            return mid;
        }

        // If X is smaller than the value
        // at middle index of the subarray
        else if (X < arr[mid])
        {

            // Search in right
            // half of subarray
            start = mid + 1;
        }
        else
        {

            // Search in left
            // half of subarray
            end = mid - 1;
        }
    }

    // If X not found
    return -1;
}

// Driver Code
int main()
{
    int arr[] = {35 ,34 ,32 ,30 ,29 ,27 ,26 ,25 ,24 ,22 ,21 ,19 ,17 ,16 ,15 ,14 ,13 ,12 ,11 ,10 ,8};
    int N = sizeof(arr) / sizeof(arr[0]);
    int X = 19;
    cout << binarySearch(arr, N, X);
    return 0;
}

/*
21
35 34 32 30 29 27 26 25 24 22 21 19 17 16 15 14 13 12 11 10 8
 */
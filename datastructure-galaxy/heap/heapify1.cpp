#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}
void heapify(int arr[], int n, int current)
{
    // cout << "step : 1 " ;
    // printArray(arr, n);
    int largest = current;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != current)
    {
        swap(arr[current], arr[largest]);
        heapify(arr, n, largest);
    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> arr[i];
    }
    printArray(arr, n);
    cout << endl;
    // heapify
    int nonLeafStart = (n / 2) - 1;

    for (int i = nonLeafStart; i >= 0; i--)
    {
        /* code */
        heapify(arr, n, i);
    }
    printArray(arr, n);

    return 0;
}
/* 
9
2 10 1 5 4 8 3 8 7

8
10 40 20 8 99 8 15 17
 */
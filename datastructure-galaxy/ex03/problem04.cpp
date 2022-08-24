#include<bits/stdc++.h>
using namespace std;


void showArr(int size,int arr[]){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
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

    cout << "Unsorted Array : ";
    showArr(size, arr);
    cout << endl
         << "Start Insertion sort " << endl;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        cout << "Step " << i << " : "<<"Key "<<key<<" -> ";
        while (j>=0&&arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        showArr(size,arr);
        cout << endl;
    }

    cout<< endl << "Sorted Array: ";
    showArr(size, arr);

    return 0;
}

/* 
6
5 1 3 8 2 2
 */
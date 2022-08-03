#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        /* code */
        cin >> arr[i];
    }

    for (int i = size - 1,j=0; i <= 0,j<size; i--,j++)
    {
        if (i>j)
        {
            swap(arr[i], arr[j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    
    return 0;
}
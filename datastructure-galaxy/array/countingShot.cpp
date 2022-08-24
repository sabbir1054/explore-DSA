#include<bits/stdc++.h>
using namespace std;

void showElement(int arr[],int size){
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

    //finding max
    int max = *max_element(arr, arr + size);

    //counting arr
    int count[max + 1] = {0};

    //frequency
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    //cumulative sum
    for (int i = 0; i <max+1; i++)
    {
        count[i] += count[i - 1];
    }

    int final[size - 1];
    for (int i = size - 1, j = 1; i >= 0; i--,j++)
    {
       
        cout << endl;
        count[arr[i]]--;
        int k = count[arr[i]];
        final[k] = arr[i];
    }

    // showElement(final, size);

    return 0;
}
/* 
8
7 2 9 2 7 4 5 1
 */
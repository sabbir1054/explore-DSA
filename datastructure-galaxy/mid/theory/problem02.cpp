//counting shot

#include <bits/stdc++.h>
using namespace std;

void showElement(int arr[], int size)
{
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

    // finding max
    int max = *max_element(arr, arr + size);
    cout << "Max = " << max << endl;

    // counting arr
    int count[max + 1] = {0};
    cout << "Make counter array: ";
    showElement(count, max + 1);
    // frequency
    cout << "\nElement\tFrequency" << endl;
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
        
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " --> " << count[arr[i]]<<endl;
    }
    

    // cumulative sum
    cout << "Cumulative sum of elements : ";
    for (int i = 0; i < max + 1; i++)
    {
        
        count[i] += count[i - 1];
        
    }
    showElement(count, max + 1);
    cout << endl;
    int final[size - 1]={0};
    cout << "New array: ";
    showElement(final, size - 1);
    cout << endl;
    for (int i = size - 1, j = 1; i >= 0; i--, j++)
    {
        cout << "Step " << j<<": ";
        count[arr[i]]--;
        int k = count[arr[i]];
        final[k] = arr[i];
        showElement(final, size);
        cout << endl;
    }

    showElement(final, size);

    return 0;
}
/*
8
3 3 1 7 7 4 4 5

 */
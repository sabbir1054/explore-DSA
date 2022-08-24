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
    cout << "Find max element : " << max<<endl;
    //counting arr
    int count[max + 1] = {0};
    cout << "Make counter array :";
    showElement(count, max + 1);
   
    
    //frequency
    for (int i = 0; i < size; i++)
    { 
        count[arr[i]]++;
    }
     cout << endl
         << "Get frequency of array element " << endl;
    //show
     cout << "Element\t\tFrequency " << endl;
     for (int i = 0; i < size; i++)
     {
         cout << arr[i] << "\t-->\t" << count[arr[i]] << endl;
    }

    cout << "Cumulative Sum of elements : ";
    //cumulative sum
    for (int i = 0; i <max+1; i++)
    {
        
        count[i] += count[i - 1];
        cout << count[i]<<" ";
    }
    cout << endl<<endl<< "Make new output array and set default value 0 then it change step by step " << endl;
    
    int final[size - 1]={0};
    cout << "New array : ";
    showElement(final, size - 1);
    cout << endl;
    for (int i = size - 1, j = 1; i >= 0; i--,j++)
    {
        
        count[arr[i]]--;
        int k = count[arr[i]];
        final[k] = arr[i];
        cout << "Step " << j << " : ";
        showElement(final, size);
        cout << endl;
    }

    

    return 0;
}
/* 
8
7 2 9 2 7 4 5 1
 */

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

    //bubble sort
    for (int i = 1; i < size; i++)
    {
        int flag = 0;
        cout << "Iteration :" <<i<< endl;
        /* 
        Solve problem 01 : here we change size-1 to size-i
         */
        
        for (int j = 0; j < size-i; j++)
        {
            cout << "Step " << j + 1 << ": ";
            showElement(arr, size);
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
            cout << endl;
        }
        cout << endl
             << endl;
        /* Solve problem 02 using flag for stop unnecessary iteration */
       if (flag==0)
        {
            break;
        }
    }
    return 0;
}

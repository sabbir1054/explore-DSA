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
        for (int j = 0; j < size-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
            
        }
          
            if (flag=0)
            {
                break; 
            }
       
    }

    showElement(arr,size);
    return 0;
}

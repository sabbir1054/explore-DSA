#include<bits/stdc++.h>
using namespace std;
 int main() {

     int size;
     cin >> size;
     int arr[size];
     for (int i = 0; i < size; i++)
     {
         cin >> arr[i];
     }

     cout << "Please Input position to delete :";
     int pos;
     cin >> pos;

     for (int i = pos-1; i < size-1; i++)
     {
         arr[i] = arr[i + 1];
     }

    for (int i = 0; i < size-1; i++)
    {
        cout << arr[i]<<" ";
    }
    
     

     return 0;
}
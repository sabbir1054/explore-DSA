#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    int arr[size+1];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
 
    cout << "Please input the value ";
    int num;
    cin >> num;
    cout << "Input the position you want to insert ";
    int pos;
    cin >> pos;

 if (pos<0 || pos>size+1)
 {
       for (int i = size; i >=pos-1 ; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos-1] = num;
 }
 

    for (int i = 0; i < size+1; i++)
    {
        cout << arr[i]<<" ";
    }
    

    return 0;
}
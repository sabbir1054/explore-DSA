#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum=0,size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum;


    return 0;
}
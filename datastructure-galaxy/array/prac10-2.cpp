#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, sum = 0;

    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >>arr[i];
        if (i%2==0)
        {
            sum += arr[i];
        }
        
    }
    cout << sum;
    return 0;
}
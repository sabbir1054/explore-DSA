#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int num;
    cout << "Please input the value you want to find " << endl;
    cin >> num;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==num)
        {
            cout << "Position of " << num << " is " << i + 1<<endl;
        }
        
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


int binarySearch(int arr[],int num,int lb,int up){
    int i=1;
    
    while (lb <= up)
    {
        cout << "Step : " << i << endl;
        int mid = lb + (up - lb) / 2;
        cout << "Lower index : " << lb << " Upper index : " << up << endl;
        cout << "Desired num :" << num << " --> Not equal " << arr[mid]<<endl<<endl;
        if (arr[mid] == num){
            return mid;
        }else if (arr[mid] < num){
            lb = mid + 1;

        }else{
            up = mid - 1;
        }
        i++;
  }
  
    return -1;
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
    int num;
    cout << "Please input the value you want to find " << endl;
    cin >> num;

    int index;
    index = binarySearch(arr, num, 0, size - 1);

    if (index!=-1)
    {
        cout << "Position : " << index +1;
    }else{
        cout << "Desired number Not found";
    }
    
    return 0;
}
/* 
10
1 2 9 11 17 24 26 31 32 45
 */
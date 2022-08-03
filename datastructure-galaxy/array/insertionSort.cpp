#include<bits/stdc++.h>
using namespace std;
void showArr(int size,int arr[]){
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

//before shot
    showArr(size, arr);
    cout << endl;
    //insertion shot

    for (int i = 1; i < size; i++)
    {
        int key = arr[i];

        int j = i - 1;
        while (j>=0&&arr[j]>key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "///////0"<<endl;

    showArr(size, arr);

    return 0;
}

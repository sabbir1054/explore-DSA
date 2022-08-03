#include<bits/stdc++.h>
using namespace std;
void showArr(int size,int arr[]){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}
int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }

        //sort array
        for (int k = 0; k < size; k++)
        {
            for (int l = 0; l < size; l++)
            {
                if (arr[k]<arr[l])
                {
                    swap(arr[k], arr[l]);
                }
                
            }
            
        }
        //get index
        int pos;
        for (int p = 0; p < size; p++)
        {
            if (arr[p]==arr[0])
            {
                pos = p;
            }
            
        }

        cout << size -( pos + 1 )<< endl;
        }
       


        return 0;
}

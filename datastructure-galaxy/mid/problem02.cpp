#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int size1, size2;
    cin >> size1;
    int arr1[size1];
    for (int  i = 0; i < size1; i++)
    {
        /* code */
        cin >> arr1[i];
    }

    cin >> size2;
    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        /* code */
        cin >> arr2[i];
    }
    

    for (int i = 0; i < size1; i++)
    {
        int check = 0;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i]==arr2[j])
            {
                check=1;
            }
            
        }
        if (check==0)
        {
            cout << arr1[i] << " ";
        }
        
    }
    

    return 0;
}

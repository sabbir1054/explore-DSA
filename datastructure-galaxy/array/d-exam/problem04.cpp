#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    for (int k = 0; k < num; k++)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            
        }

        
    int visited[size] = {0};
    int frArr[size] = {0};       
        
    for(int i=0; i<size; i++){
        if(visited[i]!=1){
           int count = 1;
           for(int j=i+1; j<size; j++){
              if(arr[i]==arr[j]){
                count++;
                visited[j]=1;
              }
            }
            frArr[i] = count;
        }
    }



        int max2 = 0;
        for (int i = 0; i < size; i++)
        {
            if (frArr[i]>max2)
            {
                max2 = frArr[i];
            }
            
        }
       
            cout << size - max2 << endl;
        

    }
    
    return 0;
}

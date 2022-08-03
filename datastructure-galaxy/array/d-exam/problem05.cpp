#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int num;
    cin >> num;
    for (int k = 0; k < num; k++)
    {
        int size;
        cin >> size;
        int q;
        cin >> q;

        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        int res[q];

        for (int i = 0; i < q; i++)
        {
            int command;
            cin >> command;

            if (command==1)
            {
                int index;
                cin >> index;
                res[i] = arr[index];
                arr[index] = 0;
            }else if(command==2){
                int index, amount;
                cin >> index;
                
                cin>> amount;

                arr[index] = arr[index] + amount;
                res[i] = -1;
            }else if(command==3){
                int index1, index2;
                cin >> index1;
                cin >> index2;
                if (index2==0 && index1==0)
                {
                    res[i]=arr[0];
                }else{
                    int amount = 0;

                    for (int m = index1; m <= index2; m++)
                    {
                        amount = amount + arr[m];
                    }
                    res[i] = amount;
                }
                
            }
            
        }

        cout << "Case " << k + 1 << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            if (res[i]!=-1)
            {
                cout << res[i] << endl;
            }
            
        }
        
    }
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin >> num;
    
    int N, Q;
    

ios_base::sync_with_stdio(false);
   cin.tie(NULL);

for (int i = 0; i <num; i++)
{
    cin >> N;
    cin >> Q;
    int arr[N];
    int res[Q];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    for (int j = 0; j < Q; j++)
    {
        int low, high;
        cin >> low;
        cin >> high;
        int min = arr[low-1];

    for (int k = low-1; k <high ; k++)
    {
        if (min>arr[k])
        {
            min = arr[k];
        }
        
    }
    res[j] = min;
    }

    cout << "Case " << i + 1 << ":\n";
    for (int m = 0; m < Q; m++)
    {
        cout << res[m] << "\n";
    }
    
}
    return 0;
}
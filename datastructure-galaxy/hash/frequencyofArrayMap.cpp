#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    map<int, int> M;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
        M[arr[i]]++;
    }

    map<int, int>::iterator it;

    for (it  = M.begin(); it!=M.end(); it++)
    {
        /* code */
        cout << it->first << " = " << it->second << endl;
    }
    

    return 0;
}

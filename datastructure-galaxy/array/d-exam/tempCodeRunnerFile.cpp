#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;

    int start, end;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i]=='A')
        {
            start = i;
        }

    }

    for (int i = a.length()-1; i >= 0; i--)
    {
        if (a[i]=='Z')
        {
            end = i;
        }
    }
    
    cout<< (end - start) + 1 << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        if (num>=10)
        {
            count++;
        }
        
    }

    cout << count;

    return 0;
}

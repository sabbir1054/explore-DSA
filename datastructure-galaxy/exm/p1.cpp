#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int numberW, numberC,sum=0;
        cin >> numberW>>numberC;
        for (int i = 0; i < numberW; i++)
        {
            int wantedCandies;
            cin >> wantedCandies;
            sum = sum + (wantedCandies * 2);
        }

        if (sum<=numberC)
        {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
        
    }
    
    return 0;
}

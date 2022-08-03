#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int num, r, sum = 0, temp;
    cin >> num;
    temp = num;

    while(num>0){
        r = num % 10;
        sum = (sum * 10) + r;
        num = num / 10;
    }

    if(temp==sum){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}

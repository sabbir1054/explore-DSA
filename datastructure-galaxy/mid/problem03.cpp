#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // test cases
    int testCase;
    cin >> testCase;

    for (int l = 0; l < testCase; l++)
    {
        int days;
        cin >> days;
        int arrEarning[days];
        for (int i = 0; i < days; i++)
        {

            cin >> arrEarning[i];
        }
        int arrExpense[days];
        for (int i = 0; i < days; i++)
        {
            cin >> arrExpense[i];
        }

        // num of query
        int qNum;
        cin >> qNum;
        int res, finalArr[qNum];
        int pos;
        for (int i = 0; i < qNum; i++)
        {
            int totalEarn = 0, totalExpense = 0;
            cin >> pos;

            for (int j = 0; j < pos + 1; j++)
            {
                totalEarn = totalEarn + arrEarning[j];
                totalExpense = totalExpense + arrExpense[j];
            }
            res = totalEarn - totalExpense;
            if (res < 0)
            {
                finalArr[i] = 0;
            }
            else
            {
                finalArr[i] = 1;
            }
        }

        for (int i = 0; i < qNum; i++)
        {
            cout << finalArr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
test cases

2
5
10 5 2 3 1
8 15 1 2 10
3
0
1
3
3
7 10 1
3 2 7
1
2

1
4
10 1 1 2
7 4 4 4
2
1
3

 */
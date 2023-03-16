#include <bits/stdc++.h>
using namespace std;

void colorMixer()
{
    stack<char> stk;
    int n;
    cin >> n;
    char str[n];
    scanf("%s", str);

    int len = sizeof(str);
    if (len == 0)
    {
        cout << " " << endl;
        return;
    }
    stk.push(str[0]);

    for (int i = 1; i < len; i++)
    {
        // char ch = str[i]; /// r
        if (!stk.empty())
        {
            char tmp = stk.top(); /// g
            if (str[i] == tmp)   /// r
            {
                stk.pop();
            }

            /// red + blue
            else if ((str[i] == 'R' && tmp == 'B') || (str[i] == 'B' && tmp == 'R'))
            {
                stk.pop();
                if (!stk.empty())
                {
                    if (stk.top() != 'P')
                    {
                        stk.push('P');
                    }
                    else
                    {
                        if (stk.top() == 'P')
                        {
                            stk.pop();
                        }
                        else
                        {
                            stk.push(str[i]);
                        }
                    }
                }
                else
                {
                    stk.push('P');
                }
            }

            /// red + green
            else if ((str[i] == 'R' && tmp == 'G') || (str[i] == 'G' && tmp == 'R'))
            {
                stk.pop();
                if (!stk.empty())
                {
                    if (stk.top() != 'Y')
                    {
                        stk.push('Y');
                    }
                    else
                    {
                        if (stk.top() == 'Y')
                        {
                            stk.pop();
                        }
                        else
                        {
                            stk.push(str[i]);
                        }
                    }
                }
                else
                {
                    stk.push('Y');
                }
            }

            /// blue + green
            else if ((str[i] == 'B' && tmp == 'G') || (str[i] == 'G' && tmp == 'B'))
            {
                stk.pop();
                if (!stk.empty())
                {
                    if (stk.top() != 'C')
                    {
                        stk.push('C');
                    }
                    else
                    {
                        if (stk.top() == 'C')
                        {
                            stk.pop();
                        }
                        else
                        {
                            stk.push(str[i]);
                        }
                    }
                }
                else
                {
                    stk.push('C');
                }
            }
            else
            {
                stk.push(str[i]);
            }
        }
        else
        {
            stk.push(str[i]);
        }
    }

    stack<char> result;

    while (!stk.empty())
    {
        result.push(stk.top());
        stk.pop();
    }
    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }

    cout << endl;
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        colorMixer();
    }

    return 0;
}
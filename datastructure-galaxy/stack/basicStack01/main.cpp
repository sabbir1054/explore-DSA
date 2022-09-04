#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;
int main(int argc, char const *argv[])
{
    Stack <float> st;
    st.push(13.5);
    st.push(2.2);
    st.push(54.2);
    st.push(4.3);
    st.push(3.8);
    

    cout << st.mid() << endl;

    
    
    return 0;
}

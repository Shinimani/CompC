#include <bits/stdc++.h>

using namespace std;

// https://cses.fi/problemset/task/1071/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    long long x,y;
    long long ans =0;
    while(t-->0)
    {
        cin>>y;
        cin>>x;
        if (y>x)
        {
            if (y%2==0)
            {
                ans = y*y - x + 1;
            } else ans = (y-1)*(y-1) + x;
        } else
        {
            if (x%2!=0)
            {
                ans = x*x - y + 1;
            } else ans = (x-1)*(x-1) + y;
        }
        cout<<ans<<"\n";
        
    }
    cout<<"\n";

}
#include <bits/stdc++.h>

using namespace std;
#define ll long long
// https://cses.fi/problemset/task/1072

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    // long long x,y;
    ll ans =0;
    cout<<"0\n";
    if (t==1) return 0;
    cout<<"6\n";
    if (t==2) return 0;
    cout<<"28\n";
    if (t==3) return 0;
    for (ll i =4;i<=t;i++)
    {
        ans = i*i*(i*i - 1)/2 - 4*(i-1)*(i-2);
        cout<<ans<<"\n";
    }
    // while(t-->0)
    // {
    //     cin>>y;
    //     cin>>x;
    //     if (y>x)
    //     {
    //         if (y%2==0)
    //         {
    //             ans = y*y - x + 1;
    //         } else ans = (y-1)*(y-1) + x;
    //     } else
    //     {
    //         if (x%2!=0)
    //         {
    //             ans = x*x - y + 1;
    //         } else ans = (x-1)*(x-1) + y;
    //     }
    //     cout<<ans<<"\n";
        
    // }
    // cout<<"\n";

}
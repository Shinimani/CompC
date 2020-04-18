#include <bits/stdc++.h>

using namespace std;
#define ll long long
// https://www.codechef.com/problems/COINS

ll coin(ll n, ll *arr)
{
    if (n==0 || n==1) return n;
    else
    {
        if (arr[n]==0)
        {
            arr[n]=max(n,(arr[n/2] + arr[n/3] + arr[n/4]));
        } 
        return arr[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    // cin>>t;
    ll *arr;
    while(cin>>n)
    {
        arr = new ll [n+1];
        cout<<coin(n,arr);
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
    return 0;
}
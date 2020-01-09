#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://cses.fi/problemset/task/1092

// ll coin(ll n, ll *arr)
// {
//     if (n==0 || n==1) return n;
//     else
//     {
//         if (arr[n]==0)
//         {
//             arr[n]=max(n,(arr[n/2] + arr[n/3] + arr[n/4]));
//         } 
//         return arr[n];
//     }
// }
vc<vc<ll>> sets(ll n)
{
    ll sum = n*(n+1)/4;
    ll i =n;
    vc<ll> s1;
    while(sum-i>0)
    {
        s1.pb(i);
        sum-=i;
        i--;
    }
    ll tem = sum;
    s1.pb(tem);
    vc<ll> s2;
    while (i>0)
    {
        if (i!=tem)
            s2.pb(i);
        i--;
    }
    vc<vc<ll>> ans;
    ans.pb(s1);
    ans.pb(s2);
    return ans;
}
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    if (n*(n+1) % 4==0)
    {
        cout<<"YES\n";
        vc<vc<ll>> ans = sets(n);
        cout<<ans[0].size()<<"\n";
        printvec(ans[0]);
        cout<<ans[1].size()<<"\n";
        printvec(ans[1]);
    } else cout<<"NO\n";
    // ll *arr;
    // while(cin>>n)
    // {
    //     arr = new ll [n+1];
    //     cout<<coin(n,arr);
    // }
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
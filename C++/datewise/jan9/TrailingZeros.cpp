#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://cses.fi/problemset/task/1618

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
// // }
// vc<vc<ll>> sets(ll n)
// {
//     ll sum = n*(n+1)/4;
//     ll i =n;
//     vc<ll> s1;
//     while(sum-i>0)
//     {
//         s1.pb(i);
//         sum-=i;
//         i--;
//     }
//     ll tem = sum;
//     s1.pb(tem);
//     vc<ll> s2;
//     while (i>0)
//     {
//         if (i!=tem)
//             s2.pb(i);
//         i--;
//     }
//     vc<vc<ll>> ans;
//     ans.pb(s1);
//     ans.pb(s2);
//     return ans;
// }
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

    ll n,a,b;
    cin>>n;
    while(n-->0)
    {
       cin>>a;
       cin>>b;
       if ((2*a -b)%3 == 0 && (2*b - a)%3 == 0 && (2*a >= b) && (2*b >=a) )
       cout<<"YES\n"; else cout<<"NO\n";
    }

    return 0;
}
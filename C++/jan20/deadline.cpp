// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://codeforces.com/contest/1288/problem/A
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}


long fact(int n)
{
    long a =1;
    for(int i =1;i<=n;i++)
    {
        a *= (long)i;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double t,n,d;
    double temp1,temp2;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        temp1 = ceil((n-1)/2);
        // cout<<temp1<<endl;
        temp2 = ceil(d/(temp1+1));
        // cout<<temp2<<endl;

        if((temp1 + temp2 )<=n)cout<<"YES\n"; else cout<<"NO\n";
    }
    return 0;
}
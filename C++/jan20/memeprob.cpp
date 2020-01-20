// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://codeforces.com/contest/1288/problem/B
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
    
    ll t,a,b;
    ll temp1,temp2;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        temp1 = ceil(log10(b));
        if (b==pow(10,temp1) - 1|| b== pow(10,temp1))
        {
            temp2 = a*temp1;
        } else temp2 = a*(temp1 -1);
        cout<<temp2<<"\n";
    }
    return 0;
}
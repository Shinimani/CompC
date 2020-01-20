#include <bits/stdc++.h>
// #include <iostream>
// #include <cmath>
// #include <vector>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://codeforces.com/contest/1288/problem/C
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
    
    ll n,m;
    cin>>n>>m;
    m *=2;
    ll p = 1000000007;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i] = 0;
    }
    for(int i =1;i<=n;i++)
    {
        dp[i][1]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j =2;j<=m;j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%p; 
        }
    }
    cout<<dp[n][m]<<"\n";
    


    return 0;
}
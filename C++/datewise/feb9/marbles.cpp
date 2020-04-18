#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/problems/MARBLES

using namespace std;

long long int ncr(int n, int r)
{
    if (n==r) return 1;
    if (r==0) return 1;
    if (r==1 || r== n-1) return (long long int) n;
    if(r>n-r) r=n-r;
    long long int ans =1;
    for(int i=0;i<r;i++)
    {
        ans = ans*(n-i)/(i+1);
    }
    return ans;
}
int main(){
    
    int t;
    long long int n,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<ncr(n-1,k-1)<<"\n";
    }

    return 0;
}
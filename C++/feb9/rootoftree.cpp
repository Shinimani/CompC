#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/problems/TREEROOT


using namespace std;

#define PB push_back
#define V vector
#define FORI(i,a,b) for(int i =a;i<b;i++)


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
    int n,l,r,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n;
        l=0;
        r=0;
        while(n--)
        {
            cin>>a>>b;
            l+=a;
            r+=b;
        }
        cout<<l-r<<"\n";
        // cout<<ncr(n-1,k-1)<<"\n";
    }

    return 0;
}
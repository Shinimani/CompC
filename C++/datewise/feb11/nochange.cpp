#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/problems/MARBLES

using namespace std;

// long long int ncr(int n, int r)
// {
//     if (n==r) return 1;
//     if (r==0) return 1;
//     if (r==1 || r== n-1) return (long long int) n;
//     if(r>n-r) r=n-r;
//     long long int ans =1;
//     for(int i=0;i<r;i++)
//     {
//         ans = ans*(n-i)/(i+1);
//     }
//     return ans;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long n,p,temp,idx,num;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        idx = -1;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if (p%temp!=0)
            {
                idx = i;
                num=p/temp + 1;
            }
        }
        if (idx==-1)
        cout<<"NO"
    }

    return 0;
}
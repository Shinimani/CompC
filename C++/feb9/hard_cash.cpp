#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/FEB20B/problems/CASH

using namespace std;

int main(){
    
    int n,k,t,temp;
    int ans;
    cin>>t;
    while(t-- > 0)
    {
        cin>>n;
        cin>>k;
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            temp = temp%k;
            ans = ans + temp;
            ans = ans % k;
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>

// https://www.codechef.com/FEB20B/problems/SNUG_FIT

using namespace std;

int main(){
    
    int n,t,temp;
    int ans;
    cin>>t;
    vector<int> a,b;
    while(t > 0)
    {
        cin>>n;
        a.clear();
        b.clear();
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            a.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            b.push_back(temp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++)
        {
            temp= min(a[i],b[i]);
            ans+=temp;
        }
        // tempi = pi*ans;
        // ans = tempi;
        cout<<ans<<"\n";
        t--;

    }
    return 0;
}
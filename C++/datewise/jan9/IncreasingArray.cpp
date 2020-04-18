#include <bits/stdc++.h>

using namespace std;


// https://cses.fi/problemset/task/1094
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    long long prev;
    cin>>prev;
    long long temp;
    long long ans=0;
    for (int i =0;i<n-1;i++)
    {
        cin>>temp;
        if (temp<prev)
        {
            ans+= (prev-temp);
        }
        else
        {
            prev=temp;
        }
        
    }
    cout<<ans<<"\n";

}
#include <bits/stdc++.h>

using namespace std;

// https://cses.fi/problemset/task/1083

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    long long k = n*(n+1)/2;
    long long temp;
    for (int i =0;i<n-1;i++)
    {
        cin>>temp;
        k-=temp;
    }
    cout<<k<<"\n";

}
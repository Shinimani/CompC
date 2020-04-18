#include <bits/stdc++.h>

using namespace std;

// https://cses.fi/problemset/task/1068


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    while(true)
    {
        cout<<n<<" ";
        if (n==1)break;
        if (n%2==0) n/=2;
        else n = 3*n +1;
    }
    cout<<"\n";

}
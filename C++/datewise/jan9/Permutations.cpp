#include <bits/stdc++.h>

using namespace std;


// https://cses.fi/problemset/task/1070
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // string ans = "";
    if (n==1) cout<<"1\n";
    else if (n<=3) cout<<"NO SOLUTION\n";
    else if (n==4) cout<<"2 4 1 3\n";
    else 
    {
        if (n%2==0)
        {
            for(int i =0;i<n/2;i++)
            {
                cout<<2*i + 1<<" ";
            }
            for(int i =1;i<=n/2;i++)
            {
                cout<<2*i<<" ";
            }
        }
        else
        {
            for(int i =0;i<=n/2;i++)
            {
                cout<<2*i + 1<<" ";
            }
            for(int i =1;i<=n/2;i++)
            {
                cout<<2*i<<" ";
            }
        }
        cout<<"\n";
    }

}
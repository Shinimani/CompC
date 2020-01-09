#include <bits/stdc++.h>

using namespace std;


// https://cses.fi/problemset/task/1069
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin>>n;
    char temp = n[0];
    int c = 0;
    int mx = 0;
    for (int i =0;i<n.length();i++)
    {
        if (temp==n[i])
        {
            c++;
            mx = max(mx,c); 
        } else 
        {
            temp = n[i];
            c=1;
        }
    }
    cout<<mx<<"\n";

}
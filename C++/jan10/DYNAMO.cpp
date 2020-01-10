#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/JAN20B/problems/DYNAMO
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n,a,b;
    int t;
    cin>>t;
    
    // int s,a,b,c;
    // cin>>s>>a>>b>>c;
    // if (s> (a+b+c))cout<<"1"<<endl;
    // else if (s>(a+b) || s>(b+c))cout<<"2"<<endl;
    // else cout<<"3"<<endl;

    ll n,s,a,b,d,temp,outpu;
    while(t-->0)
    {
        cin>>n;
        cin>>a;
        temp = (ll)(pow(10,n) + .5);
        s = 2*temp +a;
        cout<<s<<endl;
        cin>>b;
        cout<<temp-b<<endl;
        cin>>d;
        cout<<temp-d<<endl;
        cin>>outpu;
        if(outpu==-1)
        {
            break;
        }

    }
    return 0;
}
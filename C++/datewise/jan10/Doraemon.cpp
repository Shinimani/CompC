#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/JAN20B/problems/CHFDORA
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
    int n,m;
    // int s,a,b,c;
    // cin>>s>>a>>b>>c;
    // if (s> (a+b+c))cout<<"1"<<endl;
    // else if (s>(a+b) || s>(b+c))cout<<"2"<<endl;
    // else cout<<"3"<<endl;
    ll ans;
    // ll n,s,a,b,d,temp,outpu;
    while(t-->0)
    {
        ans=0;
        cin>>n>>m;
        int arr[n][m];
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //(i,j) is the position of the center of plus
                for(int l=0;l<=min(n,m)/2;l++)
                {
                    //l is the length of a side of plus
                    if (i-l<0 || j-l<0 || i+l>n-1 || j+l>m-1) break;
                    else
                    {
                        if (arr[i-l][j]==arr[i+l][j] && arr[i][j-l]==arr[i][j+l]) ans++;
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
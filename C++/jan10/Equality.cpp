#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/JAN20B/problems/ISBIAS
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
    int n,q;
    cin>>n>>q;
    ll arr[n];
    int dp[n][n] = {0};
    // ll prev=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l,r;
    ll prev;
    int flag;
    int inc;
    int dec;
    for(int i =0;i<q;i++)
    {
        cin>>l>>r;
        l--;
        r--;
        if (dp[l][r]==1) cout<<"YES"<<endl;
        else if (dp[l][r]==-1) cout<<"NO"<<endl;
        else
        {
            prev = arr[l];
            flag=0;
            inc=0;
            dec=0;
            for(int j =l;j<=r;j++)
            {
                if(flag==0)
                {
                    if (prev>arr[j])
                    {
                        flag=-1;
                        dec++;
                    } else if (prev<arr[j])
                    {
                        flag=1;
                        inc++;
                    }
                } else if (flag==1)
                {
                    if (prev==arr[j])
                    {
                        // inc++;
                        flag=0;
                    } else if (prev>arr[j])
                    {
                        // inc++;
                        flag=-1;
                        dec++;
                    }
                } else if (flag==-1)
                {
                    if (prev==arr[j])
                    {
                        // dec++;
                        flag=0;
                    } else if (prev<arr[j])
                    {
                        // dec++;
                        flag=1;
                        inc++;
                    }
                }

                prev=arr[j];
            }
            if ((inc-dec) ==0) 
            {
                dp[l][r]=1;
                cout<<"YES"<<endl;
            } else 
            {
                dp[l][r] = -1;
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}
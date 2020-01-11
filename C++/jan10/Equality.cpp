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
    // int dp[n][n] = {0};
    // ll prev=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l,r;
    ll ten=100000;
    ll prev;
    for(int i =0;i<q;i++){
        cin>>l>>r;
        l--;
        r--;
        if((arr[l]<arr[l+1] && arr[r-1]>arr[r])||(arr[l]>arr[l+1] && arr[r-1]<arr[r]))
        cout<<"YES\n";
        else cout<<"NO\n";
    }
    // int flag;
    // int inc;
    // int dec;
    // map<ll,int> values;
    // for(int i =0;i<q;i++)
    // {
    //     cin>>l>>r;
    //     l--;
    //     r--;
    //     if (values[ten*l + r]==INT16_MAX) cout<<"YES"<<endl;
    //     else if (values[ten*l + r]!=0) cout<<"NO"<<endl;
    //     else
    //     {
    //         prev = arr[l];
    //         flag=0;
    //         inc=0;
    //         dec=0;
    //         for(int j =l;j<=r;j++)
    //         {
    //             if(values[ten*l + j]!=0 && values[ten*j + r]!=0)
    //             {
    //                 if (values[ten*l + j]==INT16_MAX && values[ten*j + r]==INT16_MAX)
    //                 {
    //                     cout<<"YES"<<"\n";
    //                     values[ten*l + r]=INT16_MAX;
    //                     break;
    //                 } else if ((values[ten*l + j] + values[ten*j + r])==0)
    //                 {
    //                     cout<<"YES"<<"\n";
    //                     values[ten*l + r]=INT16_MAX;
    //                     break;
    //                 } else 
    //                 {
    //                     cout<<"NO"<<"\n";
    //                     values[ten*l + r]=(values[ten*l + j] + values[ten*j + r]);
    //                     break;
    //                 }
    //             }
    //             if(flag==0)
    //             {
    //                 if (prev>arr[j])
    //                 {
    //                     flag=-1;
    //                     dec++;
    //                 } else if (prev<arr[j])
    //                 {
    //                     flag=1;
    //                     inc++;
    //                 }
    //             } else if (flag==1)
    //             {
    //                 if (prev==arr[j])
    //                 {
    //                     // inc++;
    //                     flag=0;
    //                 } else if (prev>arr[j])
    //                 {
    //                     // inc++;
    //                     flag=-1;
    //                     dec++;
    //                 }
    //             } else if (flag==-1)
    //             {
    //                 if (prev==arr[j])
    //                 {
    //                     // dec++;
    //                     flag=0;
    //                 } else if (prev<arr[j])
    //                 {
    //                     // dec++;
    //                     flag=1;
    //                     inc++;
    //                 }
    //             }

    //             prev=arr[j];
    //         }
    //         if ((inc-dec) ==0) 
    //         {
    //             values.insert(make_pair(ten*l + r,INT16_MAX));
    //             cout<<"YES"<<endl;
    //         } else 
    //         {
    //             values.insert(make_pair(ten*l + r,inc-dec));
    //             cout<<"NO"<<endl;
    //         }
    //     }

    // }
    return 0;
}
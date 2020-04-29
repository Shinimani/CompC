#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
// #define pii         pair<ll int,ll int>
// #define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define hell1        1000000006
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
typedef vector<int> vi ;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<int,vector<int>,greater<int>> pqig;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqlg;

int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
// ll gcd(ll u,ll v)
// {
// 	if(v==0)
// 	return u;
	
// 	else
// 	return gcd(v,u%v);
// }

// // // #define MAX 1000000
// int primes[100009],cnt=0;
// // vector<int> factors[1000009];
// char str[1000009];
// void pre()
// {
//     // calcualting primes
//     int n=1000000;
//     for(int i=2; i*i<=n; i++)
//         if(str[i]==0)
//             for(int j=i; j*i<=n; j++)
//                 str[i*j]=1;
//     for(int i=2; i<=n; i++)
//         if(str[i]==0)primes[cnt]=i,cnt++;
// }

int main()
{
    io

    int t,n,temp,s;
    cin>>t;
    // int ans,p,q;
    int idx,pos,possave,posend;
    vi arr;
    bool ans;
    while(t--)
    {
        cin>>n;
        // int arr[n];
        arr.clear();
        repn(i,n)
        {

            cin>>temp;
            arr.pb(temp);
            if(arr[i]==1)pos=i;
        }
        idx=1;
        posend=n;
        ans=true;
        possave=pos;
        // pos++;
        // cout<<"here";
        // repn(i,n)
        // cout<<arr[i]<<" ";
        // cout<<endl;
        while(idx<=n)
        {
            while(pos<posend)
            {
                if(arr[pos]!=idx)
                {
                    ans=false;
                    break;
                }else
                {
                    pos++;
                    idx++;
                }
            }
            if(ans&&idx<=n)
            {
                pos=possave-1;
                while(arr[pos]!=idx)
                    {
                        pos--;
                    }
                posend=possave;
                possave=pos;
            }else break;
        }
        if(ans)cout<<"YES\n";else cout<<"NO\n";
        
    }
    
 	return 0;
}
 
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
    int ans,p,q;
    int k;
    int mx,mxidx,here,idxhere;
    // vector<bool> b(8);
    while(t--)
    {
        cin>>n>>k;
        int arr[n];
        repn(i,n) cin>>arr[i];
        int cts[n-k+1];
        // bool b[n];
        vector<bool> b(n,false);
        repn(i,n)
        {
            if(i==0||i==n-1) continue;
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])b[i]=true;
        }
        here=0;mx=0;
        repn(i,n)
        {
            if(i>0 && b[i-1])here++;
            if(i>=k-1)
            {
                if(b[i-k+1])here--;
                cts[i-k+1]=here;
            }
        }
        mx=0;
        repn(i,n-k+1)
        {
            mx=max(mx,cts[i]);
        }
        repn(i,n-k+1)
        {
            // mx=max(mx,cts[i]);
            if(cts[i]==mx){
                mxidx=i;
                break;
            }
        }
        mx++;
        mxidx++;
        cout<<mx<<" "<<mxidx<<endl;
        
        
    }
    
 	return 0;
}
 
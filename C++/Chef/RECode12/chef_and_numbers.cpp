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
    vi arr;
    map<int,int> m;
    int mx;
    int cou,prev;
    vector<pair<int,int>> vp;
    while(t--)
    {
        cin>>n;
        arr.clear();
        m.clear();
        vp.clear();
        mx = 0;
        cou=0;

        repn(i,n)
        {
            cin>>temp;
            arr.pb(temp);
            if(i==0)
            {
                cou=1;
            }else
            {
                if(temp==prev)
                {
                    cou++;
                }
                else
                {
                    m[prev]+=max((cou+1)/2 , 1);
                    cou=1;
                }
            }
            if(i==n-1) m[temp]+=max((cou+1)/2 , 1);
            prev=temp;
        }
        
        ans=INT_MAX;
        for(auto itr = m.begin();itr!=m.end();itr++)
        {
            mx=max(itr->second,mx);
        }
        for(auto itr = m.begin();itr!=m.end();itr++)
        {
            // cout<<itr->first<<" "<<itr->second<<endl;
            if(itr->second==mx)
                ans=min(ans,itr->first);
        }
        cout<<ans<<"\n";


    
        // cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
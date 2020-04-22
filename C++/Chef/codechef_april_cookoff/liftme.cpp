#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
// #define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
// #define pii         pair<ll int,ll int>
// #define vi          vector<ll int>
// #define all(a)      (a).begin(),(a).end()
// #define F           first
// #define S           second
// #define sz(x)       (ll int)x.size()
// #define hell        1000000007
// #define hell1        1000000006
// #define rep(i,a,b)    for(ll int i=a;i<b;i++)
// #define lbnd        lower_bound
// #define ubnd        upper_bound
// #define bs          binary_search
// #define mp          make_pair
// typedef vector<int> vi ;
// typedef vector<long long> vl ;
// typedef pair<int,int> pi;
// typedef pair<ll,ll> pl;


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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t,n,temp,s;
    cin>>t;
    ll p,q;
    ll ans=0;
    ll f,d;
    while(t--)
    {
        cin>>n>>q;
        ans=0;
        p=0;
        // cin>>f>>d;
        // ans+=d;
        // p=d;
        repn(i,q)
        {
            cin>>f>>d;
            ans+=(abs(p-f));
            ans+=(abs(f-d));
            p=d;
        }
        // cout<<ans<<endl;

        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
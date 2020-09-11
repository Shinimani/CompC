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
#define ret         return
#define repnitr(itr,m) for(auto itr=m.begin();itr!=m.end();itr++)
#define repnrevitr(itr,m) for(auto itr=m.rbegin();itr!=m.rend();itr++)
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

    int t,n,k;
    // int a,b,c;
    int temp,ans;
    int p,q;
    int x,y,z;
    vi a;
    // ll t,n;
    // ll a,b,c;
    // ll temp,ans;
    // ll p,q;
    // ll x,y,z;
    // vl a;
    string s;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        a.clear();
        repn(i,n)
        {
            cin>>temp;
            a.pb(temp);
        }
        sort(all(a));
        if(n==1) cout<<"0\n";
        else if(n<=3)cout<<"1\n";
        else
        {
            p = a[0]+a[1];
            q = a[n-1]+a[n-2];
            ans=0;
            for(int i=p;i<=q;i++)
            {
                temp=0;
                auto aa = a;
                auto it = aa.begin();
                while(it!=aa.end())
                {
                    k = i - *it;
                    auto helper = it;
                    helper++;
                    auto loc = find(helper,aa.end(),k);
                    if (loc!=aa.end())
                    {
                        aa.erase(loc);
                        aa.erase(it);
                        temp++;
                    }else it++;
                }
                ans=max(ans,temp);
          }
            cout<<ans<<"\n";
        }
        
    
        
    }
    
 	return 0;
}

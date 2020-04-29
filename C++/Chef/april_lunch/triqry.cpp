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
bool cont(int l1,int r1,pair<int,int> p1)
{
    double l = (double) l1;
    double r = (double) r1;
    double x = (double) p1.first;
    double y = (double) p1.second;
    double h = (r-l)/2;
    if(x<l || x>r || y>h)return false;
    if(x<=(l+r)/2)
    {
        return(y<=x-l);
    }else
    {
        return(y<=r-x);
    }
}
int main()
{
    io

    int t,n,temp,s;
    cin>>t;
    int ans,p,q;
    int x,y;
    int l,r;
    vector<pair<int,int>> vp;
    vector<pair<int,int>>::iterator st,en,itr;
    while(t--)
    {
        cin>>n>>q;
        vp.clear();
        repn(i,n)
        {
            cin>>x>>y;
            vp.push_back(make_pair(x,y));
        }
        sort(vp.begin(),vp.end());

        repn(i,q)
        {
            cin>>l>>r;
            ans=0;
            st=lower_bound(vp.begin(),vp.end(),make_pair(l,0));
            en=lower_bound(vp.begin(),vp.end(),make_pair(r+1,0));
            for(itr=st;itr!=en;itr++)
            {
                if(cont(l,r,*itr)) ans++;
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
        
        
    }
    
 	return 0;
}
 
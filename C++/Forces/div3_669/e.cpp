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
// pair<int,int> helper(vector<pair<ll,int>> v,ll k)
// {
//     int n = v.size();
//     int maxf=0;
//     int maxb=0;
//     int indf=0;
//     int indb=0;
//     for(int i=0;i<n;i++)
//     {
//         ll s = v[i].F;
//         int curr = v[i].S;
//         for(int j=i+1;j<n && v[j].F<=s+k;j++)
//     }
// }
int main()
{
    io

    // int t,n;
    // int a,b,c;
    // int temp,ans;
    // int p,q;
    // int x,y,z;
    
    ll t,n,k;
    // ll a,b,c;
    ll temp,ans;
    ll p,q;
    ll x,y,z;
    
    string s;
    cin>>t;
    vector<ll> a;
    vector<pair<ll,int>> v;
    while(t--)
    {
        cin>>n>>k;
        a.clear();
        v.clear();
        repn(i,n)
        {
            cin>>temp;
            a.pb(temp);
        }
        repn(i,n)
        {
            cin>>temp;
        }
        sort(all(a));
        ans=0;
        ll pf=0,pob=0;
        int locf=0,locb=0;
        auto start = a.begin();
        for(int i=n-1;i>=0;i--)
        {
            auto it = lbnd(all(a),a[i]-k);
            int tempindex = it-start;
            if(i-tempindex+1>pob)
            {
                pob = i-tempindex+1;
                locb = i;
            }
            int j = n - i - 1;
            it = ubnd(all(a),a[j]+k);
            if(it == a.end())
                it--;
            else if (*it > a[j]+k)
                it--;
            tempindex = it-start;
            if(tempindex-j+1>pf)
            {
                pf = tempindex-j+1;
                locf = j;
            }
        }
        if(pf>pob)
        {
            auto startit = a.begin() + locf;
            auto endit = startit + pf;
            a.erase(startit,endit);
        }else
        {
            auto endit = a.begin() + locb;
            auto startit = endit - pob;
            a.erase(startit,endit);
        }
        ans+=max(pf,pob);
        pf=0,pob=0;
        locf=0,locb=0;
        start = a.begin();
        n = a.size();
        for(int i=n-1;i>=0;i--)
        {
            auto it = lbnd(all(a),a[i]-k);
            int tempindex = it-start;
            if(i-tempindex+1>pob)
            {
                pob = i-tempindex+1;
                locb = i;
            }
            int j = n - i - 1;
            it = ubnd(all(a),a[j]+k);
            if(it == a.end())
                it--;
            else if (*it > a[j]+k)
                it--;
            tempindex = it-start;
            if(tempindex-j+1>pf)
            {
                pf = tempindex-j+1;
                locf = j;
            }
        }
        // if(pf==0) 
        // {
        //     cout<<ans<<endl;
        //     continue;
        // }
        // else if(pf>pob)
        // {
        //     auto startit = a.begin() + locf;
        //     auto endit = startit + pf;
        //     a.erase(startit,endit);
        // }else
        // {
        //     auto endit = a.begin() + locb +1;
        //     auto startit = endit - pob;
        //     a.erase(startit,endit);
        // }
        ans+=max(pob,pf);

        



        // pair<ll,int> prev = mp(a[0],1);
        // for(ll i : a)
        // {
        //     if(a==prev.F)
        //     {
        //         prev.S++;
        //     }else
        //     {
        //         v.pb(prev);
        //         prev = mp(i,1);
        //     }
        // }
        // v.pb(prev);
        // p=0,q=0;


        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
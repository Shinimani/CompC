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

    int t,n,k,x;
    int temp,p,q;
    // ll temp,ans,p,q;
    string sa,sb;
    cin>>t;
    map<char,vi> a,b;
    set<int> v;
    vector<set<int>> ans;
    while(t--)
    {
        cin>>n;
        a.clear();
        b.clear();
        cin>>sa;
        repn(i,n)
        {
            a[sa[i]].pb(i);
        }
        cin>>sb;
        bool f=true;
        repn(i,n)
        {
            b[sb[i]].pb(i);
        }
        for(auto it:b)
        {
            if(a.find(it.first)==a.end())
            {
                f=false;
                break;
            }
        }
        if(!f)
        {
            cout<<"-1\n";
        }else
        {
            ans.clear();
            for(auto it=b.rbegin();it!=b.rend();it++)
            {
                char c=it->first;

                v.clear();
                for(int i:it->second)
                {
                    if(sa[i]<c)
                    {
                        f=false;
                        break;
                    }else if(sa[i]!=c)
                    {
                        sa[i]=c;
                        v.insert(i);
                    }
                }
                if(!f)
                    break;
                else
                {
                    if(!v.empty())
                    {v.insert(a[c][0]);
                    ans.pb(v);}
                }
            }
            if(!f)
            {
                cout<<"-1\n";
            }else
            {
                cout<<ans.size()<<endl;
                for(auto g:ans)
                {
                    cout<<g.size()<<" ";
                    for(int i:g)
                    {
                        cout<<i<<" ";
                    }
                    cout<<endl;
                }
            }
        }
        
    
        
    }
    
 	return 0;
}
 
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
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    vi od,ev,a;
    bool f;
    while(t--)
    {
        cin>>n;
        od.clear();
        ev.clear();
        a.clear();
        repn(i,n)
        {
            cin>>temp;
            a.pb(temp);
            if(temp%2)
            {
                od.pb(temp);
            }else ev.pb(temp);
        }
        f=false;
        if(od.size()%2==0 && ev.size()%2==0)
        {
            f=true;
        }else
        {
            sort(all(a));
            repn(i,n-1)
            {
                if(a[i+1]-a[i]==1)
                {
                    f=true;
                    break;
                }
            }
        }
        
        // if(od.size() ==0 || ev.size()==0)
        // {
        //     f=true;
        // }else if (od.size()>=2 && ev.size()>=2)
        // {
        //     f=true;
        // }else if (n==2)
        // {
        //     f=false;
        // }else
        // {
        //     if(od.size()==1)
        //     {
        //         p=od[0];
        //         for(int i:ev)
        //         {
        //             if(abs(p-i)==1)
        //             {
        //                 f=true;
        //                 break;
        //             }
        //         }
        //     }else
        //     {
        //         p=ev[0];
        //         for(int i:od)
        //         {
        //             if(abs(p-i)==1)
        //             {
        //                 f=true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
 	return 0;
}
 
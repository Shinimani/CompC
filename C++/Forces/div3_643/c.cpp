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
bool helper_fun(vi &a,int i, int j)
{
    if(i<0) return false;
    int prev = min(a[i],a[j]);
    int temp;
    while(i<j)
    {
        // cout<<a[i]<<" "<<a[j]<<endl;
        temp = min(a[i],a[j]);
        if(temp<prev) return false;
        if(a[i]<a[j])
        {
            prev = a[i];
            i++;
        }else
        {
            prev=a[j];
            j--;
        }
    }
    return true;
}

int main()
{
    io

    int t,n,k,x;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    vi a;

    // vi c;
    // c.pb(1);
    // c.pb(2);
    // c.pb(3);
    // c.pb(4);
    // cout<<helper_fun(c,0,3);


    while(t--)
    {
        cin>>n;
        a.clear();
        repn(i,n)
        {
            cin>>temp;
            a.pb(temp);
        }
        int dir = -1;
        int prev = a[n-1];
        int i=n-2;
        for(i=n-2;i>=0;i--)
        {
            if(dir<0)
            {
                if(a[i]<prev)
                    dir=1;
            }else
            {
                if(a[i]>prev)
                {
                    break;
                }
            }
            prev=a[i];
        }
        cout<<i+1<<endl;
        
    }
    
 	return 0;
}
 
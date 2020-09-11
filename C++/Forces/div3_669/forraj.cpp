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

int helper(vector<int> &a, int i,int j,int x,int y,int z)
{
    int ans=0;
    int n = a.size();
    if(i>j)return 0;
    if(x+y+z == 0)return 0;
    int sizee = j-i+1;
    if(sizee<2 && x==0)return 0;
    if(sizee<3 && x+y==0)return 0;
    if(sizee==1)return a[i];
    // if(sizee==2)
    // {
    //     if(y>0)return a[i]+a[j];
    //     if(x==1)
    // }
    if(x+2*y+3*z >= j-i+1)
    {
        for(int k=i;k<=j;k++)
        {
            ans+=a[k];
        }
        return ans;
    }
    int a1 = max(helper(a,i+1,j,x,y,z),helper(a,i,j-1,x,y,z);
    int a2 = (x>0)? max(helper(a,i+1,j,x-1,y,z) + a[i],helper(a,i,j-1,x-1,y,z) + a[j]) : 0;
    int a3 = (y>0 && i +1 < a.size()? max(helper(a,i+2,j,x,y-1,z) + a[i] + a[i+1],helper(a,i+2,j,x,y-1,z) + a[i] + a[i+1]:0;
    int a4 = (z>0 && i +2 < a.size())? helper(a,i+3,j,x,y,z-1) + a[i] + a[i+1] + a[i+2]:0;
    
    ans = max(a1,max(a2,max(a3,a4)));
    return ans;
}
int calculateProfit(vector<int> a,int x,int y,int z)
{
    int n = a.size();
    return helper(a,0,n-1,x,y,z);

}

// int maximumNetworks(vector<int> speed,int mincomps,long thres)
// {

// }
int main()
{
    io

    int t,n;
    int a,b,c;
    int temp,ans;
    int p,q;
    int x,y,z;
    
    // ll t,n;
    // ll a,b,c;
    // ll temp,ans;
    // ll p,q;
    // ll x,y,z;
    
    string s;
    cin>>t;
    
    while(t--)
    {
        vector<int> a;
        a.pb(-6);
        a.pb(5);
        a.pb(10);
        a.pb(-2);

        cout<<calculateProfit(a,1,1,0)<<endl;
        
    }
    
 	return 0;
}
 
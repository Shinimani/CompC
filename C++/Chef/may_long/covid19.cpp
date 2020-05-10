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

    int t,n,temp,s;
    cin>>t;
    int ans,p,q;
    int arr[9];
    bool b[9];
    int best,worst;
    bool one,cont,allcover;
    int minc,maxc;
    while(t--)
    {
        cin>>n;
        // repn(i,n)
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        memset(b,false,sizeof(b));
        one=false;cont=false,allcover=true;
        minc=INT_MAX;
        maxc=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i+1]-arr[i] <=2) b[i]=true;
        }
        temp=1;
        for(int i=1;i<n;i++)
        {
            if(b[i])
            {
                temp++;
                maxc=max(maxc,temp);
            }
            else
            {
                allcover=false;
                minc=min(minc,temp);
                temp=1;
                if(i!=1 && !b[i-1]) minc=1;
            }
        }
        minc=min(minc,temp);
        if(allcover) cout<<n<<" "<<n<<endl;
        else cout<<minc<<" "<<maxc<<endl;
        
    }
    
 	return 0;
}
 
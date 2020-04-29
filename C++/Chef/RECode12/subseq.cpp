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
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

int main()
{
    io

    ll t,n,temp,s;
    cin>>t;
    ll ans,p,q;
    map<ll,ll> m;
    ll two[100001]={1};
    ll mdo = 163577857;
    repn(i,100001)
    {
        if(i!=0)
        {
            two[i]=2*two[i-1];
            two[i]%=mdo;
        }
    }
    while(t--)
    {
        cin>>n;
        m.clear();
        repn(i,n)
        {
            cin>>temp;
            m[temp]++;
        }
        temp = two[m[0]];
        ll arr[2*n+1]={0};
        repn(i,2*n+1)
        {
            p=i-n;
            if(p<0)
            {
                if(m[-1]<-p)continue;
                else
                {
                    // q=1LL;
                    for(ll j=0;j-p<=m[-1] && j<=m[1] ;j++)
                    {
                        q=nCrModPFermat(m[-1],j-p, mdo);
                        q%=mdo;
                        q*=nCrModPFermat(m[1],j,mdo);
                        q%=mdo;
                        q*=temp;
                        q%=mdo;
                        arr[i]+=q;
                        arr[i]%=mdo;
                    }
                }
            }else
            {
                if(m[1]<p)continue;
                else
                {
                    for(ll j=0;j+p<=m[1] && j<=m[-1] ;j++)
                    {
                        q=nCrModPFermat(m[1],j+p, mdo);
                        q%=mdo;
                        q*=nCrModPFermat(m[-1],j,mdo);
                        q%=mdo;
                        q*=temp;
                        q%=mdo;
                        arr[i]+=q;
                        arr[i]%=mdo;
                    }
                }
            }

            
        }

         repn(i,2*n+1)
        {    cout<<arr[i]<<" ";}
        cout<<endl;



    
        
    }
    
 	return 0;
}
 
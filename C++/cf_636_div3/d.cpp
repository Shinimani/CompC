#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
// #define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
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
typedef vector<int> vi;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

// To compute x^y under modulo m 
ll expo(ll base, ll exponent, ll mod) {                                //return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
long long modInverse(long long a, long long m) 
{ 
    return expo(a, m-2, m); 
} 
  

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
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // const int N = 1e6 + 7;
    // const int K = 24;

    int t,temp,n;
    // string s;
    cin>>t;
	int k=1;
    vl arr;
    ll curr,mx; 
    ll sum,prev;
    ll ans;
    unordered_map<ll,ll> mp;
    unordered_map<ll,ll>::iterator itr;
    vi ra;
    vi::iterator itv;
    while(t--)
    {
		cin>>n>>k;
        mp.clear();
		arr.clear();
        ra.clear();
        ans=INT_MAX;
        mx=0;
        curr=0;
        sum=0;
        repn(i,n)
        {
            cin>>temp;
            arr.push_back(temp);
            sum+=temp;
        }
        
        repn(j,n/2)
        {
            temp = arr[j]+arr[n-j-1];
            // cout<<temp<<" ";
            if(temp !=mx)
            {
                if(temp<mx)
                {
                    if(k+arr[j]>=mx || k+arr[n-1-j]>=mx)
                    {
                        curr++;
                    }else curr+=2;
                }else
                {
                    if(1+arr[j]<=mx || 1+arr[n-1-j]<=mx)
                    {
                        curr++;
                    }else curr+=2;
                }
                
            }
            mp[arr[j] + arr[n-1-j]]++;
            mx = max(mx,mp[arr[j] + arr[n-1-j]]);
        }
        ans=min(ans,curr);
        for(itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second==mx)
            {
                ra.pb(itr->first);
            }
        }
        repn(i,ra.size())
        {
            curr=0;
            mx=ra[i];
            cout<<mx<<" ";
            repn(j,n/2)
            {
                temp = arr[j]+arr[n-j-1];
                // cout<<temp<<" ";
                if(temp !=mx)
                {
                    if(temp<mx)
                    {
                        if(k+arr[j]>=mx || k+arr[n-1-j]>=mx)
                        {
                            curr++;
                        }else curr+=2;
                    }else
                    {
                        if(1+arr[j]<=mx || 1+arr[n-1-j]<=mx)
                        {
                            curr++;
                        }else curr+=2;
                    }
                    
                }
            }
            cout<<curr<<endl<<endl;
            ans=min(ans,curr);

        }
        
        cout<<ans<<endl;
        

    }

    
 	return 0;
}
 
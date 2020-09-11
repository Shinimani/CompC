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
void rotate(vector<vector<int> > &a) {
    int n = a.size();
    for(int i=0;i<=n/2;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            int topleft = a[i][i+j];
            int topright = a[i+j][n-1-i];
            int bottomright = a[n-1-i][n-1-i-j];
            int bottomleft = a[n-1-i-j][i];
            a[i][i+j] = bottomleft;
            a[i+j][n-1-i] = topleft;
            a[n-1-i][n-1-i-j] = topright;
            a[n-1-i-j][i] = bottomright;
        }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
vector<int> nextPermutation(vector<int> &a) {
    int n=a.size();
    n--;
    int max = 0;
    while(n>=0)
    {
        
    }
    return a;
}


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
        cin>>n;
    
        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
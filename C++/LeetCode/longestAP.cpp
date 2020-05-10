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
int longestArithSeqLength(vector<int>& a) {
    // sort(all(a));
    int n=a.size();
    vector<vi> dp(n,vi (n,2));
    int i,k;
    int ans=2;
    // repn(i,n)
    // {
    //     repn(j,n)
    //     {
    //         // dp[i][j]=2;
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //     cout<<endl;

    for(int j=n-2;j>=1;j--)
    {
        for(int i=j-1;i>=0;i--)
        {
            int k=j+1;
            while(k<n)
            {
                if(a[i]+a[k]==2*a[j])
                {
                    dp[i][j]=dp[j][k]+1;
                    ans=max(ans,dp[i][j]);
                    break;
                }
                k++;
            }
        }
    }

    repn(i,n)
    {
        repn(j,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;

}
int main()
{
    io

    int t,n;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    // cin>>t;
    vi a = {0,8,45,88,48,68,28,55,17,24};
    // sort(all(a));
    repn(i,a.size())cout<<a[i]<<" ";
    cout<<endl;
    // for(int i=1;i<=4;i++)
    // {
    //     a.pb(3*i);
    // }
    cout<<longestArithSeqLength(a);
    // while(t--)
    // {
    //     cin>>n;
    
    //     cout<<ans<<"\n";
        
    // }
    
 	return 0;
}
 
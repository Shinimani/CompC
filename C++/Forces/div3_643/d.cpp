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
    
    while(t--)
    {
        cin>>n;
        cin>>s;
        int i=0;
        char c = 'a';
        ans=0;
        int len = n/2;
        int lc[26];
        int rc[26];
        while(len>0)
        {
            memset(lc,0,sizeof(lc));
            memset(rc,0,sizeof(rc));
            
            // cout<<i<<" "<<len<<" "<<c<<endl;
            for(int j=0;j<len;j++)
            {
                for(char cc = c;cc<='z';cc++)
                {
                    if(s[i+j]==cc)lc[cc-'a']++;
                    if(s[i+len+j]==cc)rc[cc-'a']++;
                }
                
            }
            // for(int i=0;i<26;i++)
            // {
            //     cout<<lc[i]<<" "<<rc[i]<<endl;
            // }
            // cout<<endl;
            if(lc[c-'a']==len && rc[c-'a']==len)
                {
                    break;
                }
            else
            {
                if(lc[c-'a']>rc[c-'a'])
                {
                    ans+=len-lc[c-'a'];
                    i+=len;
                    
                }else if (rc[c-'a']>lc[c-'a'])
                {
                    ans+=len-rc[c-'a'];
                    
                }else
                {
                    ans+=len-lc[c-'a'];
                    if(len==1)
                    {
                        ans+=len-lc[c-'a'];
                    }
                    else
                    {
                        char d=c;
                        // d++;
                        while(d<='z' && lc[d-'a']==rc[d-'a'])
                            d++;
                        if( d>'z')
                        {
                            continue;
                        }else
                        {
                            if(lc[d-'a']<rc[d-'a'])
                                i+=len;
                        }
                    } 
                }
            }
            c++;
            len/=2;
            
            // cout<<ans<<endl;

        }
        cout<<ans<<endl;
        
    }
    
 	return 0;
}
 
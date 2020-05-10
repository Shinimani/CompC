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

    int t,n,k;
    int temp,p,q;
    // ll temp,ans,p,q;
    string s,ans;
    cin>>t;
    map<char,int> m;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        m.clear();
        repn(i,n)
        {
            m[s[i]]++;
        }
        q=k;
        bool flag=true;
        ans="";
        char c='a';
        while(m[c]==0)c++;
        if(m[c]<k)
        {
            q=k;
            q-=m[c++];
            while(m[c]<q) q-=m[c++];
            ans.pb(c);
        }else
        {
            ans.pb(c);
            m[c]-=k;
            // cout<<"heh";
            while(m[c]==0 && c<='z')c++;
            // cout<<"heh";

            if(c!='z'+1)
            {
            // cout<<"heh";

                char w=c+1;
                bool rem=false;
                while(w<='z')
                {
                    if(m[w])
                    {
                        rem=true;
                        break;
                    }
                    w++;
                }
                if(rem)
                {
                    while (c<='z')
                    {
                        repn(i,m[c])
                        {
                            ans.pb(c);
                        }
                        c++;
                    }
                }else
                {
                    while(m[c]>0)
                    {
                        ans.pb(c);
                        m[c]-=k;
                    }
                }
                

            }
            
        }
        cout<<ans<<"\n";
     
    }
    
 	return 0;
}
 
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

    int t,n,x,m;
    int temp;
    // ll temp,ans,p,q;
    vector<string> a;
    string s,ans,q;
    cin>>t;
    bool f;
    while(t--)
    {
        cin>>n>>m;
        a.clear();
        repn(i,n)
        {
            cin>>s;
            a.pb(s);
        }
        f=true;
        vector<pi> v;
        repn(i,n)
        {
            if(!f)break;
            for(int j=i+1;j<n;j++)
            {
                temp=0;
                repn(k,m)
                {
                    if(a[i][k]!=a[j][k])
                        temp++;
                }
                if(temp>2)f=false;
                if(temp==2)
                {
                    v.pb(mp(i,j));
                }
            }
        }
        ans="";
        if(!f)
        {
            cout<<"-1\n";
        }else
        {
            f=false;
            if(v.size()==0)
            {
                cout<<a[0]<<endl;
            }
            else
            {
                // f=(v.size()==0);
                for(auto p:v)
                {
                    if(f)break;
                    s=a[p.F];
                    q=a[p.S];
                    repn(i,m)
                    {
                        if(f)break;
                        if(s[i]==q[i])continue;
                        else
                        {
                            char c=s[i];
                            s[i]=q[i];
                            x=0;
                            repn(j,n)
                            {
                                temp=0;
                                repn(k,m)
                                {
                                    if(s[k]==a[j][k])continue;
                                    else temp++;
                                }
                                x=max(x,temp);
                                if(x>1)break;
                            }
                            if(x<=1)
                            {
                                ans=s;
                                f=true;
                                break;
                            }else
                            {
                                s[i]=c;
                            }
                        }
                    }

                }

                
                if(f)cout<<s<<endl;
                else cout<<"-1\n";
            }
            

        }
        
    
        
    }
    
 	return 0;
}
 
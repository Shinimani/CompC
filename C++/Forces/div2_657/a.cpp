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
    string c = "abacaba";
    vi a,b;
    while(t--)
    {
        cin>>n;
        cin>>s;
        a.clear();
        b.clear();
        for(int i=0;i+6<n;i++)
        {
            int j=0;
            bool f=true;
            for(j=0;j<7;j++)
            {
                if(s[i+j]=='?' || s[i+j]==c[j])
                    {
                        if(s[i+j]=='?')
                            f=false;
                        continue;
                    }
                else break;
            }
            if(j==7)
            {
                if(!f)
                    a.pb(i);
                else
                {
                    b.pb(i);
                }
            }
        }
        // cout<<a.size()<<" "<<b.size()<<endl;
        if(b.size()>1 || (a.empty() && b.empty()))
            cout<<"NO\n";
        else
        {
            if(b.size()==1)
            {
                cout<<"YES\n";
                repn(i,n)
                {
                    if(s[i]=='?')
                        s[i]='z';
                }
                cout<<s<<endl;
            }else if (a.size()==1)
            {
                for(int j=0;j<7;j++)
                {
                    s[a[0]+j]=c[j];
                }
                repn(i,n)
                {
                    if(s[i]=='?')
                        s[i]='z';
                }
                cout<<"YES\n";
                cout<<s<<endl;
            }else
            {
                string ss = s;
                bool yes = true;
                for(int i=0;i<a.size() && yes;i++)
                {
                    for(int j=0;j<7;j++)
                    {
                        ss[a[i]+j]=c[j];
                    }
                    int k=0;
                    for(k=0;k<a.size();k++)
                    {
                        if(k==i || abs(a[i]-a[k])>7) continue;
                        bool flag = true;
                        for(int j=0;j<7 && flag;j++)
                        {
                            flag = ss[a[k]+j]==c[j];
                        }
                        if(flag)
                            break;
                    }
                    if(k==a.size())
                    {
                        cout<<"YES\n";
                        yes=false;
                        repn(j,n)
                        {
                            if(ss[j]=='?')
                                ss[j]='z';
                        }
                        cout<<ss<<endl;
                    }
                }
                if(yes)
                    cout<<"NO\n";
            }
            
        }
        
    }
    
 	return 0;
}
 
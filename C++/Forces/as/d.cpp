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

    int t,n;
    // int a,b,c;
    int temp,ans;
    int p,q;
    int x,y,z;
    vi a,b;
    // ll t,n;
    // ll a,b,c;
    // ll temp,ans;
    // ll p,q;
    // ll x,y,z;
    // vl a;
    string s;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        cin>>s;
        a.clear();
        b.clear();
        int c[n];
        bool d[n];
        memset(c,-1,sizeof(c));
        memset(d,true,sizeof(d));
        bool f = true;
        f = s[0]=='1';
        repn(i,n)
        {
            if(s[i]=='1')
                a.pb(i);
            else b.pb(i);
        }
        ans=0;
        if(a.empty()||b.empty())
        {
            cout<<n<<endl;
            repn(i,n)
                cout<<i+1<<" ";
            cout<<endl;    
        }else
        {
            int counter = 1;
            c[0]=counter;
            d[0]=false;
            int prev = 0;
            auto ia = a.begin();
            auto ib = b.begin();
            int prenum = 0;
            while(!a.empty() && !b.empty())
            {
                ia = a.begin();
                ib = b.begin();
                prenum = *ib;
                prev=0;
                if(*ia<*ib)
                {
                    prev=1;
                    prenum=*ia;
                    a.erase(ia);
                }else b.erase(ib);
                c[prenum]=counter;
                d[prenum]=false;
                while(ia != a.end() && ib != b.end())
                {
                    if(prev)
                    {
                        ib = lbnd(ib,b.end(),prenum);
                        if(ib!=b.end())
                        {
                            prev=0;
                            prenum=*ib;
                            c[prenum]=counter;
                            d[prenum]=false;
                            b.erase(ib);
                        }
                    }else
                    {
                        ia = lbnd(ia,a.end(),prenum);
                        if(ia!=a.end())
                        {
                            prev=1;
                            prenum=*ia;
                            c[prenum]=counter;
                            d[prenum]=false;
                            a.erase(ia);
                        }
                    }
                }
                if(!a.empty())ia=a.begin();
                if(!b.empty())ib=b.begin();
                counter++;
            }
            if(prev ==0 && !a.empty() && a.back()>prenum)
            {
                c[a.back()]=--counter;
                a.pop_back();
                counter++;
            }
            if(prev == 1 && !b.empty() && b.back()>prenum)
            {
                c[b.back()]=--counter;
                b.pop_back();
                counter++;
            }
            for(int i:a)
            {
                c[i]=counter++;
            }
            
            for(int i:b)
            {
                c[i]=counter++;
            }
            counter--;
            cout<<counter<<endl;
            repn(i,n)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;
            

        }
    }
    
 	return 0;
}
 
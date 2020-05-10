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
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    
    while(t--)
    {
        cin>>n>>k;
        int a[n+1];
        bool b[n+1];
        memset(b,false,sizeof(b));
        vector<vi> ods,evs;
        int c=0;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=(a[i]==i);
            // if(a[i]==i)
        }
        for(int i=1;i<=n;i++)
        {
            if(!b[i])
            {
                vi v;
                v.pb(i);
                int j=a[i];
                b[i]=true;
                while(!b[j])
                {
                    v.pb(j);
                    b[j]=true;
                    j=a[j];
                }
                c+=v.size()/2;
                if(v.size()%2)
                {
                    ods.pb(v);
                }else evs.pb(v);
            }
        }
        if(evs.size()%2 || c>k)
        {
            cout<<"-1\n";
        }else
        {
            cout<<c<<endl;
            for(auto v:ods)
            {
                int m=v.size();
                for(int i=0;i+2<m;i+=2)
                {
                    cout<<v[0]<<" "<<v[i+1]<<" "<<v[i+2]<<endl;
                    
                }
            }
            for(auto v:evs)
            {
                int m=v.size();
                for(int i=0;i+2<m;i+=2)
                {
                    cout<<v[0]<<" "<<v[i+1]<<" "<<v[i+2]<<endl;
                }
            }
            // for(auto v:evs)
            // {
            //     for(auto i:v) cout<<i<<" ";
            //     cout<<endl;
            // }
            for(int i=0;i<evs.size();i+=2)
            {
                // cout<<vt[0]<<" "<<vt[vt.size()-1]<<" "<<vtt[0]<<endl;
                // cout<<vt[0]<<" "<<vtt[vtt.size()-1]<<" "<<vtt[0]<<endl;
            
                cout<<evs[i].front()<<" "<<evs[i].back()<<" "<<evs[i+1].front()<<endl;
                cout<<evs[i].front()<<" "<<evs[i+1].back()<<" "<<evs[i+1].front()<<endl;
            }
        }
        
    }
    
 	return 0;
}
 
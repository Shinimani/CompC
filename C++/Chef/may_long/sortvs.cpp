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
void swap(int p,int q,vi& v)
{
    int temp=v[p];
    v[p]=v[q];
    v[q]=temp;
}
int main()
{
    io

    int t,n,m;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    // string s;
    cin>>t;
    vi a;
    vector<bool> b;
    vector<vi> c;
    vector<pi> robot; 
    // map<pair<int,int>,int> r;
    bool r[19][19];
    vector<set<int>> s;
    while(t--)
    {
        cin>>n>>m;
        a.clear();
        b.clear();
        a.pb(0);
        b.pb(true);
        repn(i,n)
        {
            cin>>temp;
            a.pb(temp);
            b.pb(false);
        }
        // r.clear();
        memset(r,false,sizeof(r));
        robot.clear();
        repn(i,m)
        {
            cin>>p>>q;
            r[p][q]=true;
            r[q][p]=true;
            robot.push_back(mp(p,q));
        }
        // repn(i,n+1)
        // {
        //     repn(j,n+1)
        //     {
        //         cout<<r[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        c.clear();
        s.clear();
        for(int i=1;i<=n;i++)
        {
            if(b[i])continue;
            b[i]=(a[i]==i);
            if(!b[i])
            {
                b[i]=true;
                vi v;
                set<int> ss;
                ss.insert(i);
                v.pb(i);
                int j=a[i];
                while(j!=i)
                {
                    b[j]=true;
                    v.pb(j);
                    ss.insert(j);
                    j=a[j];
                }
                c.pb(v);
                s.pb(ss);
            }
        }
        ans=0;
        for(int j=0;j<c.size();j++)
        {
            for(int i:c[j])
            {
                cout<<i<<" ";
            }
            cout<<endl;
            //finding robot pairs which completely belong to this cycle
            set<pi> ths;
            for(auto p:robot)
            {
                if(s[j].count(p.F) && s[j].count(p.S))ths.insert(p);
            }
            //finding all pairs which help us in sorting
            auto it=ths.begin();
            for(it=ths.begin();it!=ths.end();it++)
            {
                cout<<it->F<<" "<<it->S<<endl;
            }
            it=ths.begin();
            while(!ths.empty() && it!=ths.end() )
            {
                if(a[it->F] == it->F && a[it->S]==it->S) 
                {
                    ths.erase(it);
                    if(!ths.empty())
                        it=ths.begin();
                }else
                {
                    if(a[it->F]==it->S || a[it->S]==it->F)
                    {
                        swap(it->F,it->S,a);
                        ths.erase(it);
                        if(!ths.empty())
                            it=ths.begin();
                    }else
                    {
                        it++;
                    }
                }
            }
            //finding the number of remaining pairs which need to be sorted
            for(int i:c[j])
            {
                if (a[i]!=i)ans++;
            }
        }
        if(ans>0)ans--;
        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
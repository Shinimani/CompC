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
    // io

    int t,n,k,x,m;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    unordered_map<int,int> mapp;
    vi o,e;
    
    while(t--)
    {
        cin>>n>>m;
        mapp.clear();
        int a[m];
        o.clear();e.clear();
        repn(i,n)
        {
            repn(j,m)
            {
                cin>>temp;
                mapp[temp]++;
            }
        }
        for(auto it:mapp)
        {
            if((it.second)%2==1)o.pb(it.first);
        }
        if(m%2==0)
        {
            if(!o.empty())
                cout<<"-1\n";
            else
            {
                auto it = mapp.begin();

                repn(i,n)
                {

                    vector<pi> v;
                    temp=0;
                    while(temp<m)
                    {
                        // cout<<"a";
                        // cout<<it->F<<" "<<it->S<<endl;
                        if(temp+(it->second) <=m)
                        {
                            v.pb(mp(it->first,it->second));
                            temp+=it->second;
                            it++;
                        }else
                        {
                            
                            mapp[it->F]-=(m-temp);
                            v.pb(mp(it->F,m-temp));
                            temp=m;
                        }
                    }
                    int j=0;
                    for(auto jj:v)
                    {
                        // cout<<"b";

                        while(jj.S!=0)
                        {
                            // cout<<"c";

                            a[j]=jj.F;
                            a[m-1-j]=jj.F;
                            jj.S-=2;
                            j++;
                        }
                    }
                    for(auto jj:a)
                    {
                        cout<<jj<<" ";
                    }
                    cout<<endl;

                }
            }
        }else
        {
            int barray[n];
            memset(barray,-1,sizeof(barray));
            if(o.size()>n)cout<<"-1\n";
            else
            {
                if((n-o.size())%2!=0)cout<<"-1\n";
                else
                {
                    
                    auto it=mapp.begin();
                    for(int zz=0;zz<o.size();zz++)
                    {
                        barray[zz]=o[zz];
                        mapp[o[zz]]--;
                        if(mapp[o[zz]]==0)mapp.erase(mapp.find(o[zz]));
                    }
                    int prev=-1,prevcount=0;
                    repn(i,n)
                    {
                        memset(a,0,sizeof(a));
                        if(barray[i]!=-1)
                        {
                            a[m/2]=barray[i];
                        }else
                        {
                            if(prevcount==0)
                            {
                                prev=it->F;
                                prevcount=2;
                                it->S-=2;
                                if(it->S==0)it++;
                            }
                            a[m/2]=prev;
                            prevcount--;
                        }
                        vector<pi> v;
                        temp=1;
                        while(temp<m)
                        {
                            if(temp+it->second <=m)
                            {
                                v.pb(*it);
                                temp+=it->second;
                                it++;
                                // mapp.erase(it);
                            }else
                            {
                                mapp[it->F]-=(m-temp);
                                v.pb(mp(it->F,m-temp));
                                temp=m;
                            }
                        }
                        int j=0;
                        for(auto jj:v)
                        {
                            while(jj.S!=0)
                            {
                                a[j]=jj.F;
                                a[m-1-j]=jj.F;
                                jj.S-=2;
                                j++;
                            }
                        }
                        for(auto jj:a)
                        {
                            cout<<jj<<" ";
                        }
                        cout<<endl;
                    }
                }
            }
                    
        }
            
            
        
        

    
        
    }
    
 	return 0;
}
 
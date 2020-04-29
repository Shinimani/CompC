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

    int t,n,temp,s,k;
    cin>>t;
    // int ans,p,q;
    bool ans;
    
    while(t--)
    {
        cin>>n>>k;
        vi arr[k];
        string str;
        repn(i,n)
        {
            cin>>temp;
            arr[i%k].push_back(temp);
        }
        if(k==1)cout<<"yes\n";
        else
        {
            
            repn(i,k)
            {
                sort(arr[i].begin(),arr[i].end(), greater<int>());
            }
            vi fin;
            int cou=0;
            for(int i=0;cou<n;i=(i+1)%k)
            {
                if(arr[i].empty()) continue;
                else
                {
                    fin.push_back(arr[i].back());
                    arr[i].pop_back();
                    cou++;
                }
            }
            ans=true;
            repn(i,n)
            {
                // cout<<fin[i]<<" ";
                if(i!=0 && fin[i]<fin[i-1])
                {
                    ans=false;
                    break;
                }
            }
            
            if(k==1||ans)cout<<"yes\n";else cout<<"no\n";   
            
            /* code */
        }
    }
    
 	return 0;
}
 
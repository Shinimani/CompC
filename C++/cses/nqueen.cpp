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
bool grid[8][8];
// bool placed[8][8];
bool diag1[15];
bool diag2[15];
bool cols[8];
// bool checkdiag(int i,int j)
// {
//     int x=i+1,y=j-1;
//     while (x<8 && y>=0)
//     {
//         if(placed[x][y]) return false;
//         x++;y--; 
//     }
//     x=i-1;y=j+1;
//     while(x>=0 && y<8)
//     {
//         if(placed[x][y]) return false;
//         x--;y++; 
//     }
//     x=i+1;y=j+1;
//     while(x<8 && y<8)
//     {
//         if(placed[x][y]) return false;
//         x++;y++; 
//     }
//     x=i-1;y=j-1;
//     while(x>=0 && y>=0)
//     {
//         if(placed[x][y]) return false;
//         x--;y--; 
//     }
//     return true;
// }
ll ans=0;
void search(int y)
{
    if(y==8)
    {
        ans++;
        return;
    }
    repn(x,8)
    {
        if(grid[y][x] || cols[x] || diag1[x+y] || diag2[x-y+7]) continue;
        cols[x]=diag1[x+y] =diag2[x-y+7]=true;
        search(y+1);
        cols[x]=diag1[x+y] =diag2[x-y+7]=false;
    }
}
int main()
{
    io

    char c;
    string s;
    repn(i,8)
    {
        cin>>s;
        repn(j,8)
        {
            // cin>>c;
            grid[i][j]=(s[j]!='.');
        }
    }
    search(0);
    cout<<ans<<endl;
    


 
 	return 0;
}
 
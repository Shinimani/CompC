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
void helperIsland(int i,int j, vector<string>& g,int mark, vector<vector<int>>& pos)
{
    if(g[i][j]=='.') return;
    g[i][j]='0';
    pos[i][j]=mark;
    int n=g.size();
    int m=g[0].length();
    int xd[4] = {1,-1,0,0};
    int yd[4] = {0,0,1,-1};
    repn(k,4)
    {
        if(!(i+yd[k]==-1 || i+yd[k]==n || j+xd[k]==-1 || j+xd[k]==m))
        {
            helperIsland(i+yd[k],j+xd[k],g,mark,pos);
        }
    }
}
pair<int,vector<vi>> numIslands(vector<string>& grid) {
    // if(grid.empty())return ;
    int n = grid.size();
    int m = grid[0].length();
    int ans=0;
    vector<vi> pos(n,vi(0,m));
    repn(i,n)
    {
        repn(j,m)
        {
            if(grid[i][j]=='#')
            {
                ans++;
                helperIsland(i,j,grid,ans,pos);
            }
        }
    }
    return mp(ans,pos);
}

int main()
{
    // io

    int t,n,m;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>n>>m;
    vector<string> g(n);
    vector<string> cc(n);
    repn(i,n)
    {
        cin>>s;
        g[i]=s;
        cc[i]=s;

    }
    // vector<string> cc =g;
    cout<<"before";
    // repn(i,n)
    // cout<<g[i]<<endl;
    pair<int,vector<vi>> pr = numIslands(cc);
    cout<<"before";
    
    vector<vi> vv = pr.second;
    cout<<"before";
    repn(r,n)
    {
        repn(c,m)
        {
            cout<<vv[r][c];
        }
        cout<<endl;
    }
    // cout<<"before";
    cout<<"here";
    bool flag=true;
    // int rf=-1,cf=-1;
    int cols[m];
    int rf=-1;
    memset(cols,-1,sizeof(cols));
    for(int r=0;r<n && flag;r++)
    {
        rf=-1;
        for(int c=0;c<m && flag;c++)
        {

            cout<<r<<" "<<c<<endl;
            if(g[r][c]=='#')
            {
                if(rf==-1)rf=pr.second[r][c];
                if(cols[c]==-1)cols[c]=pr.second[r][c];
                if(rf!=pr.second[r][c])
                {
                    flag=false;
                }
                if(cols[c]!=pr.second[r][c])
                {
                    flag=false;
                }
            }
            

            // if(r>0)
            // {
            //     cout<<"inside";
            //     // cout<<"1"<<endl;
            //     if(g[r-1][c]!='#')
            //     {
            //         int i=r-1;
            //         int k=pr.second[r][c];
            //         while(i>=0)
            //         {
            //             cout<<i<<endl;
            //             if(g[i][c]=='.' || pr.second[i][c]==k)i--;
            //             else{
            //                 flag=false;
            //                 i=-1;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // if(!flag) break;
            // cout<<"here1\n";
            // if(r<n-1)
            // {
            //     // cout<<"2"<<endl;

            //     if(g[r+1][c]!='#')
            //     {
            //         int i=r+1;
            //         int k=pr.second[r][c];
            //         while(i<n)
            //         {
            //             if(g[i][c]=='.' || pr.second[i][c]==k)i++;
            //             else{
            //                 i=n;
            //                 flag=false;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // if(!flag) break;
            // cout<<"here2\n";

            // if(c>0)
            // {
            //     // cout<<"3"<<endl;

            //     if(g[r][c-1]!='#')
            //     {
            //         int i=c-1;
            //         int k=pr.second[r][c];
            //         while(i>=0)
            //         {
            //             if(g[r][i]=='.' || pr.second[r][i]==k)i--;
            //             else{
            //                 flag=false;
            //                 i=-1;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // if(!flag) break;
            // cout<<"here3\n";

            // if(c<m-1)
            // {
            //     cout<<"4"<<endl;

            //     if(g[r][c+1]!='#')
            //     {
            //         int i=c+1;
            //         int k=pr.second[r][c];
            //         while(i<m)
            //         {
            //             if(g[r][i]=='.' || pr.second[r][i]==k)i++;
            //             else{
            //                 flag=false;
            //                 i=m;
            //                 break;
            //             }
            //         }
            //     }
            // }
        }
    }
    if(flag)cout<<pr.first<<endl;
    else cout<<"-1\n";
 	return 0;
}
 
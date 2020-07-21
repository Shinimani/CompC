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

const int sz = 2e5+1; 
  
// Adjacency list representation 
// of the tree 
vector<int> tree[sz]; 
  
// Boolean array to mark all the 
// vertices which are visited 
bool vis[sz]; 
  
// Array of vector where ith index 
// stores the path from the root 
// node to the ith node 
vector<int> path[sz]; 
  
// Utility function to create an 
// edge between two vertices 
void addEdge(int a, int b) 
{ 
  
    // Add a to b's list 
    tree[a].push_back(b); 
  
    // Add b to a's list 
    tree[b].push_back(a); 
} 
  
// Modified Breadth-First Function 
void bfs(int node) 
{ 
  
    // Create a queue of {child, parent} 
    queue<pair<int, int> > qu; 
  
    // Push root node in the front of 
    // the queue and mark as visited 
    qu.push({ node, -1 }); 
    vis[node] = true; 
  
    while (!qu.empty()) { 
        pair<int, int> p = qu.front(); 
  
        // Dequeue a vertex from queue 
        qu.pop(); 
        vis[p.first] = true; 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If any adjacent has not 
        // been visited then enqueue it 
  
        for (int child : tree[p.first]) { 
            if (!vis[child]) { 
                qu.push({ child, p.first }); 
  
                // Path from the root to this vertex is 
                // the path from root to the parent 
                // of this vertex followed by the 
                // parent itself 
                path[child] = path[p.first]; 
                path[child].push_back(p.first); 
            } 
        } 
    } 
} 
  
// Utility Function to print the 
// path from root to given node 
vi displayPath(int node) 
{ 
    vector<int> ans = path[node]; 
    // for (int k : ans) { 
    //     cout << k << " "; 
    // }
    ans.push_back(node); 
    return ans;
    // cout << node << '\n'; 
} 
  
// Driver code 
// int main() 
// { 
  
//     // Number of vertices 
//     int n = 6; 
  
//     addEdge(0, 1); 
//     addEdge(0, 2); 
//     addEdge(1, 3); 
//     addEdge(3, 4); 
//     addEdge(3, 5); 
  
//     // Calling modified bfs function 
//     bfs(0); 
  
//     // Display paths from root vertex 
//     // to the given vertices 
//     displayPath(2); 
//     displayPath(4); 
//     displayPath(5); 
  
//     return 0; 
// } 
int main()
{
    // io

    int t,n,k,x;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    vi pv,qv;
    while(t--)
    {
        cin>>n>>k;
        // memset(tree,0,sizeof(tree));
        // memset(path,0,sizeof(path));
        memset(vis,false,sizeof(vis));
        int a[n];
        repn(i,n)
        {
            cin>>a[i];
        }
        repn(i,n-1)
        {
            cin>>p>>q;
            addEdge(p,q);
        }
        // cout<<"here";
        bfs(1);
        repn(i,k)
        {
            cin>>p>>q;
            pv=displayPath(p);
            qv=displayPath(q);

            int pp = pv.size();
            int qq = qv.size();
            vi v;
            int j;
            // for(int k:pv)
            // {
            //     cout<<k<<" ";
            // }
            // cout<<endl;
            // for(int k:qv)
            // {
            //     cout<<k<<" ";
            // }
            // cout<<endl;
            
            for(j=0;j<min(pp,qq);j++)
            {
                if(pv[j]==qv[j])continue;
                else 
                {
                    j--;
                    break;    
                }
            }
            if(j==pp || j==qq)j--;
            for(int k=j;k<pp;k++)
            {
                v.pb(a[pv[k]-1]);
            }
            // cout<<"there";
            for(int k=j+1;k<qq;k++)
            {
                v.pb(a[qv[k]-1]);
            }
            // cout<<"there";
            sort(all(v));
            // cout<<"sorted";

            int prev=v[0];
            // cout<<"thesddrse";

            ans=v[1]-v[0];
            // cout<<"therse";

            for(j=1;j<v.size();j++)
            {
                // cout<<j<<" ";
                ans=min(ans,v[j]-prev);
                prev=v[j];
                if(ans==0)break;
            }
            // cout<<"there";

            cout<<ans<<endl;
        }
        // cout<<"fin\n";

        for(int i=1;i<=n;i++)
        {
            path[i].clear();
            tree[i].clear();
        }
        // cout<<"fin\n";

    
        
    }
    
 	return 0;
}
 
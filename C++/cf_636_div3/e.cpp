#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
// #define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
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
typedef vector<int> vi;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

// To compute x^y under modulo m 
ll expo(ll base, ll exponent, ll mod) {                                //return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
long long modInverse(long long a, long long m) 
{ 
    return expo(a, m-2, m); 
} 
  

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

// utility function to form edge between two vertices 
// source and dest 
void add_edge(vector<int> adj[], int src, int dest) 
{ 
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
} 
  
// a modified version of BFS that stores predecessor 
// of each vertex in array p 
// and its distance from source in array d 
bool BFS(vector<int> adj[], int src, int dest, int v, 
                            int pred[], int dist[]) 
{ 
    // a queue to maintain queue of vertices whose 
    // adjacency list is to be scanned as per normal 
    // DFS algorithm 
    list<int> queue; 
  
    // boolean array visited[] which stores the 
    // information whether ith vertex is reached 
    // at least once in the Breadth first search 
    bool visited[v]; 
  
    // initially all vertices are unvisited 
    // so v[i] for all i is false 
    // and as no path is yet constructed 
    // dist[i] for all i set to infinity 
    for (int i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 
  
    // now source is first to be visited and 
    // distance from source to itself should be 0 
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 
  
    // standard BFS algorithm 
    while (!queue.empty()) { 
        int u = queue.front(); 
        queue.pop_front(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 
  
                // We stop BFS when we find 
                // destination. 
                if (adj[u][i] == dest) 
                   return true; 
            } 
        } 
    } 
  
    return false; 
} 
  
// utility function to print the shortest distance  
// between source vertex and destination vertex 
vector<int> printShortestDistance(vector<int> adj[], int s,  
                                    int dest, int v) 
{ 
    // predecessor[i] array stores predecessor of 
    // i and distance array stores distance of i 
    // from s 
    int pred[v], dist[v]; 
    vector<int> path; 
  
    if (BFS(adj, s, dest, v, pred, dist) == false) 
    { 
        cout << "Given source and destination"
             << " are not connected"; 
        return path; 
    } 
  
    // vector path stores the shortest path 
    int crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
    return path;
    // // distance from source is in distance array 
    // cout << "Shortest path length is : "
    //     << dist[dest]; 
  
    // // printing path from source to destination 
    // cout << "\nPath is::\n"; 
    // for (int i = path.size() - 1; i >= 0; i--) 
    //     cout << path[i] << " "; 
} 




int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // const int N = 1e6 + 7;
    // const int K = 24;

    int t,temp,n,m,a,b,c,x,y,commoncount,remcount;
    // string s;
    cin>>t;
	// unordered_map<int,int> counts;
    while(t--)
    {
		cin>>n>>m>>a>>b>>c;
        vi adj[n];
        // prices.clear();
    vi prices;
        // counts.clear();
        repn(i,m)
        {
            cin>>x;
            prices.pb(x);
        }
        sort(prices.begin(),prices.end());
        repn(i,m)
        {
            cin>>x>>y;
            add_edge(adj,x-1,y-1);
        }
        vi pab = printShortestDistance(adj,a-1,b-1,n);
        // for(auto i:pab)
        //     cout<<i<<" ";
        // cout<<endl;
        sort(pab.begin(),pab.end());
        vi pbc = printShortestDistance(adj,b-1,c-1,n);
        // for(auto i:pbc)
        //     cout<<i<<" ";
        // cout<<endl;
        
        sort(pbc.begin(),pbc.end());
        vector<int> v(pab.size() + pbc.size()); 
        vector<int>::iterator it, st; 
    
        it = set_intersection(pab.begin(), 
                            pab.end(), 
                            pbc.begin(), 
                            pbc.end(), 
                            v.begin()); 

        // cout << "\nCommon elements:\n"; 

        commoncount=0;
        for (st = v.begin(); st != it; ++st) 
            commoncount++;
        // cout << '\n'; 
        remcount=pab.size()+pbc.size()-2*commoncount;
        int i=0;
        int ans=0;
        // cout<<commoncount<<" "<<remcount<<endl;
        commoncount--;

        while(commoncount+remcount!=0)
        {
            if(commoncount!=0)
            {
                commoncount--;
                ans+=2*prices[i++];
            }else
            {
                remcount--;
                ans+=prices[i++];
            }
            
        }
        cout<<ans<<endl;



        

    }

    
 	return 0;
}
 
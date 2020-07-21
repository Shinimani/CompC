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

class Graph 
{ 
// No. of vertices' 
    int V;     
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], 
 stack<int> &Stack); 
    bool isCyclicUtil(int v, bool visited[], bool *rs);
public: 
// Constructor 
    Graph(int V);    
  
     // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of  
// the complete graph 
    stack<int> topologicalSort(); 
    bool isCyclic(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
// Add w to v’s list. 
    adj[v].push_back(w);  
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil( 
int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices  
// adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack  
// which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
stack<int> Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
// to store Topological 
    // Sort starting from all  
// vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // // Print contents of stack 
    // while (Stack.empty() == false) 
    // { 
    //     cout << Stack.top() << " "; 
    //     Stack.pop(); 
    // } 
    return Stack;
} 
 
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
 
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 
  
  

int main()
{
    io

    int t,n,k,x,m;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    // string s;
    cin>>t;
    int a,b,c;
    vector<pi> v,w;
    int arr[200000];
    while(t--)
    {
        cin>>n>>m;
        Graph g(n);
        v.clear();
        w.clear();
        memset(arr,-1,sizeof(arr));
        repn(i,m)
        {
            cin>>a>>b>>c;
            if(a==1)
            {
                g.addEdge(b-1,c-1);
                w.pb(mp(b-1,c-1));
            }
                
            else
            {
                v.pb(mp(b-1,c-1));
            }
        }
        if(g.isCyclic()) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        
            stack<int> s = g.topologicalSort();
            int i=n;
            while(!s.empty())
            {
                arr[s.top()]=i;
                s.pop();
                i--;
            }
            for(auto p:v)
            {
                if(arr[p.first]>arr[p.second])
                {
                    cout<<p.first+1<<" "<<p.second+1<<endl;
                }
                else cout<<p.second+1<<" "<<p.first+1<<endl;
            }
            
            for(auto p:w)
            {
                if(arr[p.first]>arr[p.second])
                {
                    cout<<p.first+1<<" "<<p.second+1<<endl;
                }
                else cout<<p.second+1<<" "<<p.first+1<<endl;
            }
        }

    
        
    }
    
 	return 0;
}
 
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
struct TrieNode { 
    struct TrieNode* children[26]; 
  
    bool isEnd; 
}; 
  
struct TrieNode* getNode(void) 
{ 
    struct TrieNode* trieNode = new TrieNode; 
  
    trieNode->isEnd = false; 
  
    for (int i = 0; i < 26; i++) 
        trieNode->children[i] = NULL; 
  
    return trieNode; 
} 
 
bool insert(struct TrieNode* root, string key) 
{ 
    struct TrieNode* trieHelper = root; 
    bool flag = true;
    for (int i = 0; i < key.length() && flag; i++) { 
        int index = key[i] - 'a'; 
        if (!trieHelper->children[index]) 
            trieHelper->children[index] = getNode(); 
        else
        {
            flag = !trieHelper->children[index]->isEnd;
        }
        trieHelper->isEnd = false; 
        trieHelper = trieHelper->children[index]; 
    } 
    if(!flag)return flag;
    int i; 
    
    for (i = 0; i < 26; i++) { 
        if (trieHelper->children[i]) { 
            return false; 
        } 
    } 
    if (i == 26) { 
        trieHelper->isEnd = true; 
    } 
    return true;
} 
string GoodOrBad(int n, vector<string> v)
{
    struct TrieNode* root = getNode();
    bool f;
    for(int i=0;i<n;i++)
    {
        f = insert(root,v[i]);
        if(!f)
            return v[i];
    }
    return "";
}

  


int main()
{
    // io

    int t,n;
    int a,b,c;
    int temp,ans;
    int p,q;
    int x,y,z;
    
    // ll t,n;
    // ll a,b,c;
    // ll temp,ans;
    // ll p,q;
    // ll x,y,z;
    vector<string> v;
    
    // v.pb("aaefcs");
    // v.pb("aae");
    // v.pb("aac");
    // v.pb("aadfg");
    // cout<<GoodOrBad(4,v);
    
    string s;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        cout<<n*10<<" "<<n*2<<endl;
        // cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
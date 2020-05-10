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
bool isBadVersion(int version);

int firstBadVersion(int n) {
    ll k = 1;
    if(isBadVersion(1)) return 1; 
    for (ll b = n/2; b >= 1; b /= 2) { while (k+b <= n && !isBadVersion(k+b)) k += b;
    }
    if(isBadVersion(k+1))return k+1;
    return n;
}
int numJewelsInStones(string J, string S) {
    set<char> s;
    for(char c:J)
    {
        s.insert(c);
    }    
    int ans=0;
    for(char c:S)
    {
        if(s.count(c))ans++;
    }
    return ans;
}
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> m;
    for(char c='a';c<='z';c++)
    {
        m[c]=0;
    }
    for(char c:magazine)
        m[c]++; 
    bool flag=true;
    for(char c:ransomNote)
    {
        m[c]--;
        if(m[c]<0)
        {
            flag=false;break;
        }
    }
    return flag;
}
int findComplement(int num) {
    bitset<32> b(num);
    bool f=true;
    b.flip();
    for(int i=31;i>=0;i--)
    {
        if(b[i])
        {
            b.flip(i);
        }else break;
    }
    return (int)(b.to_ulong());
}
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> m;
    int n=nums.size();
    n/=2;

    for(auto i:nums)
    {
        m[i]++;
        if(m[i]>n)return i;
    }    
    return -1;
}
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> p1 = helper(root,x,0,0);
        pair<int,int> p2 = helper(root,y,0,0);
        if(p1.second==p2.second && p1.first!=p2.first)return true;else return false;

    }
    pair<int,int> helper(TreeNode* root, int x,int d,int p)
    {
        
        if(root->val == x)
        {
            return make_pair(p,d);
        }else if(root==nullptr || (root->left==nullptr && root->right==nullptr)) return make_pair(0,0);
        else 
        {
            pair<int,int> p1=make_pair(0,0);
            pair<int,int> p2=make_pair(0,0);
            if(root->left != nullptr) p1 = helper(root->left,x,d+1,root->val);
            if(root->right != nullptr) p2 = helper(root->right,x,d+1,root->val);
            return make_pair(p1.first+p2.first,p1.second+p2.second);
        }
    }
    
};
bool isPerfectSquare(int num) {
    int k=0;
    while(num%2==0)
    {
        num/=2;
        k++;
    }    
    if((k%2)!=0) return false;
    for(int i=3;i*i<=num;i+=2)
    {
        if(num%i==0)
        {
            k=0;
            while(num%i==0)
            {
                num/=i;
                k++;
            }
            if((k%2)!=0) return false;
        }
    }
    return num==1;
}
int findJudge(int n, vector<vector<int>>& t) {
    bool b[n];
    memset(b,true,sizeof(b));
    for(auto v:t)
    {
        b[v[0]]=false;
    }   
    int ans=-1; 
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(b[i])
        {
            if(!f)
            {
                f=true;
                ans=i+1;
            }else
            {
                ans=-1;
                i=n;
                break;
            }
        }
    }
    if(ans==-1)return ans;
    // memset(b,false)
    int k=0;
    for(auto v:t)
    {
        if(v[1]==ans)k++;
    }
    if(k==(n-1))return ans;else return -1;
}
int main()
{
    io

    int t,n;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
    
        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
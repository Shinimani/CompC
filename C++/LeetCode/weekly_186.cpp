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
string destCity(vector<vector<string>>& paths) {
    map<string,int> m;
    for(auto v:paths)
    {
        m[v[0]]++;
        m[v[1]]+=0;
    }
    for(auto it:m)
    {
        if(it.second==0)return it.first;
    }    
    return NULL;
}
bool kLengthApart(vector<int>& nums, int k) {
    int d=0;
    bool f=true;
    for(int i:nums)
    {
        if(i)
        {
            if(f)
            {
                f=false;
            }else if(d<k)
            {
                return false;
            }else
            {
                d=0;
            }
        }else d++;
    }
    return true;    
}
int longestSubarray(vector<int>& nums, int limit) {
    std::set<int> q;
    map<int,int> m;

    int i=0,j=1;
    int n=nums.size();
    int ans=1;
    q.insert(nums[0]);
    m[nums[0]]++;
    while(j<n)
    {
        if(q.empty() || abs(*q.begin() - nums[j])<=limit && abs(*q.rbegin()-nums[j]<=limit))
        {
            q.insert(nums[j]);
            m[nums[j]]++;
            ans=max(ans,j-i+1);
            j++;
        }else
        {
            // if(m[nums[i]]--)
            m[nums[i]]--;
            if(m[nums[i]]==0)
            {
                q.erase(q.find(nums[i]));
            }
            i++;
        }
    }   
    return ans; 
}
int firstUniqChar(string s) {
    unordered_map<char,vector<int>> m;
    int n= s.length();
    for(int i=0;i<n;i++)
    {
        m[s[i]].push_back(i);
    }    
    int ans=INT16_MAX;
    bool f=false;
    unordered_map<char,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if((it->second).size()==1)
        {
            f=true;
            ans=min(ans,it->second[0]);
        }
    }
    if(f)return ans;else return -1;
}
int kthSmallest(vector<vector<int>>& mat, int k) {
    int n=mat.size();
    int m=mat[0].size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p;
    vector<int> a(n,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=mat[i][0];
        p.push(make_pair(mat[i][1]-mat[i][0],make_pair(i,1)));
    }
    while(k>1)
    {
        if(p.top().second.second==m-1)
        {
            ans+=p.top().first;
            p.pop();
        }else
        {
            ans+=p.top().first;
            int r=p.top().second.first;
            int c=p.top().second.second;
            c++;
            p.pop();
            p.push(make_pair(mat[r][c]-mat[r][c-1],make_pair(r,c)));
        }
        k--;
    }
    return ans;
}
// void main()
// {
//    custom_priority_queue<int> queue;

//    queue.push(10);
//    queue.push(2);
//    queue.push(4);
//    queue.push(6);
//    queue.push(3);

//    queue.remove(6);

//    while (!queue.empty())
//    {
//       std::cout << queue.top();
//       queue.pop();

//       if (!queue.empty())
//       {
//         std::cout << ", ";
//       }
//    }

//  }

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
 
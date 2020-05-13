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
/*
int main()
{
    io

    int t,n,k,x;
    int temp,ans,p,q;
    // ll temp,ans,p,q;
    string s;
    cin>>n;
    int a[n];
    repn(i,n)
    {
        cin>>a[i];
    }
    temp=ans=0;
    unordered_map<int,int> m;
    repn(i,n)
    {
        if(m.find(a[i])==m.end())
        {
            m[a[i]]=i;
            temp++;
        }else
        {
            temp=i-m[a[i]];
            m[a[i]]=i;
        }
        ans=max(temp,ans);
        
    }
    cout<<ans;
    
 	return 0;
}
 */
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0;
  int j = 0;
  int m = 1;
  set<int> s;
  while (j < n) {
    if (s.count(a[j])) {
      m = max(m, j - i);
      while (a[i] != a[j]) {
        s.erase(a[i++]);
      }
      i++;
    } else s.insert(a[j]);
    j++;
  }
  m = max(m, j - i);
  cout << m << endl;
}
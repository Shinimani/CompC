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
// // }
// int a[200000];
// int main()
// {
//     io

//     int n,m;
//     int temp,p,q;
//     // ll temp,ans,p,q;
//     string s;
//     cin>>n>>m;
//     vi h(n);
//     // int
//     // memset(a,0,sizeof(a));
//     repn(i,n)
//     {
//         cin>>h[i];
//         // a[temp]++;
//     }
    
//     sort(all(h));

//     repn(i,m)
//     {
//         cin>>temp;
//         if(h.empty())cout<<"-1 ";
//         if(n==0)cout<<"-1 ";
//         else
//         {
//             // if(a[temp])
//             // {
//             //     cout<<temp<<" ";
//             //     a[temp]--;
//             //     n--;
//             // }

//             auto it=lbnd(all(h),temp);
//             if(*it==temp)
//             {
//                 cout<<*it<<" ";
//                 h.erase(it);
//             }else
//             {
//                 if(it!=h.begin())
//                 {
//                     it--;
//                     cout<<*it<<" ";
//                     h.erase(it);
//                 }else
//                 {
//                     cout<<"-1 ";
//                 }
                
//             }
            
//         }
        
//     }
    
    
//  	return 0;
// }
// https://cses.fi/problemset/task/1091/
// #include <iostream>
// #include <set>
// #include <vector>

// using namespace std;

int main() {
    io
    
  int n, m, x;
  cin >> n >> m;
  multiset<int, greater<int>> h;
  while (n--) {
    cin >> x;
    h.insert(x);
  }
  while (m--) {
    cin >> x;
    auto it = h.lower_bound(x);
    if (it == h.end()) cout << "-1\n";
    else {
      cout << *it << endl;
      h.erase(it);
    }
  }
} 

// int main() { 
//     long long N, M;
//     cin >> N >> M; 
//     vector<int> h(N);
//     // long long *t = new long long[M];
//     for(int a = 0; a < N; ++a)
//         cin >> h[a];
//     sort(h.begin(), h.end()); 
//     for(int a = 0; a < M; ++a){
//         long long val;
//         cin >> val;
//         long long idx = *upper_bound(h.begin(), h.end(), val);
//         cout << val << endl;
//         cout << idx << endl;
//         // cout << h[idx] << endl;
//         // h.erase(h.begin() + idx);
//     }    

//     return 0; 
// }
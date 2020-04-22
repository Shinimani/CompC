
#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
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
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005
void multiply(ll F[2][2], ll M[2][2])
{
    ll x =  ((F[0][0] * M[0][0])%hell1 + (F[0][1] * M[1][0])%hell1)%hell1;
    ll y =  ((F[0][0] * M[0][1])%hell1 + (F[0][1] * M[1][1])%hell1)%hell1;
    ll z =  ((F[1][0] * M[0][0])%hell1 + (F[1][1] * M[1][0])%hell1)%hell1;
    ll w =  ((F[1][0] * M[0][1])%hell1 + (F[1][1] * M[1][1])%hell1)%hell1;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
 /* 
  * function to calculate power of a matrix
  */
void power(ll F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}
 
/* 
 * function that returns nth Fibonacci number 
 */
ll fib(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0]%hell1;
}
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
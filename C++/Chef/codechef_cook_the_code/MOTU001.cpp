#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl ('\n')
#define MODLS 1000000007 
#define hell        1000000007
#define hell1       1000000006


long long gcd(long long u,long long v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
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
  

// Function to return gcd of a and b 
// int gcd(int a, int b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b%a, a); 
// } 
// // // #define MAX 1000000
int primes[100009],cnt=0;
// vector<int> factors[1000009];
char str[1000009];
void pre()
{
    // calcualting primes
    int n=1000000;
    for(int i=2; i*i<=n; i++)
        if(str[i]==0)
            for(int j=i; j*i<=n; j++)
                str[i*j]=1;
    for(int i=2; i<=n; i++)
        if(str[i]==0)primes[cnt]=i,cnt++;
}


// long long fib(int n) { 
// double phi = (1 + sqrt(5)) / 2; 
// return round(pow(phi, n) / sqrt(5)); 
// } 

void multiply(long long F[2][2], long long M[2][2]); 
  
void power(long long F[2][2], long long n); 
  
/* function that returns nth Fibonacci number */
long long fib(long long n) 
{ 
  long long F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]%hell1; 
} 
  
/* Optimized version of power() in method 4 */
void power(long long F[2][2], long long n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  long long M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
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
// #define pb push_back
#define modulo 1000000007 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,k,p,q,inv,ans,pow,fp,fq;
    long long m = 1000000007 ;
    cin>>t;
    // unordered_map<int,vector<int>> mp;
    // unordered_map<int,vector<int>>:: iterator p,q;

    while(t--)
    {
        cin>>p>>q>>n;
        if(n==0) cout<<p<<"\n";
        else if (n==1) cout<<q<<"\n";
        else
        {
            fp=fib(n-1);
            fq=fib(n);
            p=expo(p+1,fp,m);
            q=expo(q+1,fq,m);
            ans=((p*q)%m - 1+m )%m;
            cout<<ans<<"\n";
            
        }
        

        
    }
    // char ch = 97;
    // char cb = ch+1;
    // cout<<cb<<endl;



    
 	return 0;
}
 
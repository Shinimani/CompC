#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
#define sc(n) fastscan(n)
#define fr(i,a,b) for(int i=a;i<b;i++)
// https://www.codechef.com/problems/TAAND

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 
long long gcd(long long u,long long v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}

#define MAXN   1001
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 
// To compute x^y under modulo m 
long long power(long long x, long long y, long long m) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
#define MOD 1000000007;
int main() {
    // sieve();
    int t,d;
    long long a,b,n,g,ans;
    fastscan(t);
    while(t--)
    {
        fastscan(d);
        n = power(2,d+1,1000000007);
        // n = 1<<(d+1);
        n-=1;

        a=0;
        for(int i =0;i<d;i++)
        {
            for(int k=1;i+k<=d;k+=2)
            {
                g=power(2,i+k,1000000007);
                g%=1000000007;
                a+=g;
                a%=MOD;
            }
        }
        b = n*(n-1);
        b%=1000000007;
        g = gcd(a,b);
        a/=g;
        b/=g;
        b = power(b,1000000007 -2,1000000007);
        a%=1000000007;
        b%=1000000007;
        ans = a*b;
        ans %=1000000007;
        printf("%d\n",ans);

        
    }
}
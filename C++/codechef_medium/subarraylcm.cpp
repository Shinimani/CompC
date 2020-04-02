#include<bits/stdc++.h>
using namespace std;
// /************************************************************************************************/
// static struct IO {char tmp[1 << 10];char cur;inline char nextChar()
// { return cur = getc_unlocked(stdin); }inline char peekChar() { return cur; }
// inline operator bool() { return peekChar(); }inline static bool isBlank(char c)
// { return (c < '-' && c); }inline bool skipBlanks()
// { while (isBlank(nextChar())); return peekChar() != 0; }
// inline IO& operator >> (char & c) { c = nextChar(); return *this; }
// inline IO& operator >> (char * buf) {if (skipBlanks()) {if (peekChar()) {*(buf++) = peekChar();
// while (!isBlank(nextChar())) *(buf++) = peekChar();} *(buf++) = 0; } return *this; }
// inline IO& operator >> (string & s) {if (skipBlanks()) {	s.clear(); s += peekChar();
// while (!isBlank(nextChar())) s += peekChar(); }return *this; }
// inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
// #define defineInFor(intType) inline IO& operator >>(intType & n) { if (skipBlanks()) { \
// int sign = +1; if (peekChar() == '-') { sign = -1; n = nextChar() - '0'; } else \
// n = peekChar() - '0'; while (!isBlank(nextChar())) { n += n + (n << 3) + peekChar() - 48; } \
// n *= sign; } return *this; }
// defineInFor(int)defineInFor(unsigned int)defineInFor(long long)
// inline void putChar(char c) { putc_unlocked(c, stdout); }inline IO& operator << (char c) { putChar(c); return *this; }
// inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
// inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
// char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
// inline IO& operator << (double d) { return (*this) << toString(d); }
// #define defineOutFor(intType) inline char * toString(intType n) { char * p = (tmp + 30); \
// if (n) { bool isNeg = 0; if (n < 0) isNeg = 1, n = -n; while (n) *--p = (n % 10) + '0', n /= 10; \
// if (isNeg) *--p = '-'; } else *--p = '0'; return p; } inline IO& operator << (intType n) { return (*this) << toString(n); }
// defineOutFor(int)defineOutFor(long long)
// #define endl ('\n')
// #define cout __io__
// #define cin __io__
// } __io__;
// /**************************************************************************************************/
 

long long gcd(long long u,long long v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
// #define MAX 1000000
int primes[100009],last[1000009]={},cnt=0;
vector<int> factors[1000009];
char str[1000009];
void pre()
{
    // calcualting primes
    int n=10000;
    for(int i=2; i*i<=n; i++)
        if(str[i]==0)
            for(int j=i; j*i<=n; j++)
                str[i*j]=1;
    for(int i=2; i<=n; i++)
        if(str[i]==0)primes[cnt]=i,cnt++;
}
#define pb push_back
int main()
{
    pre();
     int i,j,k;
    // calculating prime factors of each number
    for(i=2; i<=1000000; i++)
    {
        j=i;
        for(int k=0; primes[k]*primes[k]<=j; k++)
        {
            if(j%primes[k]==0)
            {
                factors[i].pb(primes[k]);
                while(j%primes[k]==0)j/=primes[k];
            }
        }
        if(j>=2)factors[i].pb(j);
    }
    
    // cout<<"Here";
    //factors contains vectors of all prime factors of all numbers less than 1000000
    int t;
    cin>>t;
    int n;
    // int last[1000009];
    int curr;
    int prev,ans,temp;
    while(t--)
    {
        cin>>n;
        memset(last,-1,sizeof(last));
        // for(int i=0;i<n;i++)
        // cin>>arr[i];
        cin>>curr;
        for(int i:factors[curr])
        {
            last[i]=1;
        }
        prev=0;
        ans=1;
        for(int i=1;i<n;i++)
        {
            cin>>curr;
            // curr=arr[i];
            for(int k:factors[curr])
            {
                // cout<<
                if(last[k]>prev) prev=last[k];
                last[k]=i+1;
            }
            ans=max(ans,i-prev+1);
        }
        if(ans<2)ans=-1;
        cout<<ans<<endl;
    }



    
 	return 0;
}
 
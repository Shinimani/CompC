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


// void fastscan(int &x)
// {
//     bool neg=false;
//     register int c;
//     x =0;
//     c=getchar();
//     if(c=='-')
//     {
//         neg = true;
//         c=getchar();
//     }
//     for(;(c>47 && c<58);c=getchar())
//         x = (x<<1) + (x<<3) +c -48;
//     if(neg)
//         x *=-1;
// } 
#define MODLS 1000000007 
long long gcd(long long u,long long v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
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
// #define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    // int arr[101];
    // pre();
    int cou,i;
    cin>>t;
    long long ans;
    int x,k;
    while(t--)
    {
        cin>>x>>k;
        cou=0;
        while(x%2==0)
        {
            cou++;
            x/=2;
        }
        // i=3;
        for(i=3;i<=sqrt(x);i+=2)
        {
            while(x%i==0)
            {
                cou++;
                x/=i;
            }

        }
        if(x!=1) cou++;
        // cou++;

        if(cou>=k)cout<<"1\n";else cout<<"0\n";
        // cout<<ans<<endl;
    }
    



    
 	return 0;
}
 
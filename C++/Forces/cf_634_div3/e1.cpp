#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
#define pb push_back
typedef vector<int> vi ;
typedef vector<long long> vl ;
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
int gcd(int u,int v)
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
    int t,n,temp,s;
    cin>>t;
    vector<int> arr;
    vi pos[200];
    // vector<vi> cnt;
    // vector<vi> pos;
    int ans,p,q;
    // vector<vector<in
    // unordered_map<int,vector<int>> mp;
    // unordered_map<int,vector<int>>:: iterator p,q;

    while(t--)
    {
        cin>>n;
        int cnt[n+1][200];
        memset(cnt,0,sizeof(cnt));
        repn(i,200)
        {
            pos[i].clear();
            // cnt[0][i]
        }
        // cnt.clear();
        // pos.clear();
        repn(i,n)
        {
            cin>>temp;
            arr.push_back(temp);
            pos[temp-1].pb(i);
            repn(j,200) cnt[i+1][j]=cnt[i][j];
            cnt[i+1][temp-1]++;
        }
        ans=0;
        repn(i,200)
        {
            s=pos[i].size();
            ans=max(ans,s);
            repn(j,s/2)
            {   
                p=pos[i][j]+1;
                q=pos[i][s-j-1]-1;
                repn(k,200)
                {
                    ans=max(ans,((j+1)*2 + cnt[q+1][k]-cnt[p][k]));
                }
            }
        }

        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
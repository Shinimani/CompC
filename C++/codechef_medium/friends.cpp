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
int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
int main()
{
    int n;
    cin>>n;
    long long adj[2001][40]={0LL};
    string s;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j =0;j<n;j++)
        {
            if(s[j]=='0') continue;
            x=j/64;
            y=j%64;
            adj[i][x] |= (1LL<<y);
        }
    }
    int ans=0;
    int nn = (n+63)/64;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (i==j) continue;
            x=j/64;
            y=j%64;
            if(adj[i][x] & (1LL<<y)) continue;

            for(y=0;y<=nn;y++)
            {
                if (adj[i][y] & adj[j][y]) break; 
            }
            if (y<=nn) ans++;
        }
    }
    cout<<ans<<endl;
 	return 0;
}
 
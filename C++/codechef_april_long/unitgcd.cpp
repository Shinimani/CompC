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
int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
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
// #define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    // int arr[101];
    vector<vector<int>> ans;
    pre();
    int cou,i,j,p;
    cin>>t;
    // long long ans;
    int x,k;
    bool flag;
    while(t--)
    {
        memset(str,'0',sizeof(str));
        cin>>n;
        k=0;
        // ans.clear();
        
        for(i=1;i<=(n/2);i++)
        {
            vector<int> temp;
            temp.push_back(2*i);
            ans.push_back(temp);
            k++;
            str[2*i]='1';
        }
        ans[0].push_back(1);
        str[1]='1';
        k++;
        x=3;i=0;cou=1;
        while(x*cou<=n)
        {
            if(str[x*cou]=='0')
            {
                if(i%3==2)
                    i++;
                ans[i].push_back(x*cou);
                str[x*cou]='1';
                i++;
            }
            cou++;
        }
        for(i=2;primes[i]<=sqrt(n);i++)
        {
            x=primes[i];
            // cout<<x<<endl<<endl;
            if(str[x]=='0')
                ans[0].push_back(x);
            str[x]='1';

            cou=1;
            j=1;
            while(x*cou<=n)
            {
                cou++;
                if(str[x*cou]=='0')
                {
                    flag=true;
                    while(flag)
                    {
                        for(p=0;p<ans[j].size();p++)
                        {
                            if(gcd(ans[j][p],x*cou)!=1)
                            {
                                j++;break;
                            }
                        }
                        if(p==ans[j].size())
                            flag=true;
                    }
                    ans[j].push_back(x*cou);
                    str[x*cou]='1';

                    j++;
                }

            }
        }
        // ans[0]+=(n-k);
        if(k!=n)
        {
            for(int i=1;i<=n;i++)
            {
                if(str[i]=='0')
                {
                    ans[0].push_back(i);
                }
            }
        }
        // cout<<
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
        {
            cout<<ans[i].size()<<" ";
            for(auto j:ans[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        // cout<<primes[0]<<primes[1]<<primes[2]<<primes[3]<<primes[4];
        // cout<<ans<<endl;
    }
    



    
 	return 0;
}
 
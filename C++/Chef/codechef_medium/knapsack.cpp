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
// // #define MAX 1000000
// int primes[100009],last[1000009]={},cnt=0;
// vector<int> factors[1000009];
// char str[1000009];
// void pre()
// {
//     // calcualting primes
//     int n=10000;
//     for(int i=2; i*i<=n; i++)
//         if(str[i]==0)
//             for(int j=i; j*i<=n; j++)
//                 str[i*j]=1;
//     for(int i=2; i<=n; i++)
//         if(str[i]==0)primes[cnt]=i,cnt++;
// }
#define pb push_back
int main()
{
    int n;
    // long costs[n];
    // int weights[n];
    int w;
    long c;
    cin>>n;
    long M=0;
    priority_queue<long> ones,Ones,twos,Twos;
    for(int i=0;i<n;i++)
    {
        cin>>w;
        cin>>c;
        if(w==1)
            ones.push(c);
        else twos.push(c);
        M+=w;
    }
    long ans[M+1];
    Ones=ones;
    Twos=twos;
    ans[0]=0;
    long t,o1,o2;
    int ftwo,fone;
    for(long w=2;w<=M;w+=2)
    {
        if(!twos.empty())
            {
                t=twos.top();
                ftwo=1;
            } else ftwo=0;
        if(ones.size()>=2)
            {
                o1=ones.top();
                ones.pop();
                o2=ones.top();
                fone=2;
            }
        else if (!ones.empty())
        {
            o1=ones.top();
            fone=1;
        } else fone=0;

        if(ftwo==0)
        {
            if (fone==2)
            {
                ans[w]=ans[w-2]+o1+o2;
            } else ans[w]=ans[w-2]+o1;
            ones.pop();
        } else if (fone==0)
        {
            ans[w]=ans[w-2]+t;
            twos.pop();
        } else
        {
            if (fone==1)
            {
                if(t>o1)
                {
                    ans[w]=ans[w-2]+t;
                    twos.pop();
                } else {
                    ans[w]=ans[w-2]+o1;
                    ones.pop();
                }
            }else
            {
                if(t>=(o1+o2))
                {
                    ans[w]=ans[w-2]+t;
                    twos.pop();
                    ones.push(o1);
                } else
                {
                    ans[w]=ans[w-2]+o1+o2;
                    ones.pop();
                }
            }
        }
        

    }
    ones=Ones;
    twos=Twos;
    if(!ones.empty())
    {
        ans[1]=ones.top();
        ones.pop();
    }
    for(long w=3;w<=M;w+=2)
    {
        if(!twos.empty())
            {
                t=twos.top();
                ftwo=1;
            } else ftwo=0;
        if(ones.size()>=2)
            {
                o1=ones.top();
                ones.pop();
                o2=ones.top();
                fone=2;
            }
        else if (!ones.empty())
        {
            o1=ones.top();
            fone=1;
        } else fone=0;

        if(ftwo==0)
        {
            if (fone==2)
            {
                ans[w]=ans[w-2]+o1+o2;
            } else ans[w]=ans[w-2]+o1;
            ones.pop();
        } else if (fone==0)
        {
            ans[w]=ans[w-2]+t;
            twos.pop();
        } else
        {
            if (fone==1)
            {
                if(t>o1)
                {
                    ans[w]=ans[w-2]+t;
                    twos.pop();
                } else {
                    ans[w]=ans[w-2]+o1;
                    ones.pop();
                }
            }else
            {
                if(t>=(o1+o2))
                {
                    ans[w]=ans[w-2]+t;
                    twos.pop();
                    ones.push(o1);
                } else
                {
                    ans[w]=ans[w-2]+o1+o2;
                    ones.pop();
                }
            }
        }
        

    }
    for(long w=1;w<=M;w++)
    {
        cout<<ans[w]<<" ";
    }cout<<endl;





    
 	return 0;
}
 
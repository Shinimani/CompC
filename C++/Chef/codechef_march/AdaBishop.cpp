#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/NOKIA
void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
// int parity(int x)
// {
//     int temp=x;
//     temp=temp^(temp>>1);
//     temp=temp^(temp>>2);
//     temp=temp^(temp>>4);
//     temp=temp^(temp>>8);
//     temp=temp^(temp>>16);
//     return temp&1;
    
// }
vc<int> r;
vc<int> c;
void fill()
{

// 1
r.pb(2);
c.pb(2);
// 2
r.pb(1);
c.pb(3);
// 3
r.pb(3);
c.pb(1);
// 4
r.pb(4);
c.pb(2);
// 5
r.pb(1);
c.pb(5);
// 6
r.pb(5);
c.pb(1);
// 7
r.pb(6);
c.pb(2);
// 8
r.pb(1);
c.pb(7);
// 9
r.pb(7);
c.pb(1);
// 10
r.pb(8);
c.pb(2);
// 11
r.pb(2);
c.pb(8);
// 12
r.pb(3);
c.pb(7);
// 13
r.pb(4);
c.pb(8);
// 14
r.pb(8);
c.pb(4);
// 15
r.pb(7);
c.pb(5);
// 16
r.pb(8);
c.pb(6);
// 17
r.pb(6);
c.pb(8);
// 18
r.pb(7);
c.pb(7);
// 19
r.pb(8);
c.pb(8);
for(int i=0;i<r.size();i++)
{
    printf("%d %d\n",r[i],c[i]);
}

}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,r0,c0;
    fastscan(t);
    
    while(t>0)
    {
        t--;
        fastscan(r0);
        fastscan(c0);
        if(r0==1 && c0==1)
        {
            printf("19\n");
            fill();
        }

        
    }
    
    return 0;
}
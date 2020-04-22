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
int parity(int x)
{
    int temp=x;
    temp=temp^(temp>>1);
    temp=temp^(temp>>2);
    temp=temp^(temp>>4);
    temp=temp^(temp>>8);
    temp=temp^(temp>>16);
    return temp&1;
    
}
             
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,n,q,temp,p,one,even;
    fastscan(t);
    // bitset<28> bset;
    // bitset<28> pp;
    // bitset<28> two(1);

    while(t>0)
    {
        t--;
        fastscan(n);
        fastscan(q);
        
        // cin>>n>>q;
        // bitset<28> arr[n];
        int arr[n];
        // bset=0;
        one=0;
        for(int i=0;i<n;i++)
        {
            fastscan(temp);
            temp = parity(temp);
            if (temp==1) one++;
            // arr[i]=temp;
            // cin>>temp;
            // arr[i]=temp;
        }
        for(int i=0;i<q;i++)
        {
            // odd=0;
            fastscan(p);
            p = parity(p);
            if(p==1)
                even = one;
            else even = n-one;
            printf("%d %d\n",even,n-even);

            // cout<<n-odd<<" "<<odd<<"\n";
        }
        
    }
    
    return 0;
}
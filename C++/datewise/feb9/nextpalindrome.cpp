#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/problems/PALIN

using namespace std;

#define PB push_back
#define V vector
#define FORI(i,a,b) for(int i =a;i<b;i++)


long long int ncr(int n, int r)
{
    if (n==r) return 1;
    if (r==0) return 1;
    if (r==1 || r== n-1) return (long long int) n;
    if(r>n-r) r=n-r;
    long long int ans =1;
    for(int i=0;i<r;i++)
    {
        ans = ans*(n-i)/(i+1);
    }
    return ans;
}

int main(){
    
    int t,len,temp;
    string inp,palin;
    
    cin>>t;
    while(t--)
    {
        cin>>inp;
        len = inp.length();
        palin=inp;
        for(int i=len/2;i>0;i--)
        {
            palin[len-i]=palin[i-1];
        }
        if(palin>inp)
            cout<<palin<<"\n";
        else
        {
            if (len%2==0) temp=len/2-1; else temp=len/2;
            for(int i=temp;i>=0;i--)
            {
                if(palin[i]!='9')
                {
                    palin[i]++;
                    break;
                } else
                palin[i]='0';
            }
            for(int i=len/2;i>0;i--)
            {
                palin[len-i]=palin[i-1];
            }   
            if (palin[0]=='0')
            {
                palin[0]='1';
                palin+='1';
            }
            cout<<palin<<"\n";
        }
        
    }

    return 0;
}
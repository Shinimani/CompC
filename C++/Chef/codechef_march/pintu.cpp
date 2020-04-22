#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/NOKIA

             
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,m,n,temp,minp,minidx,types[50],fruits[51],aaya[51];
    cin>>t;
    while(t>0)
    {
        t--;
        cin>>n>>m;
        // int types[n], fruits[m+1];
        for(int i=0;i<=50;i++)
        {
            fruits[i]=0;
            aaya[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            // types[i];
            types[i]=temp;
            aaya[temp]=1;
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            fruits[types[i]] += temp;
        }
        // minidx=0;
        minp=100000;
        for(int i=0;i<=m;i++)
        {
            if(aaya[i]!=0)
            {
                if (fruits[i]<minp)
                {
                    // minidx=i;
                    minp=fruits[i];
                }
            }
        }
        cout<<minp<<"\n";
    }
    
    return 0;
}
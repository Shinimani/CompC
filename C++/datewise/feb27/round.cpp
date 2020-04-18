#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/SEAVOTE
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}


long fact(int n)
{
    long a =1;
    for(int i =1;i<=n;i++)
    {
        a *= (long)i;
    }
    return a;
}

//Prints the array 
void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
} 
#define M 10000

    // int factors[M];
    // for(i=0;i<M;i++)
    // {
    //     factors[i]=i;
    // }
    // for(i=4;i<M;i+=2)
    // {
    //     factors[i]=2;
    // }
    // for(i=3;i<M;i++)
    // {
    //     if(factors[i]==i)
    //     {
    //         for(int j=i*i;j<M;j+=i)
    //         {
    //             factors[j]=i;
    //         }
    //     }
    // }
             
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,p,i;
    long long ans1,ans2;
    // cout<<"hello\n";
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        // fill(begin(arr), end(arr), 0);
        ans1=0;
        ans2=0;
        for(i=0;i<n;i++)
        {
            cin>>p;
            ans1+=p;
            ans2+=p;
            if(p!=0)
                ans2--;
        }
        // cout<<ans<<"\n";
        if(ans1>=100 && ans2<100)
        cout<<"YES\n";else cout<<"NO\n";
              

    }
    
    return 0;
}
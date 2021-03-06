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

// Problem AND 100-point setter's solution

// #include <stdio.h>

// int n,i,j,ai,kk[30]; // kk[i] equals to amount of numbers where the i-th bit is not a zero
// long long ans=0; // answer to the problem

// int main(){
// 	scanf("%d",&n); // size of the sequence
// 	for(i=0;i<n;i++){
// 		scanf("%d",&ai);
// 		for(j=0;j<30;j++)if(ai&(1<<j))++kk[j]; // ai & (1<<j) isn't equal to zero only in case the j-th bit in ai is not a zero
// 	}
// 	for(j=0;j<30;j++)ans+=1LL*kk[j]*(1LL*kk[j]-1LL)*(1LL<<j); // calculate the answer according to the provided formula
// 	printf("%lld\n",ans/2LL);
// 	return 0;
// }

             
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,p,i;
    long long ans;
    // cout<<"hello\n";
    cin>>n;
    int arr[n];
    int counts[30]={0};
    for(int i=0;i<n;i++)
    {
        cin>>t;
        arr[i]=t;
        for(int j=0;j<30;j++)
        {
            if(t&(1<<j))
                counts[j]++;
        }
    }
    ans=0;
    for(int i=0;i<30;i++)
    {
        ans+=(1LL*counts[i]*((1LL*counts[i]-1LL))*(1LL<<i));
    }
    cout<<ans/2LL<<"\n";
        
    return 0;
}
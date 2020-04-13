#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

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
// #define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n,ans;

    cin>>t;
    for(int test=1;test<=t;test++)
    {
        cin>>n;
        // memset(arr,-1,sizeof(arr));

        for(int i=1;i<=n;i++)
        {
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;


    }



    
 	return 0;
}
 
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/NUMFACT
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
    // cout<<"hello\n";
    cin>>t;
    
    map<int,int> fin;
    int tempfactor;
    long long ans;
    while(t--)
    {
        cin>>n;
        map<int,int> vec[n];
        // fill(begin(arr), end(arr), 0);
        for(i=0;i<n;i++)
        {
            cin>>p;
            map<int,int> hello;
            hello[2]=0;
            while(p%2==0)
            {
                hello[2]++;
                p/=2;
            }
            for(tempfactor=3;tempfactor<=sqrt(p);tempfactor+=2)
            {
                while(p%tempfactor==0)
                {
                    if (hello.count(tempfactor)==0)
                        hello[tempfactor]=1;
                    else hello[tempfactor]++;
                    p/=tempfactor;
                }
            }
            if (p > 2) 
            hello[p]++;
            
            vec[i]=hello;
        }
        fin.clear();
        for(i=0;i<n;i++)
        {
            for(auto& x:vec[i])
            {
                if(fin.count(x.first)==0)
                    fin[x.first]=x.second;
                else fin[x.first]+=x.second;
            }
        }
        ans=1;
        for(auto& x:fin)
        {
            ans*=(x.second+1);
        }
        cout<<ans<<"\n";

        

    }
    
    return 0;
}
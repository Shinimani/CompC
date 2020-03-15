#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/ONEKING

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

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
bool customCompare(pair<int,int> l1, pair<int,int> l2)
{
    return l1.second<l2.second;
}
int main() {
    int t,n,l,r,ans,flag;
    pair<int,int> p (0,0);
    fastscan(t);
    while(t>0)
    {
        t--;
        fastscan(n);
        pair<int,int> arr[n];
        for(int i=0;i<n;i++)
        {
            fastscan(l);
            fastscan(r);
            pair<int,int> p (l,r);
            arr[i] = p;
        }
        sort(arr,arr+n,customCompare);
        ans=1;
        flag=arr[0].second;
        for(int i=0;i<n;i++)
        {
            
            if (arr[i].first>flag)
            {
                ans++;
                flag=arr[i].second;
            }
            
        }
        printf("%d\n",ans);

    }
    return 0;
}
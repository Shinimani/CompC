#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/MIXTURES

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

long long dp[1000][1000];

int getSum(int* arr, int i, int j) {
    int sum = 0;
    for(int k=i; k<=j; k++) {
        sum+=arr[k];
        sum %= 100;
    }
    return sum;
}

long long mix(int* arr, int l, int r) {
    if(l >= r)
        return 0;
    
    if(dp[l][r] != -1) return dp[l][r];
    
    dp[l][r] = INT_MAX;
    for(int i=l; i<r; i++) {
        dp[l][r] = min(dp[l][r], mix(arr, l, i) + mix(arr, i+1, r) + getSum(arr, l, i) * getSum(arr, i+1, r));
    }
    return dp[l][r];
}

int main() {
    int n;
    while(cin>>n) {
        int* arr = new int[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = -1;
            }
        }
        cout<<mix(arr, 0, n-1)<<"\n";
    }
}
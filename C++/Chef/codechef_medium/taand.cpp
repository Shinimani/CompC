#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
#define sc(n) fastscan(n)
#define fr(i,a,b) for(int i=a;i<b;i++)
// https://www.codechef.com/problems/TAAND

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
#define maxn 300111

int n, a[maxn], res;

int calc(int pattern) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if ((pattern & a[i]) == pattern) cnt++;
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    res = 0;

    for (int bit = 30; bit >= 0; bit--) {
        if (calc(res | (1 << bit)) >= 2)
            res |= (1 << bit);
    }

    cout << res << endl;
}
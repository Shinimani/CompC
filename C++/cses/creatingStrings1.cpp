#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
// #define pii         pair<ll int,ll int>
// #define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define hell1        1000000006
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define repnitr(itr,m) for(auto itr=m.begin();itr!=m.end();itr++)
#define repnrevitr(itr,m) for(auto itr=m.rbegin();itr!=m.rend();itr++)
typedef vector<int> vi ;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<int,vector<int>,greater<int>> pqig;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqlg;

int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
// ll gcd(ll u,ll v)
// {
// 	if(v==0)
// 	return u;
	
// 	else
// 	return gcd(v,u%v);
// }

// // // #define MAX 1000000
// int primes[100009],cnt=0;
// // vector<int> factors[1000009];
// char str[1000009];
// void pre()
// {
//     // calcualting primes
//     int n=1000000;
//     for(int i=2; i*i<=n; i++)
//         if(str[i]==0)
//             for(int j=i; j*i<=n; j++)
//                 str[i*j]=1;
//     for(int i=2; i<=n; i++)
//         if(str[i]==0)primes[cnt]=i,cnt++;
// }
ll fact(ll n); 
  
ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  
// Returns factorial of n 
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
int compare(const void* a, const void* b) 
{ 
    return (*(char*)a - *(char*)b); 
} 
  
// A utility function two swap two characters 
// a and b 
void swap(char* a, char* b) 
{ 
    char t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// This function finds the index of the 
// smallest character which is greater 
// than 'first' and is present in str[l..h] 
int findCeil(char str[], char first, int l, int h) 
{ 
    // initialize index of ceiling element 
    int ceilIndex = l; 
  
    // Now iterate through rest of the 
    // elements and find the smallest 
    // character greater than 'first' 
    for (int i = l + 1; i <= h; i++) 
        if (str[i] > first && str[i] < str[ceilIndex]) 
            ceilIndex = i; 
  
    return ceilIndex; 
} 
  
// Print all permutations of str in sorted order 
void sortedPermutations(char str[]) 
{ 
    // Get size of string 
    int size = strlen(str); 
  
    // Sort the string in increasing order 
    qsort(str, size, sizeof(str[0]), compare); 
  
    // Print permutations one by one 
    bool isFinished = false; 
    while (!isFinished) { 
  
        // print this permutation 
        static int x = 1; 
        printf("%s \n", str);
        x++; 
  
        // Find the rightmost character 
        // which is smaller than its next 
        // character. Let us call it 'first 
        // char' 
        int i; 
        for (i = size - 2; i >= 0; --i) 
            if (str[i] < str[i + 1]) 
                break; 
  
        // If there is no such character, all 
        // are sorted in decreasing order, 
        // means we just printed the last 
        // permutation and we are done. 
        if (i == -1) 
            isFinished = true; 
        else { 
  
            // Find the ceil of 'first char' 
            // in right of first character. 
            // Ceil of a character is the 
            // smallest character greater 
            // than it 
            int ceilIndex = findCeil(str, 
                     str[i], i + 1, size - 1); 
  
            // Swap first and second characters 
            swap(&str[i], &str[ceilIndex]); 
  
            // Sort the string on right of 'first char' 
            qsort(str + i + 1, size - i - 1, 
                  sizeof(str[0]), compare); 
        } 
    } 
} 
  
int main()
{
    // io

    string s;
    cin>>s;
    ll n=s.length();
    ll ans=1;
    sort(all(s));
    map<char,ll> m;
    for(char c:s)
    {
        m[c]++;
    }
    repnitr(itr,m)
    {
        // cout<<itr->first<<" "<<n<<"C"<<itr->second<<endl;
        ans*=nCr(n,itr->second);
        // cout<<nCr(n,itr->second)<<endl;
        n-=itr->second;
    }
    cout<<ans<<endl;
    char char_array[n + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(char_array, s.c_str()); 
    sortedPermutations(char_array);



 	return 0;
}
 
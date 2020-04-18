#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://cses.fi/problemset/task/1622
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}


void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
    {
        cout<<a<<endl;
        // ;
    }     
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            for(int j=l+1;j<=i;j++)
            {
                swap(a[l],a[j]);
            }
            // swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            for(int j=i;j>l;j--)
            {
                swap(a[l],a[j]);
            }
            // swap(a[l], a[i]);  
        }  
    }  
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n,a,b;
    int n;
    string s;
    // int count =0;
    cin>>s;
    sort(s.begin(),s.end());
    n=s.length();
    set<char> m;
    map<char,int> mp;
    int temp;
    for(int i=0;i<n;i++)
    {
        if(m.count(s[i]) ==1) 
        {
            temp = mp.lower_bound(s[i])->second;
            mp.erase(s[i]);
            mp.insert(pair<char,int>(s[i],temp+1));
        } else {
            m.insert(s[i]);
            mp.insert(pair<char,int>(s[i],1));
        }
    }
    long cou = fact(n);
    // vc<int> v;
    map<char, int>::iterator itr; 
    
    for(itr = mp.begin();itr!=mp.end();++itr)
    {
        cou /= itr->second;;
    }
    // for(char 
    cout<<cou<<"\n";

    permute(s,0,n-1);
    
    return 0;
}
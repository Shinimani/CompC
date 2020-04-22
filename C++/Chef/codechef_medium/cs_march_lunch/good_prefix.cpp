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
int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}


int main() {
    int t,k,x,ans,n;
    int a = (int) 'a';
    int arr[26];
    int c;
    string s;
    // int a1,a2,b1,b2;
    sc(t);
	while (t--) {
        cin>>s>>k>>x;
		// sc(k);
        // sc(x);
        ans=0;
        n = s.length();
        for(int i=0;i<26;i++)
        {
            arr[i]=0;
        }
        for(int i=0;i<n && k>=0;i++)
        {
            c = (int)s[i]-a;
            // cout<<c<<endl;
            arr[c]++;
            if(arr[c]>x && k==0)
                break;
            else if (arr[c]>x)
            {
                arr[c]--;
                k--;
            } else ans++;
        }
        printf("%d\n",ans);
    }
    // k = (int) 'a';
    // x = (int) 'c';
    // cout<<"hello"+x<<endl;
    // printf("%d",x-k);
	// cout << endl;
}
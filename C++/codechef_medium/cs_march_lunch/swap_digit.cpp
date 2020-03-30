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
    int t,a,b,ans;
    int a1,a2,b1,b2;
    sc(t);
	while (t--) {
		sc(a);
        sc(b);
        a2=a%10;
        b2=b%10;
        a1=a-a2;
        a1/=10;
        b1=b-b2;
        b1/=10;
        if(a1==0 && b1==0)
        {
            ans=a+b;
        } else if (a1==0)
        {
            ans = max(a+b,10*a2 + b1 + b2);
        } else if (b1==0)
        {
            ans = max(a+b,10*b2 + a1 + a2);
        } else ans = max((a+b),max(10*(a2+a1) + (b2+b1),10*(b2+b1) + (a2+a1)));
        // cout<<ans<<endl;
        printf("%d\n",ans);
        
        
    }

	// cout << endl;
}
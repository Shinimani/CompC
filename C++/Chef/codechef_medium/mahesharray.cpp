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
 
int main()
{	
	ll t,n,i,j,x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    ll b=pow(2,n),a[b-1];
	    multiset<ll>ms,ms1;
	    multiset<ll>::iterator it;
	    
	    for(i=0;i<b;i++)
	    { cin>>x;
	      ms.insert(x);
	    }
	    i=0;
	    ms.erase(ms.begin());
	    a[i++]=*(ms.begin());
	    ms.erase(ms.begin());
	    ms1.insert(a[0]);
	    if(ms1.size()==n)
	    cout<<a[0]<<"\n";
	    else
	    {
	        a[i++]=*ms.begin();
	        ms1.insert(a[1]);
	        ms.erase(ms.begin());
	        
	        if(ms1.size()==n)
	        cout<<a[0]<<" "<<a[1]<<"\n";
	        else
	        {
	            x=a[i-1];
	            ll y;
	            while(ms1.size()!=n)
	            {
	                y=i-1;
	                for(j=0;j<y;j++)
	                {
	                    a[i++]=x+a[j];
	                    ms.erase(ms.lower_bound(x+a[j]));
	                }
	                
	                x=*ms.begin();
	                a[i++]=x;
	                ms1.insert(x);
	                ms.erase(ms.begin());
	               }
	               
	               for(it=ms1.begin();it!=ms1.end();it++)
	               cout<<*it<<" ";
	               cout<<"\n";
	             }
	        }
	   }
	
	return 0;
}
 
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
bool checker(int a, int b, int c)
{
       //boundary cases
    if(c>a && c>b)
	{
        return false;
    }
    //if c is multiple of HCF of a and b, then possible
    if(c%gcd(a,b)==0)
	{
        return true;
    }
    
    //if c is not multiple of HCF of a and b, then not possible
    return false;
}
/*
calculating steps
Method:  Start filling A and pouring it in B,
in case B is full in between empty it, and
again pour from A, and repeat the process.
*/
int steps(int A, int B, int c)
{
    int temp=0;
    int a=0,b=0;
    int steps=0;
    
    while(a!=c && b!=c)
    {
        //if a empty, fill a
        if(a==0) 
        {
            a=A;
            steps++;
        }
        else if(b==B)
        {
            b=0;
            steps++;
        }
        else
        {
            if(B-b<a)
            {
                temp = B-b;
            } else temp=a;
            a-=temp;
            b+=temp;
            steps++;
        }
    }
    return steps;
}
int main()
{
    int t,a,b,c,s1,s2;
    sc(t);
    while(t--)
    {
        sc(a);
        sc(b);
        sc(c);
        if (checker(a,b,c))
        {
            s1=steps(a,b,c);
            s2=steps(b,a,c);
            printf("%d\n",min(s1,s2));
        }
        else printf("-1\n");
        // if (c==a|| c==b ) printf("1\n"); else if(c== abs(a-b)) printf("2\n"); else printf("-1\n");

    }
	return 0;
}
 
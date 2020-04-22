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
void buildLps(int lps[], string pat, int m)
{
    int len=0;
    int i=1;
    lps[0]=0;
    while(i<m)
    {
        if (pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        } else
        {
            if(len!=0)
            {
                len=lps[i-1];
            } else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
char A[2000005],B[2000005];
int p[2000005];
int best,ans;
 
void KMP(int x,int y,char *X,char *Y)
{
   int i,k=0,q;
 
   p[1]=0;
 
   for(q=2;q<=y;q++)
   {
      while(k>0 && Y[k]!=Y[q-1]) k=p[k];
      if(Y[k]==Y[q-1]) ++k;
      p[q]=k;
   }
 
 
   for(q=i=0;i<x;i++)
   {
      while(q>0 && Y[q]!=X[i])
         q=p[q];
      if(Y[q]==X[i])
         q++;
 
      if(q>best)
      {
         best=q;
         ans=i-q+1;
      }
     //printf("%d %d %d\n",i,q,i-q+1);
   }
}
 
int main()
{
	int m,i,j,k,tests,cs=0,t=0,n;
 
   scanf("%d%s%s",&n,A,B);
 
   int a=strlen(A),b=strlen(B);
 
   assert(n>=1 && n<=1000000 && a==b && n==a);
 
   for(i=0;i<n;i++) B[b++]=B[i];
   B[b]='\0';
   //printf("%s %s\n",B,A);
 
   best=ans=0;
   KMP(b,a,B,A);
   printf("%d\n",ans);
 
 
	return 0;
}
 
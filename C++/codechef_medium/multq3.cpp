#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
#define sc(n) fastscan(n)
#define fr(i,a,b) for(int i=a;i<b;i++)
// https://www.codechef.com/problems/TAAND
class trip
{
    public: 
    int zer,on,tw;
    
    trip()
    {
        zer=0;
        on=0;
        tw=0;
    }
    int sum()
    {
        return zer+on+tw;
    }
    void spin()
    {
        int temp = zer;
        zer=on;
        on=tw;
        tw=temp;
    }
    void spin(int x)
    {
        int temp = x%3;
        if (temp==1)
            spin();
        if (temp==2)
        {
            spin();
            spin();
        }
    }
    void adder(trip a, trip b)
    {
        zer=a.zer+b.zer;
        on=a.on+b.on;
        tw=a.tw+b.tw;
    }
  
};
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
int get0util(int si, int sb, int se, int b, int e, trip st[], int lz[])
{
    // if (lz[si]!=0)
    //     {
    //         st[si].spin(lz[si]);
    //         if(sb!=se)
    //         {
    //             lz[2*si + 1]+=lz[si];
    //             lz[2*si + 2]+=lz[si];
                
    //         }
    //         lz[si]=0;
    //     }
    if (sb>e || se<b)
        return 0;
    // if(lz[si].sum()!=0)
    // {

    // }
    if (sb>=b && se<=e)
        {
            return st[si].zer;
        }
        
    int mid = (sb + se)/2;
    return get0util(2*si+1,sb,mid,b,e,st,lz) + get0util(2*si+2,mid+1,se,b,e,st,lz);
}
int get0(int n,int b,int e,trip st[], int lz[])
{
    return get0util(0,0,n-1,b,e,st,lz);
}
void updateutil(int si, int sb, int se, int b, int e, trip st[], int lz[])
{
    // if (lz[si]!=0)
    //     {
    //         st[si].spin(lz[si]);
    //         if(sb!=se)
    //         {
    //             lz[2*si + 1]+=lz[si];
    //             lz[2*si + 2]+=lz[si];
                
    //         }
    //         lz[si]=0;
    //     }
    if (sb>e || se<b)
        return;
    
    if (sb>=b && se<=e)
        {
            st[si].spin();
            if(sb!=se)
            {
                int mid = (sb + se)/2;
                updateutil(2*si+1,sb,mid,b,e,st,lz);
                updateutil(2*si+2,mid+1,se,b,e,st,lz);
                return;
            } else return;
        }
    int mid = (sb + se)/2;
    updateutil(2*si+1,sb,mid,b,e,st,lz);
    updateutil(2*si+2,mid+1,se,b,e,st,lz);
    st[si].adder(st[2*si+1],st[2*si+2]);
    
    // return get0util(2*si+1,sb,mid,b,e,st,lz) + get0util(2*si+2,mid+1,se,b,e,st,lz);
}

void update(int n,int b,int e,trip st[], int lz[])
{
    updateutil(0,0,n-1,b,e,st,lz);
}


// A recursive function that constructs Segment Tree for 
//  array[ss..se]. si is index of current node in segment 
// tree st. 
void constructSTUtil(int ss, int se, int si, trip st[]) 
{ 
    // out of range as ss can never be greater than se 
    if (ss > se) 
        return ; 
  
    // If there is one element in array, store it in 
    // current node of segment tree and return 
    if (ss == se) 
    { 
        trip temp;
        temp.zer=1;
        st[si] = temp;
        return; 
    } 
    
    // If there are more than one elements, then recur 
    // for left and right subtrees and store the sum 
    // of values in this node 
    int mid = (ss + se)/2; 
    constructSTUtil(ss, mid, si*2+1,st); 
    constructSTUtil(mid+1, se, si*2+2,st); 
    st[si].adder(st[si*2 + 1],st[si*2 + 2]);

} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree and 
   calls constructSTUtil() to fill the allocated memory */
void constructST(int n, trip st[]) 
{ 
    // Fill the allocated memory st 
    constructSTUtil(0, n-1, 0, st); 
} 
void printSTree(int n,trip st[])
{
    for(int i=0;i<(2*n-1);i++)
    {
        printf("%d %d %d - ",st[i].zer,st[i].on,st[i].tw);
    }
    printf("\n");
}
void printLZTree(int n,int lz[])
{
    for(int i=0;i<(2*n-1);i++)
    {
        printf("%d  - ",lz[i]);
    }
    printf("\n");
}
  
int main()
{
    int n,q;
    sc(n);
    sc(q);
    int type,a,b;
    trip st[2*n-1];
    int lz[1] ={0};
    // for(int i=0;i<(2*n-1);i++)
    // lz[i]=0;
    constructST(n,st);
    // printSTree(n,st);
    // printLZTree(n,lz);
    while(q--)
    {
        sc(type);
        sc(a);
        sc(b);
        if(type==1)
        {
            printf("%d\n",get0(n,a,b,st,lz));
            // printSTree(n,st);
            // printLZTree(n,lz);
        } else
        {
            update(n,a,b,st,lz);
            // printSTree(n,st);
            // printLZTree(n,lz);
        }
    }


    
 	return 0;
}
 
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/NOKIA
void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
 
int leftChild(int i, int n)
{
    double d = n;
    d /= (i+1);
    d = log2(d);
    d = ceil(d);
    int ans = 1<<(int)(d+0.01);
    ans = ans*(i+1) -1;
    return ans;
}
int rightChild(int i, int n)
{
    double d = 2*n+1;
    d /= (i+2);
    d = log2(d);
    d = floor(d);
    int ans = 1<<(int)(d+0.01);
    ans = ans*(i+2) -2;
    return ans;
}
bool checklr(int l, int r, int y, int x, int arr[],int n)
{
    if((x-(n-1)>=l)&&((x+1-(n-1))<=r))
    {
        // cout<<"inside";
        return ((arr[x-(n-1)]<=y && arr[x+1-(n-1)]>=y)||(arr[x-(n-1)]>=y && arr[x+1-(n-1)]<=y));
    } else return false;
}
int recur(int l, int r, int y, int x, int arr[],int n, int minst[], int maxst[],int count)
{
    // cout<<count<<endl;
    int xl = leftChild(x,n);
    int xr = rightChild(x,n); 
    if (x==xl) 
    {
        // cout<<"x is"<<x<<" "<<arr[x-(n-1)]<<" "<<arr[x+1-(n-1)]<<" "<<endl;
        if (checklr(l,r,y,x,arr,n))
        {
            // cout<<"x is"<<x<<" plus1"<<endl;
            return 1;
        } else return 0;        
    } else if (y<minst[x] || y>maxst[x])
    {

        // cout<<x<<"  "<<minst[x]<<" "<<maxst[x]<<" "<<"here"<<endl;
        if (checklr(l,r,y,xr,arr,n))
        {
            // cout<<"x is"<<x<<" plus1"<<endl;
            return 1;
        } else return 0;
    } else
    {
        return recur(l,r,y,2*x + 1, arr,n,minst,maxst,count+1) + recur(l,r,y,2*x + 2, arr,n,minst,maxst,count+1);
    }
}
// A utility function to get the middle index from corner indexes.  
int getMid(int s, int e) { return s + (e -s)/2; }  
  
// A recursive function that constructs Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
int constructSTUtil(int arr[], int ss, int se, int *st, int si)  
{  
    // If there is one element in array, store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements, then recur for left and  
    // right subtrees and store the sum of values in this node  
    int mid = getMid(ss, se);  
    st[si] = min(constructSTUtil(arr, ss, mid, st, si*2+1),constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree from given array. This function  
allocates memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *constructST(int arr[], int n)  
{  
    // Allocate memory for the segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    //Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    // Allocate memory  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}  
int maxconstructSTUtil(int arr[], int ss, int se, int *st, int si)  
{  
    // If there is one element in array, store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements, then recur for left and  
    // right subtrees and store the sum of values in this node  
    int mid = getMid(ss, se);  
    st[si] = max(maxconstructSTUtil(arr, ss, mid, st, si*2+1),maxconstructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree from given array. This function  
allocates memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *maxconstructST(int arr[], int n)  
{  
    // Allocate memory for the segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    //Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    // Allocate memory  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    maxconstructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}  


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,n,q,h,l,r,y,ans;
    fastscan(t);
    
    while(t>0)
    {
        t--;
        fastscan(n);
        fastscan(q);
        // Allocate memory  
        int *arr = new int[n];  
        for(int i=0;i<n;i++)
        {
            fastscan(arr[i]);
        }
        // Build segment tree from given array  
        int *stmin = constructST(arr, n);  
        int *stmax = maxconstructST(arr, n);  
        
        for(int i=0;i<q;i++)
        {
            fastscan(l);
            fastscan(r);
            fastscan(y);

            ans = recur(l-1,r-1,y,0,arr,n,stmin,stmax,0);
            printf("%d\n",ans);

        }
        // for(int i=0;i<2*n-1;i++)
        // {
        //     printf("%d\n",stmax[i]);
        // }



        
    }
    
    return 0;
}
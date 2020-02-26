#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://www.codechef.com/problems/FLIPCOIN
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
#define mx 100024
#define scnf(n) scanf("%d",&n)
#define scnf2(n,m) scanf("%d%d",&n,&m)

// using namespace std;
int tree[mx*4];
int lazy[mx*4];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=0;
        return;
    }
    int mid=(b+e)/2;
    init(node*2,b,mid);
    init(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];

}

void update(int node, int stree, int etree, int i, int j)
{
    if (lazy[node]!=0)
    {
        tree[node] = etree-stree+1-tree[node];
        if(stree!=etree)
        {
            lazy[2*node]  = 1- lazy[2*node];
            lazy[2*node + 1] = 1 - lazy[2*node +1];

        }
        lazy[node]=0;

    }
    if(etree<i || stree>j)
    {
        return;
    }
    if (stree>=i && etree<=j)
    {
        tree[node] = etree-stree+1-tree[node];
        if(stree!=etree)
        {
            lazy[2*node]  = 1- lazy[2*node];
            lazy[2*node + 1] = 1 - lazy[2*node +1];

        }
        return;
    }
    int mid = (stree+etree)/2;
    update(node*2,stree,mid,i,j);
    update(node*2+1,mid+1,etree,i,j);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int node,int b,int e,int i,int j)
{
        if(b>j||e<i)
        return 0;
    if(lazy[node]!=0)
    {
        tree[node]=(e-b+1)-tree[node];
        if(b!=e)
        {
            lazy[node*2]=1-lazy[node*2];
            lazy[node*2+1]=1-lazy[node*2+1];
        }
        lazy[node]=0;
    }
    if(b>=i&&e<=j)
        return tree[node];
    int mid=(b+e)/2;
    int q1=query(node*2,b,mid,i,j);
    int q2=query(node*2+1,mid+1,e,i,j);
    return q1+q2;
}

#define M 100000
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n;
    scnf(n);
    init(1,1,n);
    int q;
    scnf(q);
    while(q--)
    {
        int c,i,j;
        scanf("%d%d%d",&c,&i,&j);
        if(c==0)
        {
            update(1,1,n,i+1,j+1);
        }
        else
        {
            int ans=query(1,1,n,i+1,j+1);
            printf("%d\n",ans);
        }

    }
    
    return 0;
}
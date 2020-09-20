#include<bits/stdc++.h>
using namespace std;

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

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int toSumTree(struct TreeNode* Node)  
{  
    // Base case  
    if(Node == NULL)  
    return 0;  
  
    // Store the old value  
    int old_val = Node->data;  
  
    // Recursively call for left and 
    // right subtrees and store the sum as  
    // new value of this node  
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);  
  
    // Return the sum of values of nodes 
    // in left and right subtrees and  
    // old_value of this node  
    return Node->data + old_val;  
} 


void SumTree(struct TreeNode* root)
{
    int home = root->data;
    int k = toSumTree(root);
    root->data = k-home;
    return;
}
TreeNode* newNode(int data)  
{  
    TreeNode *temp = new TreeNode;  
    temp->data = data;  
    temp->left = NULL;  
    temp->right = NULL;  
    return temp;  
}  

int maxGold(int** mine,int m,int n)
{
    int dp[m][n];
    // memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        dp[i][n-1]=mine[i][n-1];
    }
    // dp[m-1][n-1]=mine[m-1][n-1];
    
    for(int j=n-2;j>=0;j--)
    {
        for(int i=0;i<m;i++)
        {
            int a1 = 0,a2=0,a3=0;
            if(i>0)a1=dp[i-1][j+1];
            a2=dp[i][j+1];
            if(i+1<m)a3=dp[i+1][j+1];
            int a4 = max(a1,max(a2,a3));
            dp[i][j]=a4+mine[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans=max(ans,dp[i][0]);
    }
    if(ans==0)return -1;
    else return ans;
}


int main()
{
    // io

    int t,n;
    // int a,b,c;
    int temp,ans;
    int p,q;
    int x,y,z;
    
    int** a = new int*[3];
    for(int i = 0; i < 3; ++i)
        a[i] = new int[6];
    a[0][0]=8;
    a[0][1]=3;
    a[0][2]=1;
    a[0][3]=8;
    a[0][4]=9;
    a[0][5]=10;
    a[1][0]=7;
    a[1][1]=4;
    a[1][2]=1;
    a[1][3]=1;
    a[1][4]=2;
    a[1][5]=3;
    a[2][0]=6;
    a[2][1]=6;
    a[2][2]=3;
    a[2][3]=2;
    a[2][4]=3;
    a[2][5]=4;
    // a[3][2]=1;
    // a[3][3]=2;
    cout<<maxGold(a,3,6);

    
    


    // TreeNode *root = NULL; 
    // root = newNode(10);  
    // root->left = newNode(-2);  
    // root->right = newNode(6);  
    // root->left->left = newNode(8);  
    // root->left->right = newNode(-4);  
    // root->right->left = newNode(7);  
    // root->right->right = newNode(5); 
    // SumTree(root); 
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    // cout<<root->left->left->data<<endl;
    // cout<<root->left->right->data<<endl;
    // cout<<root->right->left->data<<endl;
    // cout<<root->right->right->data<<endl;
    
      
    // ll t,n;
    // ll a,b,c;
    // ll temp,ans;
    // ll p,q;
    // ll x,y,z;
    vector<string> v;
    
    // v.pb("aaefcs");
    // v.pb("aae");
    // v.pb("aac");
    // v.pb("aadfg");
    // cout<<GoodOrBad(4,v);
    
    // string s;
    // cin>>t;
    
    // while(t--)
    // {
    //     cin>>n;
    //     cout<<n*10<<" "<<n*2<<endl;
    //     // cout<<ans<<"\n";
        
    // }
    
 	return 0;
}
 
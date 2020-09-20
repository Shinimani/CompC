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

int countPossibleExits(int n,int b,vector<int> c)
{
    int m = c.size();
    unordered_set<int> prev,nxt;
    prev.insert(b);
    for(int i=0;i<m;i++)
    {
        nxt.clear();
        for(int k:prev)
        {
            if(k - c[i] >0)nxt.insert(k-c[i]);
            if(k + c[i] <=n)nxt.insert(k+c[i]);
        }
        prev = nxt;
    }
    if(nxt.empty()) return -1;
    return nxt.size();
}
#define pb push_back

int triplets(int n,int k)
{
    int ans=1;
    int temp;
    for(int i=1;i<=n;i++)
    {
        temp = 1 + 6*min(i,k) + 3*(min(i,k))*(max(0,min(i,k)-1));
        ans+=temp;
    }
    return ans;

}
// 
bool vis[10][10];
int pathlen[10][10];
// memset
set<int> prime;

set<int> squarecube;

int helper(int x,int y)
{
    if(x<0 || y<0 || x>10 || y>10)return 0;
    if(pathlen[x][y] != -1) return pathlen[x][y];
    if(vis[x][y])return INT_MAX;
    vis[x][y]=true;
    int ans = INT_MAX;
    if(prime.find(x+y)!=prime.end())
    {
        if(x==10)return 1;
        if(!vis[x+1][y])
            ans = min(ans,1+ helper(x+1,y));
    }else if ((x+y)!=1 && (x+y)!=0)
    {
        if(x==0)return 1;
        if(!vis[x-1][y])
            ans = min(ans,1+ helper(x-1,y));
    }else
    {
        if(y==0)return 1;
        if(!vis[x][y-1])
            ans = min(ans,1+helper(x,y-1));
    }
    if(squarecube.find(x+y) != squarecube.end())
    {
        if(y==10)return 1;
        if(!vis[x][y+1])ans = min(ans,1+helper(x,y+1));
    }
    pathlen[x][y]=ans;
    return ans;
}
int getpath(string initial)
{
    memset(pathlen,-1,sizeof(pathlen));
    memset(vis,false,sizeof(vis));

prime.insert(2);
prime.insert(3);
prime.insert(5);
prime.insert(7);
prime.insert(11);
prime.insert(13);
prime.insert(17);
prime.insert(19);

squarecube.insert(4);
squarecube.insert(8);
squarecube.insert(9);
squarecube.insert(16);
    vector<int> nums;
    stringstream check1(initial); 
    string intermediate; 
    while(getline(check1, intermediate, ',')) 
    { 
        nums.push_back(stoi(intermediate)); 
    } 

    int posx = nums[0];
    int posy = nums[1];

    // int ans = helper(posx,posy);
    int ans=0;
    return ans;
}
int main()
{   

    int n=5,b=1;
    vector<int> c;
    c.pb(2);
    c.pb(1);
 	c.pb(2);
    c.pb(1);
    prime.insert(2);
prime.insert(3);
prime.insert(5);
prime.insert(7);
prime.insert(11);
prime.insert(13);
prime.insert(17);
prime.insert(19);

squarecube.insert(4);
squarecube.insert(8);
squarecube.insert(9);
squarecube.insert(16);
    // cout<<countPossibleExits(n,b,c)<<endl;
    cout<<"helloss";// cout<<triplets(2,6)<<endl;
    
    // getpath("");
    cout<<"hello";
    cout<<helper(4,5)<<endl;
    return 0;
}
 
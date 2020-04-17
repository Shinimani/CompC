#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

// day 1
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>ans;
    int n=nums.size();
    int prod=1;
    rep(i,n)
    {
        ans.push_back(prod);
        prod*=nums[i];
    }    
    prod=1;
    rep(i,n)
    {
        ans[n-1-i]*=prod;
        prod*=nums[n-i-1];
    }
    return ans;
}

// day 2
bool checkValidString(string s) {
    vector<char> v;
    int l=0;
    int m=0;
    int n=s.length();
    bool ans=true;
    // int j;
    vector<char>::iterator j;
    rep(i,n)
    {
        if(s[i]=='(')
        {
            v.push_back('(');
            l++;
        }
        else if (s[i]=='*')
        {
            v.push_back('*');
            m++;
        }
        else
        {
            if (l>0)
            {
                l--;
                // j=v.size()-1;
                j=v.end();
                j--;
                while(*j!='(')j--;
                v.erase(j);
            }
            else if (m>0)
            {
                m--;
                v.pop_back();
            }
            else
            {
                ans=false;
                break;
            }
        }
    }  
    if(!ans) return ans;
    if(l>0)
    {
        if(l>m)
           return false;
        else
        {
            l=0;
            for(auto c:v)
            {
                if(c=='(')l++;
                else if(l>0)l--;
            }
            if(l>0) return false; else return true;
        }
    }else return ans;
}

// day 3
void helperIsland(int i,int j, vector<vector<char>>& g)
{
    if(g[i][j]=='0') return;
    g[i][j]='0';
    int n=g.size();
    int m=g[0].size();
    int xd[4] = {1,-1,0,0};
    int yd[4] = {0,0,1,-1};
    rep(k,4)
    {
        if(!(i+yd[k]==-1 || i+yd[k]==n || j+xd[k]==-1 || j+xd[k]==m))
        {
            helperIsland(i+yd[k],j+xd[k],g);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty())return 0;
    int n = grid.size();
    int m = grid[0].size();
    int ans=0;
    rep(i,n)
    {
        rep(j,m)
        {
            if(grid[i][j]=='1')
            {
                ans++;
                helperIsland(i,j,grid);
            }
        }
    }
    return ans;
}


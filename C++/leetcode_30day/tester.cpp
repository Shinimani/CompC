#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
int count(ListNode* node,int curr)
{
    ListNode temp = *node;
    if((*node).next==NULL)
        return curr;
    return((*node).next,curr+1);
}
ListNode* nthNode(ListNode* node, int curr, int target)
{
    if(curr==target)
        return node;
    return nthNode(node->next,curr+1,target);
}
ListNode* middleNode(ListNode* head) {
        int n=count(head,1);
        if(n==1) return head;
        return nthNode(head,0,n/2);
    }


int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> p;
    for(int i=0;i<stones.size();i++)
    {
        p.push(stones[i]);
    }   
    int a;
    int b; 
    while(p.size()>1)
    {
        a=p.top();
        p.pop();
        b=p.top();
        p.pop();
        if(a==b)
        continue;
        else
        {
            a=a-b;
            p.push(a);
        }
        
    }
    if(p.empty())
    return 0;
    else return p.top();
}

int findMaxLength(vector<int>& nums) {
    vector<int> v;
    int sum=0;
    int max0=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        sum--;
        else sum++;
        v.push_back(sum);
        if(sum==0)max0=i;
    }
    max0++;
    map<int,vector<int>> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]].push_back(i);
    }
    vector<int> temp;
    map<int,vector<int>>::iterator itr;
    // int 
    for(itr=m.begin();itr!=m.end();itr++)
    {
        temp=itr->second;
        if(temp.size()==1)continue;
        max0=max(max0,temp[temp.size()-1]-temp[0]);
    }
    return max0;
}

    string stringShift(string s, vector<vector<int>>& shift) {
        
    }

int main()
{
 
//  [2,7,4,1,8,1]
vector<int> a;
a.push_back(2);
a.push_back(7);   
a.push_back(4);   
a.push_back(1);   
a.push_back(8);   
a.push_back(1);

int ans = lastStoneWeight(a);
cout<<ans<<endl;


    
    return 0;
}
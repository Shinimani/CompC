#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

bool backspaceCompare(string S, string T) {
    int ns = S.length();
    int nt = T.length();
    int j=0;
    for(int i=0;i<ns;i++)
    {
        if(S[j]!='#')j++;
        else{
            if(j!=0)
                {
                    S.erase(S.begin()+j-1);
                    S.erase(S.begin()+j-1);
                    j--;    
                }
            else
                {
                    S.erase(S.begin()+j);
                }
        }
    }
    j=0;
 
    for(int i=0;i<nt;i++)
    {
        if(T[j]!='#')j++;
        else{
            if(j!=0)
                {
                    T.erase(T.begin()+j-1);
                    T.erase(T.begin()+j-1);
                    j--;    
                }
                else
                {
                    T.erase(T.begin()+j);
                }
                
        }
    }
    return S==T;
   
       
    }

    class MinStack {
public:
    /** initialize your data structure here. */
    vector<pair<int, int>> st;
    
    void push(int x) {
        if (st.empty() || x <= st[st.size()-1].second)
		    st.push_back(make_pair(x, x));
	    else
		    st.push_back(make_pair(x, st[st.size() - 1].second));
    }
    
    void pop() {
        return st.pop_back();
    }
    
    int top() {
        return st[st.size() - 1].first;
    }
    
    int getMin() {
        return st[st.size() - 1].second;
    }
};
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 int height(TreeNode* node, int& ans)
 {
     if(node==NULL)
     {
         return 0;
     }
     int lft = height(node->left,ans);
     int rght = height(node->right,ans);
     ans = max(ans,lft+rght);
     return 1+max(lft,rght);
 }
 int diameterOfBinaryTree(TreeNode* root) {
    //  return 0;
    if(root==NULL)return 0;
    int ans=INT_MIN;
    int h = height(root,ans);
    return ans;
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
    int del=0;
    for(int i=0;i<shift.size();i++)
    {
        cout<<shift[i][0]<<" "<<shift[i][1]<<endl;
        if(shift[i][0]==0)
            {del+=shift[i][1];}
        else {del-=shift[i][1];}
    }   
    if(del<0)
    {
        del=-del;
        del%=s.length();
        del=-del;
    } else
    {
        del%=s.length(); 
    }
    
    char c;
    cout<<del<<endl;
    // if(del==0) return s;
    if(del>0)
    {
        while(del--)
        {
            // c=s[0];
            s.push_back(s.front());
            s.erase(s.begin());
        }
    } else
    {
        del= -del;
        while(del--)
        {
            s.insert(s.begin(),s.back());
            s.pop_back();
        }
    }
    return s;
    
}
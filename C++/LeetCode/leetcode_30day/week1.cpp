#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it=nums.begin();
        for(int i=0;i<nums.size();i++)
        {
            if(*it==0)
            {
                nums.erase(it);
                nums.push_back(0);
            }else it++;
        }
    }

    int maxProfit(vector<int>& price) {
        int n=price.size();
        int ans=0;
        if (n == 1) 
            return ans; 
    
        // Traverse through given price array 
        int i = 0; 
        while (i < n - 1) { 
    
            // Find Local Minima 
            // Note that the limit is (n-2) as we are 
            // comparing present element to the next element 
            while ((i < n - 1) && (price[i + 1] <= price[i])) 
                i++; 
    
            // If we reached the end, break 
            // as no further solution possible 
            if (i == n - 1) 
                break; 
    
            // Store the index of minima 
            int buy = i++; 
    
            // Find Local Maxima 
            // Note that the limit is (n-1) as we are 
            // comparing to previous element 
            while ((i < n) && (price[i] >= price[i - 1])) 
                i++; 
    
            // Store the index of maxima 
            int sell = i - 1; 
            ans+=(price[sell]-price[buy]);
            // cout << "Buy on day: " << buy 
                //  << "\t Sell on day: " << sell << endl; 
        } 
        return ans;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> mp;
        string temp;
        for(int i=0;i<strs.size();i++)
        {
            temp=strs[i];
            map<char,int> p;

            for(int j=0;j<temp.length();j++)
            {
                p[temp[j]]++;
            }
            mp[p].push_back(temp);
        }
        vector<vector<string>> ans;
        vector<string> y;
        map<map<char,int>,vector<string>>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            // y=it->second;
            // for(int j=0;j<y.size();j++)
            // {
            //     cout<<y[j]<<":";
            // }
            // cout<<endl;
            ans.push_back(it->second);
        }
        return ans;
        
    }

    int countElements(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int cou=0,ans=0,prev;
        prev=arr[0];
        cou=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==prev)
            {
                cou++;
                continue;
            }
            else if(arr[i]==(prev+1))
            {
                ans+=cou;
            }
            cou=1;
            prev=arr[i];
        }
        return ans;
    }

};
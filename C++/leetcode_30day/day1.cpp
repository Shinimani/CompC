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

    
};
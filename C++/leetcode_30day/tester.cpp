#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    vector<string> l;
    l.push_back("eat");
    l.push_back("tea");
    l.push_back("tan");
    l.push_back("ate");
    l.push_back("nat");
    l.push_back("bat");
    vector<vector<string>> k = groupAnagrams(l);
    cout<<"\n\n";
    for(int i=0;i<k.size();i++)
    {
        for(int j=0;j<k[i].size();j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
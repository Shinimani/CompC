// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PB push_back
#define V vector
#define FORI(i,a,b) for(int i =a;i<b;i++)

int maxcontsum(V<int> v)
{
    int ans = 0;
    int temp = 0;
    // int max = INT16_MIN;
    // int temp = 0;
    for(int i =0;i<v.size();i++)
    {
        // if (max<v[i]) max = v[i];
        temp += v[i];
        if (temp>ans) ans=temp;
        if (temp<0) temp=0;
    }
    // if (max<0) return max;
    return ans;
}
void printVec(V<int> v)
{
    FORI(i,0,v.size())
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<"Hello\n";
    // V<int> v;
    // // v.PB(1);
    // // cout<<v[0]<<"\n";
    // v.PB(-1);
    // v.PB(2);
    // v.PB(4);
    // v.PB(-3);
    // v.PB(5);
    // v.PB(2);
    // v.PB(-5);
    // v.PB(2);
    // cout<<maxcontsum(v)<<"\n";
    // printVec(v);
    // sort(v.begin(),v.end());
    // printVec(v);
    // sort(v.rbegin(),v.rend());
    // printVec(v);
    // string s = "monkeyM";
    // sort(s.begin(),s.end());
    // cout<<s<<"\n";

    V<pair<int,int>> v;
    // vp.PB({1,5});
    v.push_back({1,5});
    v.push_back({2,3});
    v.push_back({1,2});
    sort(v.begin(), v.end());
    // printVec(v);
    FORI(i,0,v.size())
    {
        cout<<"("<<v[i].first<<","<<v[i].second<<") ";
    }
    cout<<"\n";



}
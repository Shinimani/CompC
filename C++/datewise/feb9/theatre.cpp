#include <bits/stdc++.h>
// #include <iostream>
// #include <unordered_map> 
// #include <cmath>
// #include <vector>
// https://www.codechef.com/FEB20B/problems/CASH

using namespace std;

int main(){
    
    int n,k,t,temp,row,col,maxx,maxr,maxc;
    char c;
    int ans;
    cin>>t;
    int arr[4][4];
    vector<pair<int,int>> maxs;
    while(t-- > 0)
    {
        maxx=0;
        maxs.clear();
        //making the table 0
        for( int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                arr[i][j]=0;
            }
        }

        cin>>n;
        // cin>>k;
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            cin>>temp;
            if(c=='A')
                row = 0;
            else if (c=='B')
                row = 1;
            else if (c=='C')
                row = 2;
            else if (c=='D')
                row = 3;
            
            if(temp==12)
                col = 0;
            else if (temp==3)
                col = 1;
            else if (temp==6)
                col = 2;
            else if (temp==9)
                col = 3;
            
            arr[row][col]++;
            if(arr[row][col]>maxx)
            {
                maxx=arr[row][col];
                maxr=row;
                maxc=col;
            }
        }
        //the table has been made, first pass max element found
        //checking if multiple max element exist
        for( int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                arr[i][j]=0;
            }
        }
    }
    return 0;
}
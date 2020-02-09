// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map> 
// #include <cmath>
// #include <vector>

using namespace std;
// int max(int & a, int & b)
// {
//     if(a>b)
//     {
//         return a;
//     } else return b;
// }
// int min(int & a, int & b)
// {
//     if(a<b)
//     {
//         return a;
//     } else return b;
// }
// #define ll long long
// #define vc vector
// #define pb push_back
// // https://codeforces.com/contest/1288/problem/D
// void printvec(vc<ll> v)
// {
//     for(ll i:v)
//     {
//         cout<<i<<" ";
//     }
//     cout<<"\n";
// }


// long fact(int n)
// {
//     long a =1;
//     for(int i =1;i<=n;i++)
//     {
//         a *= (long)i;
//     }
//     return a;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    constexpr std::uint_fast8_t zero{ 0b0000'0000 }; // represents zero
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7
    cout<<mask2 + zero<<" aaa"<<endl;
    
    int n,m,temp1,temp2;
    temp2 = INT16_MIN;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>temp1;
            temp2 = max(temp2,temp1);
            arr[i][j]=temp1;
        }
    }
    int l=0,r=temp2,mid;
    unordered_map<uint_fast8_t, int> umap; 
  
    while (l<r)
    {
        mid =(l+r)/2;

    }
    
    // // int temp[m];
    // pair<int,int> ans;
    // temp2=INT16_MIN;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i;j<n;j++)
    //     {
    //         temp1=max(arr[i][0],arr[j][0]);
    //         for(int k=0;k<m;k++)
    //         {
    //             temp1 = min(temp1,(max(arr[i][k],arr[j][k])));
    //         }
    //         if(temp1>temp2)
    //         {
    //             temp2=temp1;
    //             // ans=(i,j);
    //             ans.first = i;
    //             ans.second = j;
    //         }
    //     }
    // }

    // cout<<ans.first + 1<<" "<<ans.second + 1<<"\n";


    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
// https://cses.fi/problemset/task/1622
void printvec(vc<ll> v)
{
    for(ll i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}


long fact(int n)
{
    long a =1;
    for(int i =1;i<=n;i++)
    {
        a *= (long)i;
    }
    return a;
}

//Prints the array 
void printArr(int a[],int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    printf("\n"); 
} 

// int factorial(int n)
// {
//     int ans=1;
//     for(int i=1;i<=n;i++)
//     {
//         ans*=i;
//     }
//     return ans;
// }

// // Generating permutation using Heap Algorithm 
// void heapPermutation(int a[], int size, int n, int j, int store[][]) 
// { 
//     // if size becomes 1 then prints the obtained 
//     // permutation 
//     if (size == 1) 
//     { 
//         printArr(a, n); 
//         return; 
//     } 
  
//     for (int i=0; i<size; i++) 
//     { 
//         heapPermutation(a,size-1,n); 
  
//         // if size is odd, swap first and last 
//         // element 
//         if (size%2==1) 
//             swap(a[0], a[size-1]); 
  
//         // If size is even, swap ith and last 
//         // element 
//         else
//             swap(a[i], a[size-1]); 
//     } 
// } 
  
// // Driver code 
// int main() 
// { 
//     int a[] = {1, 2, 3}; 
//     int n = sizeof a/sizeof a[0]; 
//     heapPermutation(a, n, n); 
//     return 0; 
// } 
char converter(int n)
{
    if (n==1) return 'A';
    if (n==2) return 'B';
    if (n==3) return 'C';
    return 'D';
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,p,row,col;
    char ch;
    int arr[4][4];
    //all permutations of 4
    int permut[24][4] ={{0,1,2,3},{1,0,2,3},{2,0,1,3},{0,2,1,3},{1,2,0,3},{2,1,0,3},{3,1,2,0},{1,3,2,0},{2,3,1,0},{3,2,1,0},{1,2,3,0},{2,1,3,0},{3,0,2,1},{0,3,2,1},{2,3,0,1},{3,2,0,1},{0,2,3,1},{2,0,3,1},{3,0,1,2},{0,3,1,2},{1,3,0,2},{3,1,0,2},{0,1,3,2},{1,0,3,2}};
    //permutations of prices
    int prices[24][4] = {{100,75,50,25},{75,100,50,25},{50,100,75,25},{100,50,75,25},{75,50,100,25},{50,75,100,25},{25,75,50,100},{75,25,50,100},{50,25,75,100},{25,50,75,100},{75,50,25,100},{50,75,25,100},{25,100,50,75},{100,25,50,75},{50,25,100,75},{25,50,100,75},{100,50,25,75},{50,100,25,75},{25,100,75,50},{100,25,75,50},{75,25,100,50},{25,75,100,50},{100,75,25,50},{75,100,25,50}};
    
    cin>>t;
    while(t--)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                arr[i][j]=0;
            }
        }
        //resetting the table
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ch>>p;
            if (ch=='A') row=0;
            if (ch=='B') row=1;
            if (ch=='C') row=2;
            if (ch=='D') row=3;

            if(p==12) col=0;
            if (p==3) col=1;
            if (p==6) col=2;
            if (p==9) col=3;
            
            arr[row][col]++;
        }
        for( int i=0;i<24;i++)
        {
            for(int j=0;j<24;j++)
            {
                
            }
        }
        //table made


    }
    
    return 0;
}
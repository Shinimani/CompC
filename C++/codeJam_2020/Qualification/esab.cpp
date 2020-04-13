#include <bits/stdc++.h>
using namespace std;

void flip(int n,bool arr[])
{
    for(int i=0;i<n;i++)
    {
        arr[i]=!arr[i];
    }
}
void reverse(int n,bool arr[])
{
    int i=0;
    int j=n-1;
    int temp;
    while(i<j)
    {
        arr[i]=temp;
        arr[i]=arr[j];
        arr[j]=temp;
        i++;j--;
    }
}
void fliprev(int n,bool arr[])
{
    flip(n,arr);
    reverse(n,arr);
}
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int test,s;
    cin>>test>>s;
    int q=1;
    bool f;
    bool fgamma=false;
    int locgamma[2];
    bool bothalpha=false;
    bool bothbeta=false;
    int locboth[4];
    bool alphabeta=false;
    int locaplhabeta[4];
    int i=0,j;
    bool ans[s];
    memset(ans,false,sizeof(ans));
    vector<int> found;
    int bit;
    bitset<4> bset1(0);
    bitset<4> bset2(0);
    bitset<4> which[16];
    int whichint;
    int bset1type;
    int bset2type;
    for(int i=0;i<16;i++)
    {
        which[i]=i;
    }
    while(found.size()<s)
    {
        if(q<11)
        {
            bset1=0;
            //the first 2 bits
            cout<<i+1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[i]=true;
                bset1.set(0);
            }
            else 
            {
                ans[i]=false;
            }
            cout<<i+1+1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[i+1]=true;
                bset1.set(1);
            }
            else 
            {
                ans[i+1]=false;
            }
            //the last 2 bits
            cout<<s-i-1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[s-i]=true;
                bset1.set(3);
            }
            else 
            {
                ans[s-i]=false;
            }
            cout<<s-i-1-1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[s-i-1]=true;
                bset1.set(2);
            }
            else 
            {
                ans[s-i-1]=false;
            }
            whichint = (int)(bset.to_ulong());
            if(whichint==0||whichint==6||whichint==9||whichint==15)
            bset1type=1;
            else if (whichint==3||whichint==5||whichint==10||whichint==12)
            bset1type=2;
            else bset1type=3;
            j=i;
            i=i+2;
            bset1=0;
            //the first 2 bits
            cout<<i+1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[i]=true;
                bset1.set(0);
            }
            else 
            {
                ans[i]=false;
            }
            cout<<i+1+1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[i+1]=true;
                bset1.set(1);
            }
            else 
            {
                ans[i+1]=false;
            }
            //the last 2 bits
            cout<<s-i-1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[s-i]=true;
                bset1.set(3);
            }
            else 
            {
                ans[s-i]=false;
            }
            cout<<s-i-1-1<<endl;
            cin>>bit;
            if(bit==1)
            {
                ans[s-i-1]=true;
                bset1.set(2);
            }
            else 
            {
                ans[s-i-1]=false;
            }
            whichint = (int)(bset.to_ulong());
            if(whichint==0||whichint==6||whichint==9||whichint==15)
            bset1type=1;
            else if (whichint==3||whichint==5||whichint==10||whichint==12)
            bset1type=2;
            else bset1type=3;


            
            

        }
    }

    // cin>>sz;

    // bitset<sz> ba,bb;
    // ba.set(0);
    // rev(sz,ba);
    // cout<<ba;




 	return 0;
}
 
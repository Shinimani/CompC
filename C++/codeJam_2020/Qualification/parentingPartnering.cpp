#include <bits/stdc++.h>
using namespace std;

struct Interval 
{ 
    int idx,start, end; 
}; 
  
// Compares two intervals according to ending times. 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.end < i2.end); 
} 
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int test,n;
    cin>>test;  
    int prev;
    int Idx,S,E;
    string ss;
    bool imp;
    vector<Interval> vec;

    for(int t=1;t<=test;t++)
    {
        imp=false;
        vec.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>S>>E;
            vec.push_back({i,S,E});
        }
        sort(vec.begin(), vec.end(), compareInterval);
        prev=-1;
        for(int i=0;i<n;i++)
        {
            Idx=vec[i].idx;
            S=vec[i].start;
            E=vec[i].end;
            if(S<prev && i!=n-1 && vec[i+1].start<prev)
            {
                imp=true;
                break;   
            } else prev=E;
        }
        if (imp)
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
        else
        {
            char ans[n];
            memset(ans,'C',sizeof(ans));
            ans[vec[0].idx-1]='J';
            prev=vec[0].end;
            for(int i=1;i<n;i++)
            {
                Idx=vec[i].idx;
                S=vec[i].start;
                E=vec[i].end;
                if(S<prev) continue;
                else
                {
                    // cout<<Idx;
                    ans[Idx-1]='J';
                    prev=E;
                }
            }
            ss.clear();
            for(char ch:ans)
            {
                ss.push_back(ch);
            }
            cout<<"Case #"<<t<<": "<<ss<<endl;
        }






    }


 	return 0;
}
 
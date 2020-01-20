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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ll n,a,b;
    int t,temp;
    // int* pos;
    // vc<int> iterator pos;
    std::vector<int>::iterator low,up;
  
    cin>>t;
    int n,s,k,upp,loww,counterl,counteru;
    vc<int> fll;
    while(t-->0)
    {   fll.clear();
        cin>>n>>s>>k;
        for(int i=0;i<k;i++)
        {
            cin>>temp;
            fll.pb(temp);
        }
        sort(fll.begin(),fll.end());
        if(binary_search(fll.begin(),fll.end(),s))
        {
            low = lower_bound(fll.begin(),fll.end(),s);
            loww = fll[low-fll.begin()];
            counterl = s;
            counteru = s;
            // up = lower_bound(fll.begin(),fll.end(),s);
            // low = low - fll.begin();
            // up = low;
            while(counterl == loww && low !=fll.begin())
            {
                counterl--;
                low--;
                loww = fll[low-fll.begin()];
                // loww = fll[low-fll.begin()];
            }
            if (low == fll.begin())
            {
                if (counterl == loww)
                    counterl--;
                
            }
            if(counterl==0)
            {
                counterl = INT16_MAX;
            } 
            else
            {
                counterl = s - counterl;
            }
            
            low = lower_bound(fll.begin(),fll.end(),s);
            loww = fll[low-fll.begin()];
            
            while(counteru == loww )
            {
                counteru++;
                low++;
                if (low !=fll.end())
                    loww = fll[low-fll.begin()];
                else
                {
                    break;
                }
            }
            if (low == fll.end())
            {
                if (counteru == loww)
                    counteru++;
            }
            if(counteru==n+1)
            {
                counteru=INT16_MAX;
            }
            else
            {
                
                counteru = counteru - s;
            }
            
            cout<<min(counterl,counteru)<<"\n";

        } else
        {
            cout<<"0\n";
        }
        
        

    }
    
    return 0;
}
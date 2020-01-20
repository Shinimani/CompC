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
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,q,x,y,tempu,tempd,i;
    // cout<<"before while loop4\n"<<endl;

    cin>>n>>q;
    // cout<<"before while loop3\n";
    
    bitset<100000> bup;
    bitset<100000> bdo;
    // cout<<"before while loop1\n";
    vc<int> vup;
    vc<int> vdo;
    vector<int>::iterator itru,itrd,it;

    bool ans = true;

    while(q--)
    {
        // int x1, y1;
        cin>>x>>y;
        if(x==1) bup.flip(y-1); 
        else bdo.flip(y-1);

        // cout<<"before iterators ";
        itru = lower_bound(vup.begin(),vup.end(),y-1);
        itrd = lower_bound(vdo.begin(),vdo.end(),y-1);
        // cout<<"after iterators\n";

        if(ans)
        {
            if(bup[y-1] && (bdo[y-1] || (y<n && bdo[y]) || (y-1>0 && bdo[y-2])))
            {
                vup.pb(y-1);
                cout<<"NO\n";
                ans = false;
            }
            else if(bdo[y-1] && (bup[y-1] || (y<n && bup[y]) || (y-1>0 && bup[y-2])))
            {
                vdo.pb(y-1);
                cout<<"no\n";
                ans = false;

            }
            else cout<<"yes\n";
        } else
        {
            cout<<"before iterators ";
            if (vup.empty())
            {
                it = lower_bound(vdo.begin(),vdo.end(),y-1);
                    {
                        i = vdo[it-vdo.begin()];
                        if(bdo[i] && (bup[i] || (i+1<n && bup[i+1]) || (i-1>=0 && bup[i-1])))
                        {
                            cout<<"no\n";
                            // break;
                        } else 
                        {
                            vdo.erase(it);
                            it--;
                        }    
                    }
                it++;
                if(it != vdo.end())
                    {
                        i = vdo[it-vdo.begin()];
                        if(bdo[i] && (bup[i] || (i+1<n && bup[i+1]) || (i-1>=0 && bup[i-1])))
                        {
                            cout<<"no\n";
                            // break;
                        } else 
                        {
                            vdo.erase(it);
                            it--;
                        }    
                    }
                if(vdo.empty())
                    {
                        cout<<"yes\n";
                        ans = true;
                    }
            } else if (vdo.empty())
            {
                it = lower_bound(vup.begin(),vup.end(),y-1);
                {
                    i = vup[it-vup.begin()];
                    if(bup[i] && (bdo[i] || (i+1<n && bdo[i+1]) || (i-1>=0 && bdo[i-1])))
                    {
                        cout<<"no\n";
                        // break;
                    } else 
                    {
                        vup.erase(it);
                        it--;
                    }    
                }
                it++;
                if(it!=vdo.end())
                {
                    i = vup[it-vup.begin()];
                    if(bup[i] && (bdo[i] || (i+1<n && bdo[i+1]) || (i-1>=0 && bdo[i-1])))
                    {
                        cout<<"no\n";
                        // break;
                    } else 
                    {
                        vup.erase(it);
                        it--;
                    }    
                }
                if (vup.empty())
                {
                        cout<<"yes\n";
                        ans = true;
                }
            } else 
            {

            tempu = vup[itru-vup.begin()];
            tempd = vdo[itrd-vdo.begin()];
            cout<<"after iterators\n";
            if(bup[tempu] && (bdo[tempu] || (tempu+1<n && bdo[tempu+1]) || (tempu-1>=0 && bdo[tempu-1])))
            {
                if(!binary_search(vup.begin(),vup.end(),y-1)) 
                {
                    vup.pb(y-1);
                    push_heap(vup.begin(),vup.end());
                    cout<<"no\n";
                } else
                {
                    cout<<"no\n";
                }
            } else if(bdo[tempd] && (bup[tempd] || (tempd+1<n && bup[tempd+1]) || (tempd-1>=0 && bup[tempd-1])))
            {
                if(!binary_search(vdo.begin(),vdo.end(),y-1)) 
                {
                    vdo.pb(y-1);
                    push_heap(vdo.begin(),vdo.end());
                    cout<<"no\n";
                } else
                {
                    cout<<"no\n";
                }
            } else
            {
                for(std::vector<int>::iterator it = vup.begin();it<vup.end();it++)
                {
                    i = vup[it-vup.begin()];
                    if(bup[i] && (bdo[i] || (i+1<n && bdo[i+1]) || (i-1>=0 && bdo[i-1])))
                    {
                        cout<<"no\n";
                        break;
                    } else 
                    {
                        vup.erase(it);
                        it--;
                    }    
                }
                if(vup.empty())
                {
                    for(std::vector<int>::iterator it = vdo.begin();it<vdo.end();it++)
                    {
                        i = vdo[it-vdo.begin()];
                        if(bdo[i] && (bup[i] || (i+1<n && bup[i+1]) || (i-1>=0 && bup[i-1])))
                        {
                            cout<<"no\n";
                            break;
                        } else 
                        {
                            vdo.erase(it);
                            it--;
                        }    
                    }
                    if(vdo.empty())
                    {
                        cout<<"yes\n";
                        ans = true;
                    }
                }
            }
                // if(bup[y-1] && (bdo[y-1] || (y<n && bdo[y]) || (y-1>0 && bdo[y-2])))
                // {
                //     vup.pb(y-1);
                //     cout<<"NO\n";
                //     ans = false;
                // }
                // else if(bdo[y-1] && (bup[y-1] || (y<n && bup[y]) || (y-1>0 && bup[y-2])))
                // {
                //     vdo.pb(y-1);
                //     cout<<"no\n";
                //     ans = false;
                // }   
            }

        }
    // cout<<"inside q loop\n";
    }

    // // bitset<4> bset;
    // // cout<<bset<<"\n";
    // // bset.flip(1);
    // // if(bset[1])
    // //     cout<<"bla"<<endl;

    return 0;
}
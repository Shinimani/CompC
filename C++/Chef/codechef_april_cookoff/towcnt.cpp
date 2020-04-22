#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
// #define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define hell1        1000000006
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
typedef vector<int> vi;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

// To compute x^y under modulo m 
ll expo(ll base, ll exponent, ll mod) {                                //return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
long long modInverse(long long a, long long m) 
{ 
    return expo(a, m-2, m); 
} 
  

int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}
// ll gcd(ll u,ll v)
// {
// 	if(v==0)
// 	return u;
	
// 	else
// 	return gcd(v,u%v);
// }

// // // #define MAX 1000000
// int primes[100009],cnt=0;
// // vector<int> factors[1000009];
// char str[1000009];
// void pre()
// {
//     // calcualting primes
//     int n=1000000;
//     for(int i=2; i*i<=n; i++)
//         if(str[i]==0)
//             for(int j=i; j*i<=n; j++)
//                 str[i*j]=1;
//     for(int i=2; i<=n; i++)
//         if(str[i]==0)primes[cnt]=i,cnt++;
// }

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);

    int t,n,temp,s;
    cin>>t;
    int p,q,h;
    int type,x,a;
    int ans=0;
    int f,d;
    int j;
    vector<pair<float,float>> pos;
    vi types;
    float lowerslope,upperslope,del;
    float lowermax,uppermax,loclower,locupper;
    int yaha;
    bool up,down,lowerdone,upperdone;
    vi arr[4];
    while(t--)
    {
        cin>>h>>n;
        // ans=0;
        lowermax=0;
        uppermax=h;
        pos.clear();
        repn(i,4)
            arr[i].clear();

    // vector<pi> lowerFront;   0
    // vector<pi> lowerBack;    1
    // vector<pi> upperFront;   2
    // vector<pi> upperBack;    3
        repn(i,n)
        {
            cin>>type>>x>>a;
            types.pb(type);
            pos.pb(mp(x,a));
            if(type==0)
            {
                if(a>=lowermax)
                    lowermax=a;
            } else
            {
                if(a<=uppermax)
                    uppermax=a;
            }
            arr[0].pb(lowermax);
            arr[1].pb(0);
            arr[2].pb(uppermax);
            arr[3].pb(h);
        }
        lowermax=0;
        uppermax=h;
        for(int i=n-1;i>=0;i--)
        {
            type=types[i];
            a=pos[i].second;
            if(type==0)
            {
                if(a>=lowermax)
                    lowermax=a;
            } else
            {
                if(a<=uppermax)
                    uppermax=a;
            }
            arr[1][i]=lowermax;
            arr[3][i]=uppermax;
        }

        // repn(i,4)
        // {
        //     cout<<i<<endl;
        //     repn(j,n)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        repn(i,n)
        {
            ans=0;
            if(i!=0)
            {
                //moving left now
                up=true;
                down=true;
                lowerdone=false;
                upperdone=false;

                for(j=i-1;j>=0;j--)
                {
                    type=types[j];
                    x=pos[j].first;
                    a=pos[j].second;
                    //if lower type ka ho to
                    if(type==0)
                    {
                        if(lowerdone)continue;
                        if(down)
                        //if kabhi pehle koi lower na aaya ho to
                        {
                            down=false;
                            lowermax=pos[j].second;
                            loclower=pos[j].first;
                            lowerslope = (float)(lowermax-pos[i].second)/(float)(loclower-pos[i].first);
                            if(up) ans++;
                            else
                            {
                                del = (upperslope*(double)(pos[i].first - x));
                                // cout<<endl<<upperslope<<endl;
                                yaha = pos[i].second - del;
                                // cout<<"   "<<yaha;
                                if(yaha>=a)
                                {
                                    ans++;
                                    // cout<<"   yaha hua   ";
                                }
                            }
                        } else
                        {
                            yaha= pos[i].second - (int) (lowerslope*(pos[i].first - x));
                            if (yaha>arr[0][j])
                            {
                                lowerdone=true;
                                if(upperdone) break;
                            }
                            else if(yaha<a)
                            {
                                if(up) ans++;
                                else
                                {
                                    yaha = pos[i].second - (int)(upperslope*(pos[i].first - x));
                                    if(yaha>=a)
                                    {
                                        ans++;
                                    }
                                }
                            }else
                            {
                                lowermax=pos[j].second;
                                loclower=pos[j].first;
                                lowerslope = (lowermax-pos[i].second)/(loclower-pos[i].first);
                            }
                        }
                        
                    }else
                    {
                        if(upperdone)continue;
                        if(up)
                        //if kabhi pehle koi upper na aaya ho to
                        {
                            up=false;
                            uppermax=pos[j].second;
                            locupper=pos[j].first;
                            upperslope = (float)(uppermax-pos[i].second)/(float)(locupper-pos[i].first);
                            if(down) ans++;
                            else
                            {
                                yaha = pos[i].second - (int)(lowerslope*(pos[i].first - x));
                                if(yaha<=a)
                                {
                                    ans++;
                                }
                            }
                        } else
                        {
                            yaha= pos[i].second - (int) (upperslope*(pos[i].first - x));
                            if (yaha<arr[2][j])
                            {
                                upperdone=true;
                                if(lowerdone) break;
                            }
                            else if(yaha>a)
                            {
                                if(down) ans++;
                                else
                                {
                                    yaha = pos[i].second - (int)(lowerslope*(pos[i].first - x));
                                    if(yaha<=a)
                                    {
                                        ans++;
                                    }
                                }
                            }else
                            {
                               uppermax=pos[j].second;
                               locupper=pos[j].first;
                               upperslope = (uppermax-pos[i].second)/(locupper-pos[i].first);
                            }
                        }
                    }
                }
            }
            if(i!=(n-1))
            {
                //moving right now
                up=true;
                down=true;
                lowerdone=false;
                upperdone=false;

                for(j=i+1;j<n;j++)
                {
                    type=types[j];
                    x=pos[j].first;
                    a=pos[j].second;
                    //if lower type ka ho to
                    if(type==0)
                    {
                        if(lowerdone)continue;
                        if(down)
                        //if kabhi pehle koi lower na aaya ho to
                        {
                            down=false;
                            lowermax=pos[j].second;
                            loclower=pos[j].first;
                            lowerslope = (lowermax-pos[i].second)/(loclower-pos[i].first);
                            if(up) ans++;
                            else
                            {
                                yaha = pos[i].second - (int)(upperslope*(pos[i].first - x));
                                if(yaha>=a)
                                {
                                    ans++;
                                }
                            }
                        } else
                        {
                            yaha= pos[i].second - (int) (lowerslope*(pos[i].first - x));
                            if (yaha>arr[1][j])
                            {
                                lowerdone=true;
                                if(upperdone) break;
                            }
                            else if(yaha<a)
                            {
                                if(up) ans++;
                                else
                                {
                                    yaha = pos[i].second - (int)(upperslope*(pos[i].first - x));
                                    if(yaha>=a)
                                    {
                                        ans++;
                                    }
                                }
                            }else
                            {
                                lowermax=pos[j].second;
                                loclower=pos[j].first;
                                lowerslope = (lowermax-pos[i].second)/(loclower-pos[i].first);
                            }
                        }
                        
                    }else
                    {
                        if(upperdone)continue;
                        if(up)
                        //if kabhi pehle koi upper na aaya ho to
                        {
                            up=false;
                            uppermax=pos[j].second;
                            locupper=pos[j].first;
                            upperslope = (uppermax-pos[i].second)/(locupper-pos[i].first);
                            if(down) ans++;
                            else
                            {
                                yaha = pos[i].second - (int)(lowerslope*(pos[i].first - x));
                                if(yaha<=a)
                                {
                                    ans++;
                                }
                            }
                        } else
                        {
                            yaha= pos[i].second - (int) (upperslope*(pos[i].first - x));
                            if (yaha<arr[3][j])
                            {
                                upperdone=true;
                                if(lowerdone) break;
                            }
                            else if(yaha>a)
                            {
                                if(down) ans++;
                                else
                                {
                                    yaha = pos[i].second - (int)(lowerslope*(pos[i].first - x));
                                    if(yaha<=a)
                                    {
                                        ans++;
                                    }
                                }
                            }else
                            {
                               uppermax=pos[j].second;
                               locupper=pos[j].first;
                               upperslope = (uppermax-pos[i].second)/(locupper-pos[i].first);
                            }
                        }
                    }
                }
            }
            cout<<ans<<" ";

        }
        cout<<"\n";
        
        
    }
    
 	return 0;
}
 
#include<bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=0;i<n;i++)
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define endl        '\n'
// #define pii         pair<ll int,ll int>
// #define vi          vector<ll int>
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
typedef vector<int> vi ;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<int,vector<int>,greater<int>> pqig;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqlg;

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
int abso(int x)
{
    if (x>0) return x;
    else return -x;
}
string reformat(string s) {
    vector<char> nums;
    vector<char> letters;
    for(auto c:s)
    {
        if(c>=48 && c<=57)nums.push_back(c);else letters.push_back(c);
    }
    
    if(abso(nums.size()-letters.size())>1)return "";
    else 
    {
        string ans="";
        if(nums.size()>=letters.size())
        {
            while(!letters.empty())
            {
                ans.push_back(nums.back());
                ans.push_back(letters.back());
                nums.pop_back();
                letters.pop_back();
            }
            if(!nums.empty())ans.push_back(nums.back());
        }else
        {
            while(!nums.empty())
            {
                ans.push_back(letters.back());
                ans.push_back(nums.back());
                nums.pop_back();
                letters.pop_back();
            }
            if(!letters.empty())ans.push_back(letters.back());
        }
        return ans;
    }
}

vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    map<int,map<string,int>> mp;
    int n=orders.size();
    int m,table;
    set<string> dishes;
    set<int> tables;
    for(int i=0;i<n;i++)
    {
        table=stoi(orders[i][1]); 
        tables.insert(table);
        mp[table][orders[i][2]]++;
        dishes.insert(orders[i][2]);
    }    
    set<string>::iterator its;
    set<int>::iterator iti;
    vector<vector<string>> ans;
    vector<string> temp;
    temp.push_back("Table");
    for(its=dishes.begin();its!=dishes.end();its++)
    {
        temp.push_back(*its);
    }
    ans.push_back(temp);
    for(iti=tables.begin();iti!=tables.end();iti++)
    {
        vector<string> vc;
        vc.push_back(to_string(*iti));
        for(its=dishes.begin();its!=dishes.end();its++)
        {
            vc.push_back(to_string(mp[*iti][*its]));
        }
        ans.push_back(vc);   
    }
    return ans;
}

int minNumberOfFrogs(string s) {
    vector<int> pos[5];
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='c')pos[0].push_back(i);
        else if(s[i]=='r')pos[1].push_back(i);
        else if(s[i]=='o')pos[2].push_back(i);
        else if(s[i]=='a')pos[3].push_back(i);
        else if(s[i]=='k')pos[4].push_back(i);
    }
    int k=pos[0].size();
    for(int i=1;i<5;i++)
    {
        if(pos[i].size()!=k)return -1;
    }    
    for(int i=0;i<k;i++)
    {
        // if(pos[0][i]>pos[1][i])
        for(int j=1;j<5;j++)
        {
            if(pos[j][i]<pos[j-1][i]) return -1;
        }
    }
    int ans=1,temp,temp2;
    for(int i=0;i<k;i++)
    {
        temp=1;
        for(int l=0;l<4;l++)
        {
            temp2 = lower_bound(pos[l].begin(),pos[l].end(),pos[4][i]) - pos[l].begin();
            temp2 = temp2 - i;
            temp = max(temp,temp2);
        }
        ans=max(ans,temp);
    }
    
    return ans;
}


 
void makeCombiUtil(vector<vector<int> >& ans, 
    vector<int>& tmp, int n, int left, int k) 
{ 
    // Pushing this vector to a vector of vector 
    if (k == 0) { 

        ans.push_back(tmp); 
        return; 
    } 
  
    // i iterates from left to n. First time 
    // left will be 1 
    for (int i = left; i <= n; ++i) 
    { 
        tmp.push_back(i); 
        makeCombiUtil(ans, tmp, n, i + 1, k - 1); 
  
        // Popping out last inserted element 
        // from the vector 
        tmp.pop_back(); 
    } 
} 
  
// Prints all combinations of size k of numbers 
// from 1 to n. 
vector<vector<int> > makeCombi(int n, int k) 
{ 
    vector<vector<int> > ans; 
    vector<int> tmp; 
    makeCombiUtil(ans, tmp, n, 1, k); 
    return ans; 
} 


void makeCombiUtil2(vector<vector<int> >& ans, 
    vector<int>& tmp, int n, int left, int k,vector<int>& nums,int& anss) 
{ 
    // Pushing this vector to a vector of vector 
    if (k == 0) { 
        for(int i=0;i<tmp.size();i++)
        {
            // if(i==0)anss+=
        }
        ans.push_back(tmp); 
        return; 
    } 
  
    // i iterates from left to n. First time 
    // left will be 1 
    for (int i = left; i <= n; ++i) 
    { 
        tmp.push_back(i); 
        makeCombiUtil2(ans, tmp, n, i + 1, k - 1,nums,anss); 
  
        // Popping out last inserted element 
        // from the vector 
        tmp.pop_back(); 
    } 
} 
  
// Prints all combinations of size k of numbers 
// from 1 to n. 
vector<vector<int> > makeCombi2(int n, int k) 
{ 
    vector<vector<int> > ans; 
    vector<int> tmp; 
    makeCombiUtil2(ans, tmp, n, 1, k); 
    return ans; 
} 


int main()
{
    io

    int t,n,temp,s;
    cin>>t;
    int ans,p,q;
    
    while(t--)
    {
        cin>>n;
        
        cout<<ans<<"\n";
        
    }
    
 	return 0;
}
 
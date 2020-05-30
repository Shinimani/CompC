#include <bits/stdc++.h>
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
#define ret         return
#define repnitr(itr,m) for(auto itr=m.begin();itr!=m.end();itr++)
#define repnrevitr(itr,m) for(auto itr=m.rbegin();itr!=m.rend();itr++)
typedef vector<int> vi ;
typedef vector<long long> vl ;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<int,vector<int>,greater<int>> pqig;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqlg;


vector<string> split_string(string);
bool compareInterval(vector<int> i1, vector<int> i2) 
{ 
    return (i1[2] > i2[2]); 
} 
int find(int p,vector<int> & parent)
{
    if(parent[p]!=p)
    {
        parent[p]=find(parent[p],parent);
    }
    return parent[p];
}
void Union(int p,int q,vector<int> & parent)
{
    int pp=find(p,parent);
    int pq=find(q,parent);
    if(pp==pq)return;
    parent[pp]=pq;
}

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    sort(roads.begin(),roads.end(),compareInterval);
    int n = roads.size()+1;
    vector<int> parent(n);
    bool machine[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        machine[i]=false;
    }
    int pp,pq,p,q;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        p=roads[i][0];
        q=roads[i][1];
        pp=find(p,parent);
        pq=find(q,parent);
        if(pp==pq)continue;
        if(machines[pp] && machines[pq])
        {
            ans+=roads[i][2];
            continue;
        }
        Union(pp,pq,parent);
        if(machines[pp]||machines[pq]||machines[p]||machines[q])
        {
            machines[pp]=true;
            machines[pq]=true;
        }
    }
    return ans;
}

int main()
{
    vector<int> parent(5);
    for(int i=0;i<5;i++)
    {
        parent[i]=i;
    }
    Union(2,1,parent);
    for(int i=0;i<5;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    Union(1,0,parent);
    for(int i=0;i<5;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    Union(2,4,parent);
    for(int i=0;i<5;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    Union(1,3,parent);
    for(int i=0;i<5;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;


//     ofstream fout(getenv("OUTPUT_PATH"));

//     string nk_temp;
//     getline(cin, nk_temp);

//     vector<string> nk = split_string(nk_temp);

//     int n = stoi(nk[0]);

//     int k = stoi(nk[1]);

//     vector<vector<int>> roads(n - 1);
//     for (int i = 0; i < n - 1; i++) {
//         roads[i].resize(3);

//         for (int j = 0; j < 3; j++) {
//             cin >> roads[i][j];
//         }

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     vector<int> machines(k);

//     for (int i = 0; i < k; i++) {
//         int machines_item;
//         cin >> machines_item;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');

//         machines[i] = machines_item;
//     }

//     int result = minTime(roads, machines);

//     fout << result << "\n";

//     fout.close();

//     return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

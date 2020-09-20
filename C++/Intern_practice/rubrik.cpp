#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


bool comp (char s1, char s2) 
{ 
    return tolower(s1)<tolower(s2); 
} 

struct DS {
    string name;
    int score; 
    // This function is used by set to order 
    // elements of Test. 
    bool operator<(const DS& p2) const
    { 
        if(this->score==p2.score)
        {
            string s1 = this->name;
            string s2 = p2.name;
            return lexicographical_compare(s2.begin(), s2.end(), s1.begin(),s1.end(), comp);
        }
        return this->score<p2.score;
    }
}; 

struct find_by_name {
    find_by_name(const string& name) : name(name) {}
    bool operator()(const DS & elem) {
        return elem.name == name;
    }
private:
    string name;
};

int main()
{
    int n;
    cin>>n;
    set<struct DS> Q; 
    while(n--)
    {
        char query_type;
        cin>>query_type;
        if(query_type=='M')
        {
            DS top = *Q.rbegin();
            cout<<top.name<<" "<<top.score<<endl;
            continue;
        }
        if(query_type=='A')
        {
            string name;
            cin>>name;
            int score;
            cin>>score;
            struct DS* elem= new DS;
            elem->score = score;
            elem->name = name;
            Q.insert(*elem);

            continue;
        }
        if(query_type=='D')
        {
            string name;
            cin>>name;
            auto it = find_if(Q.begin(), Q.end(), find_by_name(name));
            if(it!=Q.end())
                Q.erase(it);
            continue;
        }
        if(query_type=='G')
        {
            string name;
            cin>>name;
            auto it = find_if(Q.begin(), Q.end(), find_by_name(name));
            if(it!=Q.end())
                cout<<it->score<<endl;
            else cout<<0<<endl;
            continue;
        }

    }
 	return 0;
}
 
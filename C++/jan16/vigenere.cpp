#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back

vc<int> toInt(string txt)
{
    vc<int> ans;
    string bla = ""+txt;
    int temp=0;
    for(int i=0;i<txt.length();i++)
    {
        temp = (int)txt[i] - (int)'A';
        ans.pb(temp);
    }
    return ans;
}
string decode(vc<int> vect)
{
    string ans;
    int temp = 0;
    for(int i=0;i<vect.size();i++)
    {
        if (i%5==0) ans.pb(' ');
        temp = (int)'A';
        temp+=vect[i];
        ans.pb((char)temp);
    }
    return ans;
}
void printvec(vc<int> v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void subtract(vc<int> & coded, vc<int> key)
{
    int n = coded.size();
    for(int i=0;i<n/5;i++)
    {
        for(int j=0;j<5;j++)
        {
            coded[5*i + j] -= key[j];
            if (coded[5*i + j] <0) coded[5*i + j] +=26;
        }
    }
    // return coded;   
}

void add(vc<int> & coded, vc<int> key)
{
    int n = coded.size();
    for(int i=0;i<n/5;i++)
    {
        for(int j=0;j<5;j++)
        {
            coded[5*i + j] += key[j];
            if (coded[5*i + j] >=26) coded[5*i + j] -=26;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // "LJVBQ STNEZ LQNED LJVMA MPKAU FAVAT LJVDA YYVNF JQLNP LJVHK VTRNF LJVCM LKETA LJVHU YJVSF KRFTT WEFUX VHZNP";
    string str = "LJVBQ STNEZ LQNED LJVMA MPKAU FAVAT LJVDA YYVNF JQLNP LJVHK VTRNF LJVCM LKETA LJVHU YJVSF KRFTT WEFUX VHZNP";
    // string str = "HELLO";
    string key = "IYJPT";
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    cout<<str<<"\n";
    vc<int> coded = toInt(str);
    // printvec(coded);
    // vc<int> keyv = toInt(key);
    vc<int> keyv;
    keyv.pb(8);
    keyv.pb(24);
    keyv.pb(9);
    // for(int i=0;i<26;i++)
    int i=16;
    {
        for(int j=0;j<26;j++)
        {
            cout<<i<<" "<<j<<"\n";
            keyv.pb(i);
            keyv.pb(j);
            add(coded,keyv);
            string deco = decode(coded);
            cout<<deco<<"\n";
            subtract(coded,keyv);
            keyv.pop_back();
            keyv.pop_back();
        }
    }

    return 0;
}
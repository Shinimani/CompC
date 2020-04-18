// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include "hanoi.h"
#include "cube.h"

using namespace std;
#define PB push_back
#define V vector

class hanoi
{
    V<V<cube>> stacks_;
    public:
    hanoi(int n)
    {
        // stacks_ = new V<V<cube>>;
        V<cube> first;
        stacks_.PB(first);
        V<cube> second;
        stacks_.PB(second);    
        V<cube> third;
        stacks_.PB(third);
        for (int i =n-1;i>=0;i--){
            stacks_[0].PB(cube(i));
        }
    }

    void printS(int index)
    {
        V<cube> &temp = stacks_[index];
        for(int i =0;i<temp.size();i++)
        {
            cout<<temp[i].getLen()<<" ";
        }
        cout<<"\n";
    }

    void printAll()
    {
        for(int i =0;i<3;i++)
        {
            if (stacks_[i].size()!=0)
            {
                cout<<"Stack number "<<i<<":\n";
                printS(i);
            } else cout<<"Stack number "<<i<<" is empty\n";
        }
    }

    void move(int a,int b)
    {
        if(stacks_[a].size()==0)
        {
            cout<<"Invalid move, stack "<<a<<" is empty\n";
        } else {
            // V<cube> sta = stacks_[a];
            cube temp;
            temp = stacks_[a][stacks_[a].size()-1];
            stacks_[a].pop_back();
            stacks_[b].push_back(temp);
            cout<<"Moved cube of length "<<temp.getLen()<<" from "<<a<<" to "<<b<<"\n";
            // int len = temp.getLen();
            // cout<<temp.getLen()<<"\n";
            // printS(a);
            // printS(b);

        }
    }

    void shift(int n, int a, int b)
    {
        if(stacks_[a].size()==0)
        {
            cout<<"Invalid move, stack "<<a<<" is empty\n";
        } else if(n == 1)
        {
            move(a,b);

        } else if(n == 2)
        {
            move(a,3-a-b);
            move(a,b);
            move(3-a-b,b);
        } else
        {
            shift(n-1,a,3-a-b);
            shift(1,a,b);
            shift(n-1,3-a-b,b);
        }
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    hanoi game(4);
    cout<<"Finished construction\n";
    game.printAll();

    game.shift(4,0,1);
    game.printAll();
    cout<<"Finished\n";

    return 0;
}

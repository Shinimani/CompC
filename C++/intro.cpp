#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Note that the newline "\n" works faster than endl, because endl always
    // causes a flush operation.

    cout<<"Hello world"<<endl;
    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("%d and %d\n",a,b);
    // string st;
    // getline(cin, st);
    // cout<<st;
    int a = 123456789;
    long long b = a*a;
    cout << b << "\n"; // -1757895751

    b = (long long) a*a;
    cout << b << "\n"; // correct answer
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    int x;
    auto it = s.lower_bound(x); 
    if (it == s.begin()) { cout << *it << "\n";
    } else if (it == s.end()) { it--; cout << *it << "\n";
    } else { int a = *it; it--; int b = *it; if (x-b < a-x) cout << b << "\n"; else cout << a << "\n";
    }

}
// #include <bits/stdc++.h>
#include <iostream>

// using std::cout;
// using std::ios;
// using std::cin;

using namespace std;


template <typename T>
T maxx(T a, T b)
{
    if (a>b) {return a;}
    return b;
}


// void relationalOperation(string s1, string s2) 
// { 

// 	if (s1 != s2) 
// 		cout << s1 << " is not equal to "
// 			<< s2 << endl; 
// 	if (s1 > s2) 
// 		cout << s1 << " is greater than "
// 			<< s2 << endl; 
// 	else
// 		cout << s2 << " is greater than "
// 			<< s1 << endl; 
// } 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // cout<<"Hello\n";
    // string s = "Hello";
    cout<<maxx(3,4)<<"\n";
    cout<<maxx('a','d')<<"\n";
    cout<<maxx("Hello","World")<<"\n";
    // string s1("Hello"); 
	// string s2("World"); 
    // if ("Hello">"World")
    // {
    //     cout<<"Hello"<<"\n";
    // } else cout <<"World"<<"\n";

	// relationalOperation(s1, s2); 

    return 0;


}


// // CPP code to implement relational 
// // operators on string objects 
// #include <iostream> 
// using namespace std; 

// void relationalOperation(string s1, string s2) 
// { 

// 	if (s1 != s2) 
// 		cout << s1 << " is not equal to "
// 			<< s2 << endl; 
// 	if (s1 > s2) 
// 		cout << s1 << " is greater than "
// 			<< s2 << endl; 
// 	else
// 		cout << s2 << " is greater than "
// 			<< s1 << endl; 
// } 

// // Main function 
// int main() 
// { 
// 	string s1("Hello"); 
// 	string s2("World"); 
// 	relationalOperation(s1, s2); 
// 	return 0; 
// } 

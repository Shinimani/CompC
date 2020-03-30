#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vc vector
#define pb push_back
#define sc(n) fastscan(n)
#define fr(i,a,b) for(int i=a;i<b;i++)
// https://www.codechef.com/problems/TAAND

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 
int gcd(int u,int v)
{
	if(v==0)
	return u;
	
	else
	return gcd(v,u%v);
}long long int coins(long long int* a, long long int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	if (a[n] != 0) {
		return a[n];
	}
	a[n] = max(n, coins(a, n / 2) + coins(a, n / 3) + coins(a, n / 4));

	return a[n];		
}

int main() {
	long long int n;

	while (cin >> n) {
		long long int* a = new long long int[n + 1];
		cout << coins(a, n) << endl;
	}

	cout << endl;
}
// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
#define int long long
#define inf 100000000000000000 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
int i; string res;
/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
	for(int i = 0 ; i < 10 ; ++i) {
        cout << i << endl;
        string s; getline(cin, s);
		if(s != "no") cout << ((s == "don't touch me" || s == "don't think so" || s == "cool" || s == "great" || s == "not bad") ? "normal" : "grumpy") << endl;
	}
}
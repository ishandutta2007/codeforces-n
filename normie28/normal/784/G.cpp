// Credit to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long 
#define ll int64_t 
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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fi first 
#define se second 
 
/*********VARIABLE****************/
struct bd {ll v; ll c;};
typedef pair<int,int> ii;
/******************************/
const ll po[94]={0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51, 1, 2, 1, 14, 1, 2, 2, 14, 1, 6, 1, 4, 2, 2, 1, 52, 2, 5, 1, 5, 1, 15, 2, 13, 2, 2, 1, 13, 1, 2, 4, 267, 1, 4, 1, 5, 1, 4, 1, 50, 1, 2, 3, 4, 1, 6, 1, 52, 15, 2, 1, 15, 1, 2, 1, 12, 1, 10, 1, 4, 2};
ll n,i,j,x,y,z,minn=0,t,pr,b,k;
bd all[300001]; bd h;
ll dp[300001][3];
int a[250];
char op[250];
int c = 0;
 /*********FUNCTIONS**************/

/***********MAIN**************/
 
 // ya succ
 
int main()
{
 	srand(time(0));
	ios::sync_with_stdio(0);
#ifdef _F1A4X_
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s;
	ll sum = 0, x = 0;
	char l = '+';
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (l == '+')
			{
				sum += x;
			}
			else
			{
				sum -= x;
			}
			l = s[i];
			x = 0;
		}
		else
		{
			x = x * 10 + s[i] - '0';
		}
	}
	if (l == '+')
	{
		sum += x;
	}
	else
	{
		sum -= x;
	}
	stringstream str;
	str << sum;
	str >> s;
	for (int i = 0; i < s.size(); i++)
	{
		cout << ">";
		for (int j = 0; j < s[i]; j++)
		{
			cout << "+";
		}
		cout << "." << endl;
	}
	cout << endl;
}
//kitten
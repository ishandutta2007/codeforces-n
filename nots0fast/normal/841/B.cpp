#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 100001
#define sz 300
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	bool var = 0;
	fori(n){
		int ed;
		cin>>ed;
		if(ed&1)
			var = 1;
	}
	if(var)
		cout<<"First";
	else
		cout<<"Second";
}
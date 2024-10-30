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
int i,n,m,k,a,d,b,c;
long long mod;
int o[511];
long long l[511][511];
 

/*********FUNCTIONS**************/

/***********MAIN**************/

signed main(){ 
    scanf("%d %d %d %lld",&a,&b,&c,&mod);
    for(int t=1;t<=a;t++)
        scanf("%d",&o[t]);
    l[b][c]=1;
    for(int i=a;i>0;i--)
    for(int t=b;t>0;t--)
        for(int w=c;w>=o[i];w--)
            l[t-1][w-o[i]]+=l[t][w],l[t-1][w-o[i]]%=mod;
    long long x=0;
    for(int t=0;t<=c;t++)
        x+=l[0][t],x%=mod;
    printf("%lld",x);
}
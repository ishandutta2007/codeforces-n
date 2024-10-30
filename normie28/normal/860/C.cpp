#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
vector<pii(int)> vec;
int n,m,i,j,k,t,t1,u,v,a,b,e;
set<int> fil[3][2];
set<int> slo[2];
int arr[200002],brr[200002];
map<string,int> ntc;
string ctn[200002],s;
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=n+1;i++)
    {
        s=to_string(i);
        ntc[s]=i;
        ctn[i]=s;
    }
    t=n+1;
    for (i=1;i<=n;i++)
    {
        cin>>s;
        if (ntc[s]==0)
        {
            t++;
            ntc[s]=t;
            ctn[t]=s;
        }
        arr[i]=ntc[s];
        cin>>brr[i]; e+=brr[i];
    }
    for (i=1;i<=n;i++) if (i<=e) slo[1].insert(i); else slo[0].insert(i);
    for (i=1;i<=n;i++)
    {
        if (arr[i]<=e) u=1;
        else if (arr[i]<=n) u=0;
        else u=2;
        fil[u][brr[i]].insert(i);
        if (u<=1) slo[u].erase(arr[i]);
    }
    if (!(slo[0].size()+slo[1].size()))
    {
        if (fil[0][1].size())
        {
            u=*(fil[0][1].begin());
            vec.push_back({arr[u],n+1});
            fil[0][1].erase(u);
            fil[2][1].insert(u);
            slo[0].insert(arr[u]);
            arr[u]=n+1;
        }
    }
    while ((fil[0][1].size())and(fil[1][0].size()))
    {   
        u=*(fil[0][1].begin());
        v=*(fil[1][0].begin());

        fil[0][1].erase(u);
        fil[1][0].erase(v);

        fil[1][1].insert(u);
        fil[0][0].insert(v);

        if (slo[0].size())
        {
            a=*(slo[0].begin());
            vec.push_back({arr[v],a});
            vec.push_back({arr[u],arr[v]});
            slo[0].erase(a);
            slo[0].insert(arr[u]);
            arr[v]=a;
            arr[u]=arr[v];
        }
        else
        if (slo[1].size())
        {
            a=*(slo[1].begin());
            vec.push_back({arr[u],a});
            vec.push_back({arr[v],arr[u]});
            slo[1].erase(a);
            slo[1].insert(arr[v]);
            arr[u]=a;
            arr[v]=arr[u];
        }
    }

    while(fil[0][1].size())
    {
        u=*(fil[0][1].begin());
        fil[0][1].erase(u);
        fil[1][1].insert(u);
        a=*(slo[1].begin());
        slo[1].erase(a);
        slo[0].insert(arr[u]);
        vec.push_back({arr[u],a});
        arr[u]=a;
    }

    while(fil[1][0].size())
    {
   //     cout<<"sol.size()"<<slo[0].size()<<endl;
        u=*(fil[1][0].begin());
        fil[1][0].erase(u);
        fil[0][0].insert(u);
        a=*(slo[0].begin());
        slo[0].erase(a);
        slo[1].insert(arr[u]);
        vec.push_back({arr[u],a});
        arr[u]=a;
    }
    while(fil[2][0].size())
    {
        u=*(fil[2][0].begin());
        fil[2][0].erase(u);
        fil[0][0].insert(u);
        a=*(slo[0].begin());
        slo[0].erase(a);
        vec.push_back({arr[u],a});
        arr[u]=a;
    }
    while(fil[2][1].size())
    {
        u=*(fil[2][1].begin());
        fil[2][1].erase(u);
        fil[1][1].insert(u);
        a=*(slo[1].begin());
        slo[1].erase(a);
        vec.push_back({arr[u],a});
        arr[u]=a;
    }

    cout<<vec.size()<<endl;
    for (auto g : vec)
    {
   //     cout<<"movee "<<g.fi<<' '<<g.se<<endl;
        cout<<"move "<<ctn[g.fi]<<' '<<ctn[g.se]<<endl;
    }
}
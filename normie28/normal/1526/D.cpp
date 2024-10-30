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
ll n,m,i,j,k,t,t1,u,v,a,b;
// A = 0, T = 1, O = 2, N = 3
int cnt[4]; // Dem so luong ky tu thuoc moi loai
ll moves[4][4]; // moves[i][j] la dem so lan swap de cac ky tu i dung truoc cac ky tu j (gia su trong xau chi co cac ky tu i va j)
// O day chung ta bieu dien 1 xau duoi dang 1 vector: {0,1,2,3} nghia la xau co dang ((cac ky tu 0)(cac ky tu 1)(cac ky tu 2)(cac ky tu 3))
vector<int> res; // xau ket qua hien tai
ll maxx; // So lan swap tuong ung voi xau ket qua
vector<int> per; // xau dang xet
ll cur; // So lan swap tuong ung voi xau dang xet
string s;
char cc[4]={'A','T','O','N'};
int main()
{
	fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>s;
        n=s.length();
        for (i=0;i<4;i++) cnt[i]=0;
        for (i=0;i<4;i++) for (j=0;j<4;j++) if (i-j)
        {
            moves[i][j]=0;
            a=0;
            for (k=0;k<n;k++)
            {
                if (s[k]==cc[j]) a++;
                if (s[k]==cc[i]) moves[i][j]+=a;
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<4;j++) if (s[i]==cc[j]) cnt[j]++;
        }
        maxx=-1;
        per={0,1,2,3};
        do
        {
            cur=0;
            for (i=0;i<4;i++) for (j=i+1;j<4;j++) cur+=moves[per[i]][per[j]];
            if (cur>maxx)
            {
                maxx=cur;
                res=per;
            }
        } while (next_permutation(per.begin(),per.end()));
        for (i=0;i<4;i++)
        {
            for (j=0;j<cnt[res[i]];j++) cout<<cc[res[i]];
        }
        cout<<endl;
    }
}
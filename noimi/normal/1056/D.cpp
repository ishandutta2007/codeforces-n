#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 1e9+7
#define N 201000
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()

int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll,int,custom_hash>
struct pair_hash
{
    template<class T1,class T2>
    size_t operator() (const pair<T1,T2> &p)const{
        return hash<T1>()(p.first)^hash<T2>()(p.second);
    }
};

vec G[N];
int c[N];
int dfs(int x){
    int res=0;
    rep(i,G[x].size()){
        res+=dfs(G[x][i]);
    }
    if(G[x].size()==0)res++;
    return c[x]=res;
}
main(){
    int n;
    cin>>n;
    int p[N];
    p[1]=-1;
    rep2(i,2,n){
        p[i]=in();
        G[p[i]].pb(i);
    }
    vector<int> v;
    dfs(1);
    rep2(i,1,n){
        v.pb(c[i]);
    }
    sort(ALL(v));
    rep(i,n){
        cout<<v[i]<<" ";
    }
}
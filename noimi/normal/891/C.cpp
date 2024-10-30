#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),(x)))
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vec iota(int n){vec a(n);iota(all(a),0);return a;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
#define _GLIBCXX_DEBU
#define endl '\n'
#ifdef _MY_DEBUG
    #undef endl
    #define debug(x) cout<<#x<<": "<<x<<endl
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion

struct UnionFind2 {
  vector< int > data;
 
  UnionFind2(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

constexpr int N = 500010;
struct UnionFind {
    array<int,N> time;
    array<int,N> par;
    int now=0;
    UnionFind(int sz){
        rep(i,sz)time[i]=INT_MAX;
        rep(i,sz)par[i]=i;
    }
    int find(int t,int x){
        if(time[x]>t)return x;
        else return find(t,par[x]);
    }
    int unite(int x,int y){
        ++now;
        x=find(now,x);
        y=find(now,y);
        if(x==y) return now;
        if(par[x]<par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        time[y]=now;
        return now;
    }
};

template< typename T >
struct edge {
  int src, to;
  T cost;
  edge(int _src,int _to,T _cost):src(_src),to(_to),cost(_cost){}


  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in();
    int m=in();
    Edges<int> ed;
    vec costs;
    rep(i,m){
        int x=in()-1,y=in()-1,c=in();
        costs.eb(c);
        ed.eb(x,y,c);
    }
    sort(all(costs));
    costs.erase(unique(all(costs)),costs.end());
    for(auto &e:ed) e.cost = lb(costs,e.cost);
    int cost_num=costs.size();
    UnionFind2 uf(n);
    ed.emplace_back(-1,-1,INT_MAX);
    vec id=iota(m+1);
    sort(all(id),[&](int x,int y){return ed[x].cost<ed[y].cost;});
    vec time(m+1);
    rep(i,m)time[id[i]]=i;
    int pre=-1;
    vec pretime(cost_num);
    vecpii mem(m+1);
    vec proc;
    for(auto i:id){
        if(pre<ed[i].cost){
            for(auto e:proc){
                mem[e]={uf.find(ed[e].src),uf.find(ed[e].to)};
            }
            for(auto e:proc)uf.unite(ed[e].src,ed[e].to);
            proc=vec();
            pre=ed[i].cost;
        }
        proc.eb(i);
    }
    int q=in();
    while(q--){
        int k=in();
        vec v;
        rep(i,k){
            v.pb(in()-1);
        }
        sort(all(v),[&](int x,int y){return ed[x].cost<ed[y].cost;});
        int precost = ed[v[0]].cost;
        v.eb(m);
        bool res=true;
        vec now;
        for(auto &w:v){
            auto &E=ed[w];
            if(precost==E.cost){
                now.eb(w);
                continue;
            }
            int cnt = 0;
            Edges<int> proc;
            for(auto &i:now){
                auto e = ed[i];
                e.src=mem[i].fi;
                e.to =mem[i].se;
                proc.eb(e);
            }
            vec num;
            for(auto &e:proc){
                num.eb(e.src);num.eb(e.to);
            }
            sort(all(num));
            num.erase(unique(all(num)),num.end());
            UnionFind2 uf2(num.size());
            for(auto &e:proc){
                res&=uf2.unite(lb(num,e.src),lb(num,e.to));
            }
            vec next{w};
            std::swap(now,next);
            precost=E.cost;
            if(!res)break;
        }
        cout<< (res ? "YES\n":"NO\n");
    }
}
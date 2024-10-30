#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
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
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
#define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}




int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    
    int t=in();
    int p[200];
    int pos=0;
    int primes[1100]={};
    primes[0]=primes[1]=1;
    rep2(i,2,1099){
        if(!primes[i]){
            p[pos++]=i;
            for(int j=i*2;j<1099;j+=i){
                primes[j]=1;
            }
        }
    }

    while(t--){
        int a=in(),b=in();
        bool flag=1;
        rep(i,pos){
            int e=p[i];
            int A=0,B=0;
            while(a%e==0){a/=e;A++;}
            while(b%e==0){b/=e;B++;}
            flag &= ((A+B)%3==0 and max(A,B)<=min(A,B)*2);
            if(a==1 or b==1)break;
        }
        if(a==b*b or b==a*a){a=1;b=1;}
        if(a>1 or b>1)flag=0;
        cout<<(flag? "Yes":"No")<<endl;
    }
}
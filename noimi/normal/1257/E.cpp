#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=998244353;


main(){
    int a,b,c;
    cin>>a>>b>>c;
    vec v(a+b+c+1);
    rep(i,a){
        v[in()]=0;
    }
    rep(i,b)v[in()]=1;
    rep(i,c)v[in()]=2;
    int n=a+b+c;
    vec cnt(n+1);
    cnt[0]=b;
    rep2(i,1,n){
        if(v[i]==1)cnt[i]=cnt[i-1]-1;
        else if(v[i]==2)cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1];
    }
    vector<pii> mem;
    mem.pb(pii{n,cnt[n]});
    rep3(i,n-1,0){
        if(cnt[i]<mem[mem.size()-1].second)mem.pb(pii{i,cnt[i]});
    }
    reverse(all(mem));
    int cnta=0,ans=a+mem[0].second,cntc=0,tmp=0;
    int now=0;
    rep2(i,1,n){
        if(v[i]==0)cnta++;
        else if(v[i]==2)cntc++;
        else tmp++;
        if(mem[now].first<i)now++;
        ans=min(ans,tmp+(a-cnta)+mem[now].second);
    }
    cout<<ans<<endl;
}
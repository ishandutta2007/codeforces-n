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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
//#define N 110000



main(){
    int n=in();
    bool flag=false;
    int pre=in();
    vec a;a.pb(pre);
    int ans=0;
    rep(i,n-1){
        if(pre==1){
            pre=in();
            a.pb(pre);
            if(pre==2)ans+=3;
            else ans+=4;
        }
        else if(pre==2){
            pre=in();
            a.pb(pre);
            if(pre==1)ans+=3;
            else flag=true;
        }
        else{
            pre=in();
            a.pb(pre);
            if(pre==1)ans+=4;
            else flag=true;
        }
    }
    rep(i,n-2){
        if(a[i]==3&&a[i+1]==1&&a[i+2]==2)ans--;
    }
    cout<<(flag?"Infinite\n":"Finite\n");
    if(!flag)cout<<ans;
}
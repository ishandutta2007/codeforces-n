#import<bits/stdc++.h>
using namespace std;int n,u,v,c[2];vector<int>g[1<<18];void d(int t,int p){c[n^=1]++;for(int o:g[t])o^p?d(o,t),n^=1:1;}main(){for(cin>>n;n-->1;g[u].push_back(v),g[v].push_back(u))cin>>u>>v;d(1,1);cout<<min(*c,c[1])-1;}
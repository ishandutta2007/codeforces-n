#import<bits/stdc++.h>
using namespace std;int n,x,f[200001],szf,g[200001],szg,p,a[200001];const int inf=1e9;main(){cin>>n;f[0]=g[0]=-2*inf;for(int i=1;i<=n;i++)cin>>a[i],a[i]-=i+inf;for(int i=2;i<=n;i++)p=upper_bound(g,g+szg+1,a[i]+1)-g,szg=max(szg,p),g[p]=a[i]+1,p=upper_bound(f,f+szf+1,a[i-1])-f,szf=max(szf,p),f[p]=a[i-1],g[p]=min(g[p],f[p]);cout<<n-1-max(szg,szf);}
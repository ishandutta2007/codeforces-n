#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,ans[maxn],al;
int main(){
	n=read();k=read();
	if(1ll*k*(k+1)/2>n) return puts("NO"),0;
	FOR(i,1,k) ans[i]=i;
	int sum=k*(k+1)/2,ad=(n-sum)/k;
	FOR(i,1,k) ans[i]+=ad;
	sum=(n-sum)%k;
	ROF(i,k,k-sum+1){
		ans[i]++;
		if(ans[i]>2*ans[i-1]) ans[i]--,ans[k]++;
	}
	if(k!=1 && ans[k]>2*ans[k-1]) puts("NO");
	else{
		puts("YES");
		FOR(i,1,k) printf("%d ",ans[i]);
	}
}
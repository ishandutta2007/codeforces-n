#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=3e5+5;
int T,n,pos[N],top;
char a[4][N];
int s[4][2];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=3;i++)scanf("%s",a[i]+1);
		mem0(s);
		for(int i=1;i<=3;i++){
			for(int k=1;k<=2*n;k++){
				s[i][a[i][k]-'0']++;
			}
		}
		int ta=-1,tb,id;
		for(int i=1;i<=3;i++){
			for(int k=i+1;k<=3;k++){
				if(s[i][0]>=n && s[k][0]>=n){
					ta=i;tb=k;id=0;
					break;
				}
				if(s[i][1]>=n && s[k][1]>=n){
					ta=i;tb=k;id=1;
					break;
				}
			}
			if(ta!=-1)break;
		}
		int tot=0;
		for(int i=1;i<=2*n;i++){
			if(a[tb][i]-'0'==id && tot<n){
				pos[++tot]=i;
			}
		}
		int head=0;
		for(int i=1;i<=2*n;i++){
			if(a[ta][i]-'0'==id){
				head++;
				if(head<=n){
					for(int k=pos[head-1]+1;k<pos[head];k++){
						cout<<a[tb][k];
					}
				}
			}
			cout<<a[ta][i];
		}
		for(int i=pos[n]+1;i<=n*2;i++){
			cout<<a[tb][i];
		}
		cout<<'\n';
		for(int i=1;i<=n*2;i++)pos[i]=0;
	}
	
	return 0;
}
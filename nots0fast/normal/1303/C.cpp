#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;




 
void deal(){
	ll t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		map<char, ll> seen;
		ll ind = 0;
		string ans = "";
		ans+=a[0];
		seen[a[0]] = 0;
		
		bool fucked = 0;
		for(ll i =1; i<(ll)a.length(); i++){
			if(seen.find(a[i])!=seen.end()){
				ll dif = fabs(seen[a[i]]-ind);
				if(dif==1){
					ind = seen[a[i]];
				}
				else{
					fucked = 1;
				}
			}
			else{
				if(ind!= (ll)ans.length()-1 && ind!=0){
					fucked = 1;
				}
				else{
					if(ind == 0){
						for(auto& it : seen){
							it.ss++;
						}
					}
					else{
						++ind;
					}
					string z ="";
					z+=a[i];
					ans.insert(ind, z);
					seen[a[i]] = ind;
				}
			}
		}
		for(char f = 'a'; f<='z'; f++){
			if(seen.find(f) == seen.end()){
				ans+=f;
			}
		}
		if(fucked){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			cout<<ans<<'\n';
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
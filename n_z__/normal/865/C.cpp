??=include<bits/stdc++.h>
using namespace std;
??=define eps 1e-10
double dp??(51??)??(5001??);
int a??(51??),b??(51??),p??(51??);
bool bo=false;
void pd(double mid,int r,int n)
??<
	bo=false;
    for(int x=n-1;x>=0;x--)
	??<
        for(int y=r+1;y<5000;y++)
        dp??(x+1??)??(y??)=mid;
        for(int y=0;y<=r;y++)
        dp??(x??)??(y??)=min(mid,(dp??(x+1??)??(y+a??(x??)??)+a??(x??))*p??(x??)/100+(dp??(x+1??)??(y+b??(x??)??)+b??(x??))*(100-p??(x??))/100);
    ??>
    bo=(dp??(0??)??(0??)<mid);
??>
int main()
??<
	auto start=clock();
	int n,r;
    cin>>n>>r;
    for(int x=0;x<n;x++)
    cin>>a??(x??)>>b??(x??)>>p??(x??);
    double le=0,ri=1e10;
    while(10*(clock()-start)/CLOCKS_PER_SEC<=14) 
	??<
        double mid=(le+ri)/2;
        pd(mid,r,n);
        if(bo)ri=mid;
        else le=mid;
    ??>
    printf("%.10f??/n",le);
??>
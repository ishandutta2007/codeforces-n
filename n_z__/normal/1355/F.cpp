#include<bits/stdc++.h>
using namespace std;
#define int long long
const int q[]={2ll*2*2*2*2*2*2*2*2*2*2*3*3*3*3*3*3*3*5*5*5*5*7*7*7*11*11*13*13,
               17ll*17*19*19*23*23*29*29*31*31*37*41,
               43ll*47*53*59*61*67*71*73*79*83,
               89ll*97*101*103*107*109*113*127,
               131ll*137*139*149*151*157*163*167,
               173ll*179*181*191*193*197*199,
               211ll*223*227*229*233*239*241,
               251ll*257*263*269*271*277*281,
               283ll*293*307*311*313*317*331,
               337ll*347*349*353*359*367*373,
               379ll*383*389*397*401*409,
               419ll*421*431*433*439*443,
               449ll*457*461*463*467*479,
               487ll*491*499*503*509*521,
               523ll*541*547*557*563*569,
               571ll*577*587*593*599*601,
               607ll*613*617};
main(){
	int t;
    cin>>t;
    while(t--){
        int a=1;
        for(auto x:q)
        {
            cout<<"? "<<x<<endl;
            int y;
            cin>>y;
            a*=y;
        }
        int ans=1;
        for(int x=2;x<=801;x++){
            int cnt=0;
            while(a%x==0){a/=x,cnt++;}
            ans*=cnt+1;
        }
        cout<<"! "<<max(8ll,ans*2)<<endl;
    }
}
// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/
string s,res;
ll n,i,j,b,row[100001],col[100001];
vector <ll> a={0, 4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086, 1111, 1165};
/*********FUNCTIONS**************/


/***********MAIN**************/

int main(void) 
{
	cin>>n;
	cout<<a[n];
}
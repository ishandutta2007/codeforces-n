/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
**********************************************************************************/

#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
int ar[1000001];
char pp[1000001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>pp;
    a=strlen(pp);
    b=0;
    c=a-1;
    for(x=0;x<a;x++)
    {
        if(pp[x]=='l'){ar[c]=x+1;c--;}
        else {ar[b]=x+1;b++;};
    }
    for(x=0;x<a;x++)cout<<ar[x]<<endl;
}
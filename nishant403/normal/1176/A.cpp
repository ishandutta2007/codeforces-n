/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>

class ADivideIt {
public:
	void solve(std::istream& in, std::ostream& out) {
   int q;
   in >> q;

   while(q--)
   {
      long long  int n;
       in >> n;

       int x = 0;

       while(n!=1)
       {
           x++;

       if(n%2==0) n/=2;
       else if(n%3==0) { n/=3; n*=2; }
       else if(n%5==0) { n/=5; n*=4; }
       else {out << -1 << "\n";  break;}

       }

       if(n==1) out << x << "\n";


   }


	}
};


int main() {
	ADivideIt solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
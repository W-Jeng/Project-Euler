#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<math.h>
#include<algorithm>

using namespace std;

void solve();
int curious(int a, int b);
int gcd(int a, int b);
bool double_equals(double a, double b, double epsilon);
int main() {
   solve();
   return 0;
}

void solve() {
   int n_product = 1;
   int d_product = 1;
   for (int i = 10; i<100; i++) {
      for (int j = i+1; j<100; j++) {
         // j is the denominator
         if (curious(i,j)> 0) {
            n_product = n_product*i;
            d_product = d_product*j;
         }
      }
   }
   cout << "the product of digit cancelling fractions denominator: " << d_product/gcd(n_product, d_product) << endl;
}

int curious(int a, int b) {
   int x1 = a/10; //the second digit
   int x2 = a % 10; // the first digit
   int y1 = b/10;
   int y2 = b % 10;
   double cur_div = 0;
   int gcd_div;
   
   if (x1 == y1 && x1 !=0 && y2 != 0) {
      cur_div = x2/(1.0*y2);
      gcd_div = y2/gcd(x2, y2);
   } else if (x1 == y2 && x1 != 0 && y1 != 0) {
      cur_div = x2/(1.0*y1);
      gcd_div = y1/gcd(x2, y1);
   } else if (x2 == y1 && x2 != 0 && y2 != 0) {
      cur_div = x1/(1.0*y2);
      gcd_div = y2/gcd(x1, y2);
   } else if (x2 == y2 && x2 != 0 && y1 != 0) {
      cur_div == x1/(1.0*y1);
      gcd_div = y1/gcd(x1,y1);
   }
   if (double_equals(cur_div,  a/(1.0 * b), 0.001)) {
      cout << "a is " << a << ", b is " << b << endl;
      return gcd_div;
   } else 
      return 0;
   return 0;
}

int gcd(int a, int b) {
   if (b==0) return a;
   else return gcd(b, a%b);
}

bool double_equals(double a, double b, double epsilon)
{
    return std::abs(a - b) < epsilon;
}

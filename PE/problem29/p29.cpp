#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<chrono>
#include<numeric>
#include<unordered_map>
#include<map>

using namespace std;
void solve(map<double, int>& val, int a_min, int a_max, int b_min, int b_max);
int main() {
   map<double, int> val;
   int a_min = 2;
   int a_max = 100;
   int b_min = 2;
   int b_max = 100;
   int counter = 2;
   solve(val, a_min, a_max, b_min, b_max);
   cout << "the numbers generated are: " << val.size() << endl;
   return 0;
}

void solve(map<double, int> & val, int a_min, int a_max, int b_min, int b_max) {
   for (int i = a_min; i<= a_max; i++) {
      for (int j = b_min; j<=b_max; j++) {
         //putting this because of precision issue
         double rounded =ceil(((j*1.0)*log(i*1.0))*10000000.0)/10000000.0;
         val[(rounded)]++;
      }
   }
   return;
}

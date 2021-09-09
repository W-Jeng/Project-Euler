#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<numeric>
#include<vector>

using namespace std;



int main() {
   int max_num = 1000000;
   set<int, int> primes;
   int counter = 0;
   int digits = 1;
   for (int i = 2; i<max_num; i++) {
      if (i > pow(10,digits))
         digits++;
      if (check_prime(i, primes)) {
         for (int i = 0; i<digits; i++) { 
            
         } 
      }     
   }
   return 0;
}

bool check_prime(int a, set<int, int> primes) {
   int max_num = sqrt(a);
   iterator it = primes.find(a);
   if (it == primes.end())
      return true;
   
   for (auto it2 :primes) {
      if (primes.first>max_num)
         break;
      if (a % primes.first == 0) {
         return false;
      }
   }
   return true;
}

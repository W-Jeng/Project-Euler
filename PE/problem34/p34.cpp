#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<numeric>

using namespace std;

int factorial(int a);

int main() {
   vector<int> fact(10,0);
   int max_bound = 10000000;
   int sum = 0;
   int num;
   int cur_sum;
   for (int i = 0; i<10; i++) {
      fact[i] = factorial(i);
   }
   for (int i = 3; i<max_bound; i++) {
      num = i;
      cur_sum = 0;
      while (num != 0) {
         cur_sum += fact[num%10];
         num = num/10;
      }
      if (cur_sum == i) { 
         sum += i;
         cout << "curious: " << i << endl;
      }   
   }
   cout << "the sum is " << sum << endl;

   return 0;
}

int factorial(int a) {
   int prod = 1;
   if (a == 0) 
      return 1;
   while (a > 0) {
      prod = prod*a;
      a--;
   }
   return prod;
}

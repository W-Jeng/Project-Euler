#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include<iterator>
#include<string>
#include<unordered_map>
using namespace std;

bool nine(int i, int j, int sum);

int main() {
   int sum = 0;
   int cur_val; 
   unordered_map<int, int> prod_sum;
   //cout << nine(38, 186, 7254);
   
   for (int i = 1; i<10; i++) {
      for (int j = 99; j<10000; j++) {
         cur_val = i*j;
         if (nine(i, j ,cur_val)) {
            prod_sum[cur_val]++;
         }
         //cout << "cur i: " << i << endl;
      }
   }
   for (int i = 10; i<99; i++) {
      for (int j = 99; j<1000; j++) {
         cur_val = i*j;
         if (nine(i, j ,cur_val)) {
            prod_sum[cur_val]++;
         }
         //cout << "cur i: " << i << endl;
      }
   }
   for (auto it:prod_sum) {
      sum+= it.first;
   }
   cout << "the numbers are: " << sum << endl;
   return 0;
}

bool nine(int i, int j, int sum) {
   int digits = 0;
   int pre_i = i;
   int pre_j = j;
   int pre_sum = sum;
   string digit_keep = "";
   vector<int> placement(9,0);
   while (i != 0) {
      digits++;
      digit_keep += to_string(i % 10);
      i = i/10;
   }
   while (j != 0) {
      digits++;
      digit_keep += to_string(j % 10);
      j = j/10;
   }
   while (sum != 0) {
      digits++;
      digit_keep += to_string(sum % 10);
      sum = sum/10;
   }
   if (digits == 9) {
      for (int i = 0; i<digit_keep.size(); i++) {
         placement[digit_keep[i] -'0' - 1]++;
      }
      for (int i = 0; i<placement.size(); i++) {
         if (placement[i] != 1)
            return false;
      }
      cout << "i is " << pre_i << ", j is " << pre_j << ", sum is " << pre_sum << endl;
      return true;
   }
   return false;
}

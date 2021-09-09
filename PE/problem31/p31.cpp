#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<numeric>
#include<iterator>
#include<fstream>
#include<string>
using namespace std;


void recur(int max_val, int cur_val, int & num_way, int index, vector<int> combin);

int main() {
   int max_val = 200;
   int cur_val = 0;
   int num_way = 0;
   int index = 0;
   vector<int> combin {1, 2, 5, 10, 20, 50, 100, 200};
         
   recur(max_val, cur_val, num_way, index, combin);            
   cout << "the num of way is num_way: " << num_way; 
   return 0;
}

void recur(int max_val, int cur_val, int & num_way, int index, vector<int> combin) {
   if (cur_val == max_val) {
      num_way++;
      return;
   } else if (cur_val > max_val) {
      return;
   }
   for (int i = index; i < combin.size(); i++) {
      cur_val += combin[i];
      recur(max_val, cur_val, num_way, i, combin);
      cur_val -= combin[i];
   }
   return;
}

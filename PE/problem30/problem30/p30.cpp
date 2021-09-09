#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<numeric>
#include <iterator>
#include <fstream>
#include<string>

using namespace std;
void solve();

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}

void solve() {
	vector<int> store;
	int digit = 0;
	for (int i = 10; i < 500000; i++) {
		int left_sum = 0;
		int right_sum = i;
		int num_right = i;
		while (num_right != 0) {
			int saved = num_right;
			num_right = num_right / 10;
			digit = saved - num_right * 10;
			left_sum = left_sum + pow(digit, 5);
		}
		if (left_sum == right_sum) {
			store.push_back(right_sum);
			cout << "This is the equal you are looking for " << right_sum << endl;
		}
	}
	cout << "sum of the fifth power is " << accumulate(store.begin(), store.end(), 0) << endl;
	return ;
}

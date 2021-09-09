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
bool abundant(int x);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}
bool abundant(int x) {
	int sum = 1;
	int div;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			div = x / i;
			if (div == i) {
				sum += div;
			}
			else {
				sum += div + i;
			}
		}
	}
	if (sum > x)
		return true;
	else
		return false;
}

void solve() {
	vector<int> data;
	for (int i = 1; i <= 28123; i++) {
		if (abundant(i)) {
			data.push_back(i);
			//cout << i << endl;
		}
	}
	long long int sum = 0;
	bool found;
	for (int k = 1; k <= 28183; k++) {
		found = 0;
		for (int j = 0; j < data.size(); j++) {
			int gap = k - data[j];
			if (gap > 0) {
				auto it = find(data.begin(), data.end(), gap);
				if (it != data.end()) {
					found = 1;
					break;
				}
			}	
		}
		if (found == 0) {
			//cout << "cannot at " << k << endl;
			sum += (long long int) k;
		}
	}
	cout << "The sums are " << sum << endl;
	return;
}
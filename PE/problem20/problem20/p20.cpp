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
	vector<int> digits;
	int aim = 100;
	digits.push_back(1);
	int bring_over = 0;
	int remainder;
	for (int i = 1; i < aim; i++) {
		int size = digits.size();
		int mult = i + 1;
		for (int j = 0; j < size; j++) {
			digits[j] = bring_over + digits[j] * mult;
			bring_over = digits[j]/10;
			digits[j] = digits[j] % 10;
		}
		while (bring_over != 0) {
			digits.push_back(bring_over % 10);
			bring_over = bring_over / 10;
		}
		//print out
		/*
		for (int k = digits.size()-1; k >=0; k--) {
			cout << digits[k];
		}
		cout << endl;
		*/
	}
	cout << "The accumulations are " << accumulate(digits.begin(), digits.end(), 0) << endl;
	return;
}
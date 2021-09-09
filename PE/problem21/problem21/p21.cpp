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
int sumOfDivisor(int x);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}
int sumOfDivisor(int x) {
	int sum = 1;
	for (int i = 2; i * i < x; i++) {
		if (x % i == 0) {
			sum += i + x / i;
		}
	}
	return sum;
}
void solve() {
	int aim = 10000;
	int sum = 0;
	set<int> pair;
	for (int i = 2; i < aim; i++) {
		auto it = pair.find(i);
		if (it == pair.end()) {
			int temp = sumOfDivisor(i);
			if (temp != i && i == sumOfDivisor(temp) && temp < aim) {
				pair.insert(i);
				pair.insert(temp);
				cout << "the pairs are " << i << " and " << temp << endl;
			}
		}
	}
	for (auto it2 = pair.begin(); it2 != pair.end(); it2++) {
		sum += *it2;
	}
	cout << "The sums are " << sum << endl;
	return;
}
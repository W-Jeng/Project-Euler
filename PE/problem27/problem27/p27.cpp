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
bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			//cout << "the i is " << i << endl;
			return false;
		}
	}
	return true;
}

int primestreak(int a, int b) {
	int n = 0;
	while (true) {
		int poly = n*n + a * n + b;
		if (poly <= 0)
			return n;
		//cout << poly << endl;
		//cout << "n is " << n << endl;
		if (!prime(poly))
			return n;
		n++;
		
	}
}

void solve() {
	int max_streak = 0;
	int max_a;
	int max_b;
	int streak;
	
	for (int a = -999; a < 1000; a++) {
		for (int b = -1000; b <= 1000; b++) {
			streak = primestreak(a, b);
			if (streak > max_streak) {
				max_streak = streak;
				max_a = a;
				max_b = b;
			}
			//cout << "ab is " << a << ", " << b << " and the streak is " << streak << endl;
		}
	}
	
	cout << "The mult is " << max_a * max_b << endl;

	//cout << primestreak(1, 41) << endl;
	return;
}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
#include<unordered_set>
#include<set>

using namespace std;
void solve();
bool isPrime(int num);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}

void solve() {
	long long int ans=2;
	for (int i = 3; i < 2000000; i++) {
		if (isPrime(i)) {
			ans += (long long int) i;
		}
	}
	cout << "the ans is " << ans << endl;
	return;
}

bool isPrime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if ((num % i) == 0) return false;
	}
	return num > 1;
}
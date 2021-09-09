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
bool isPrime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if ((num % i) == 0) return false;
	}
	return num > 1;
}


void solve() {
	int i = 2;
	for (int primes = 0; ; ++i) {
		if (isPrime(i)) {
			if (++primes == 10001) {
				std::cout << i << "\n";
				break;
			}
		}
	}
	return;
}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>

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
	long long int N = 600851475143;
	long long int div = 2;
	long long int last_div = div;
	while (div < sqrt(N)+1) {
		while (N % div == 0) {
			N = N / div;
			last_div = div;
			cout << "The current N is " << N << endl;
		}
		div++;
	}
	cout << "the greatest prime factorisation is " << last_div << " or " << N << endl;
	return;
}
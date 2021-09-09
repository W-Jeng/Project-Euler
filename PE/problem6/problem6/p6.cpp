#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>

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
	long long int square_sum = 0;
	long long int sum_square = 0;
	for (int i = 1; i <= 100; i++) {
		sum_square += i * i;
	}
	for (int j = 1; j <= 100; j++) {
		square_sum += j;
	}
	cout << "the difference is " << square_sum * square_sum - sum_square << endl;
	return;
}
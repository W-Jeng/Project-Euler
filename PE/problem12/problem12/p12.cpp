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
int divisor(long long int x);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}
int divisor(long long int x) {
	int count = 0;
	for (long long int i = 1; i*i <= x; i++) {
		if (x % i == 0)
			count+=2;
	}
	return count;
}

void solve() {
	long long int triangle_num = 1;
	long long int counter = 2;
	while (divisor(triangle_num) <= 500) {
		triangle_num += counter;
		counter++;
	}
	cout << "the number is " << triangle_num << " with " << divisor(triangle_num) << endl;
	return;
}
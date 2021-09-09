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
	int condition = 0;
	int num = 5000;
	while (!condition) {
		num++;
		for (int i = 2; i < 21; i++) {
			if (num % i != 0) {
				break;
			}
			if (num % i == 0 && i == 20) {
				condition = 1;
			}
		}
	}
	cout << "the smallest positive number is " << num << endl;
	return;
}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;
void solve();
bool palin(int x);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}

void solve() {
	int max_num=100000;
	for (int i = 100; i < 1000; i++) {
		for (int j = i; j < 1000; j++) {
			if (palin(i * j)) {
				max_num = max(max_num, i * j);
			}
		}
	}
	cout << "the answer is " << max_num << endl;
	return;
}
bool palin(int x) {
	int cur = 0;
	int ori = x;
	while (x != 0) {
		int temp = x - (x / 10) * 10;
		cur = cur * 10;
		cur += temp;
		x = x / 10;
	}
	if (ori == cur)
		return true;
	else
		return false;
}

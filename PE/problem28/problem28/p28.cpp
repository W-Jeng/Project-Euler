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
	int cur = 2;
	int spacing = 2;
	int sum = 1;
	while (spacing+1 <= 1001) {
		for (int j = 0; j < 4; j++) {
			if (j == 0)
				cur += spacing - 1;
			else
				cur += spacing;

			sum += cur;
		}
		cur++;
		spacing += 2;
	}
	cout << "sum of diagonal " << sum << endl;
	return;
}
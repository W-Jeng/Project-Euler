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

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}

void solve() {
	int target = 0;
	double ans;
	int aa;
	int bb;
	int cc;
	bool con = false;
	for (int a = 0; a < 999; a++) {
		for (int b = a+1; b < 1000; b++) {
			for (int c = b + 1; c <= 1000; c++) {
				if ((a * a + b * b == c * c) && a + b + c == 1000) {
					aa = a;
					bb = b;
					cc = c;
					con = true;
					break;
				}
			}
			if (con)
				break;
		}
		if (con)
			break;
	}
	cout << "the product is " << aa * bb * cc << endl;
	return;
}
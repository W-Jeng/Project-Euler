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
	//we take down 2, 4, 8 first
	vector<int> two;
	vector<int> four;
	vector<int> eight;
	vector<int> three;
	vector<int> fi
	for (int i = 2; i < 100; i++) {
		two.push_back(i);
		four.push_back(2*i);
		eight.push_back(3 * i);
	}
	return;
}
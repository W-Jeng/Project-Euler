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
	vector<int> prev;
	vector<int> cur;
	vector<int> temp;
	prev.push_back(1);
	cur.push_back(1);
	int take_over = 0;
	int counter = 2;
	while (cur.size() < 1000) {
		temp = cur;
		counter++;
		for (int i = 0; i < cur.size(); i++) {
			if (prev.size() <= i)
				cur[i] += take_over;
			else
				cur[i] += take_over + prev[i];
			take_over = 0;
			if (cur[i] >= 10) {
				take_over = 1;
				cur[i] = cur[i] % 10;
			}
		}
		if (take_over == 1) {
			cur.push_back(1);
			take_over = 0;
		}
		prev = temp;
		/*
		for (int k = cur.size()-1; k >= 0; k--) {
			cout << cur[k];
		}
		cout << " with size " << cur.size() << endl;
		*/
	}
	cout << "the first term of 1000 digits is " << counter << endl;
	return;
}
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
	ifstream data;
	data.open("p067_triangle.txt");
	vector<vector<int>> triangle;
	int cur;
	vector<string> row;
	while (!data.eof()) {
		for (int i = 0; i < 100; i++) {
			vector<int> tmpVec;
			string tmpString;
				for (int j = 0; j < i+1; j++) {
					data >> tmpString;
					cur = stoi(tmpString);
					tmpVec.push_back(cur);
				}
			triangle.push_back(tmpVec);
		}
	}
	/*
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	cout << triangle.size() << endl;
	*/
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	cout << "the maximum path way sum is " << triangle[0][0] << endl;
	
	return;
}
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
	long long int iterator = 2;
	int max_chain = 0;
	int cur_chain = 0;
	long long int cur_num=iterator;
	int record;
	vector<long long int> hist;
	hist.resize(1000001);
	while (iterator < 1000000) {
		if (cur_num % 2 == 0) {
			cur_num = cur_num / 2;
			cur_chain++;
		}
		else {
			cur_num = (3 * cur_num + 1) / 2;
			cur_chain += 2;
		}
		if (cur_num < iterator) {
			cur_chain += hist[cur_num];
			cur_num = 1;
		}
		if (cur_num == 1) {
			if (cur_chain > max_chain) {
				max_chain = cur_chain;
				record = iterator;
			}
			hist[iterator]=cur_chain;
			//cout << "the current iterator is " << iterator << " cur chain is " << cur_chain << endl;
			cur_chain = 0;
			iterator++;
			cur_num = iterator;
			
		}
	}
	cout << "The number with max chain is " << record << " with max chain " << max_chain << endl;
	return;
}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<numeric>
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
	vector<int> digits;
	digits.push_back(1);
	int bring_over=0;
	int pow = 1000;
	for (int i = 0; i < pow; i++) {
		int fix_size = digits.size();
		for (int k = 0; k < fix_size; k++) {
			digits[k] = bring_over + digits[k] * 2;
			if (bring_over == 1)
				bring_over = 0;
			if (digits[k] >= 10) {
				digits[k] = digits[k] % 10;
				bring_over = 1;
			}
			//cout << digits[k] << " ";
			if (k == fix_size - 1 && bring_over == 1) {
				digits.push_back(1);
				//cout << digits[k+1] << " ";
				bring_over = 0;
			}
			
		}
		//cout << "-------"<<endl;
	}
	int sum = accumulate(digits.begin(), digits.end(),0);
	cout << "the ans is " << sum << endl;
	return;
}
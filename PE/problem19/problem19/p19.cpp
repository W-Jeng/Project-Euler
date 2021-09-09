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
bool leap(int x);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	return 0;
}
bool leap(int x) {
	if (x % 4 == 0) {
		if (x % 400 == 0)
			return true;
		else if (x % 100 == 0)
			return false;
		else
			return true;
	}
	return false;
}

void solve() {
    int count = 0, days_in_month, days_passed = 2;

    for (int i = 1901; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (j == 4 || j == 6 || j == 9 || j == 11) {
                days_in_month = 30;
            }
            else if (j == 2) {
                if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
                    days_in_month = 29;
                }
                else {
                    days_in_month = 28;
                }
            }
            else {
                days_in_month = 31;
            }
            if (days_passed % 7 == 0) {
                count++;
            }
            days_passed += days_in_month;
        }
    }

    cout << count << endl;
	return;
}
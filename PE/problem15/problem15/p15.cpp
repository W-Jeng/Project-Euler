#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<chrono>
#include<algorithm>
#include<unordered_set>
#include<set>
#include<iomanip>

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
	//137846528820
	//find out the nCr formula, set 40C20
	double ans = 1;
	int N = 40;
	int R = 20;
	for (int i = R; i > 0; i--) {
		ans *=  ((double) i+20)/ (double) i;
		cout << ans << endl;
	}
	
	cout << "the number of ways are " << setprecision(15) << ans << endl;
	return;
}
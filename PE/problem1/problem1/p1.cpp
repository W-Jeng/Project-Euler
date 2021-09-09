#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
void solve();

int main() {
	solve();
	return 0;
}

void solve() {
	int multiplier = 1;
	int sum = 0;
	while (multiplier * 3 < 1000) {
		sum += multiplier *3;
		multiplier++;
	}
	multiplier = 1;
	while (multiplier*5 < 1000) {
		sum += multiplier * 5;
		multiplier++;
	}
	multiplier = 1;
	while (multiplier * 15 < 1000) {
		sum -= multiplier * 15;
		multiplier++;
	}
	cout << "the sum is " << sum << endl;

	return;
}
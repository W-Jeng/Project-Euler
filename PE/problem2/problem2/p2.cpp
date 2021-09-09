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
	int num = 2;
	int prev = 1;
	int sum = 0;
	while (num < 4000000) {
		if (num % 2 == 0)
			sum += num;
		int temp = num;
		num += prev;
		prev = temp;
	}
	cout << "the sum is " << sum << endl;
	return;
}
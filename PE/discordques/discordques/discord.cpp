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
#include<time.h>
#include<random>
using namespace std;
void solve();
double FrozenMagic(int magicPower, char magicUser);

int main() {
	auto t1 = std::chrono::high_resolution_clock::now();
	solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << " seconds" << endl;
	cout << FrozenMagic(2, 'E') << endl;
	return 0;
}

void solve() {

	return;
}
double FrozenMagic(int magicPower, char magicUser) {
	magicPower = abs(magicPower);
	double damageModifier;
	double totalMagicPower;
	srand(time(NULL));
	
	if (magicUser == 'E') {
		damageModifier = 0.5 + ((double) (rand()%10)/10) * 3.5;
	}
	else if (magicUser == 'A') {
		damageModifier = 1.5;
	}
	else if (magicUser == 'O') {
		damageModifier = 1.0;
	}
	cout << damageModifier << endl;
	totalMagicPower = damageModifier * (double) magicPower;
	return totalMagicPower;
}
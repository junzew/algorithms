#include <iostream>
using namespace std;
/*
Problem
Assuming an unlimited supply of quarters (25 cents), dimes (10 cents),
nickels (5 cents), and pennies (1 cent), give a greedy algorithm to 
make change for n ≥ 0 cents using the smallest total number of coins
http://blogs.ubc.ca/cpsc3202016w2/files/2017/02/2017-03-01-dp-change-part1-sample-soln.pdf
*/
int solve(int n) {
	// greedy strategy:
	// use coins of large values first
	int V[6] = {25, 10, 5, 1};
	int ans = 0;
	for (int i = 0; i <= 3; i++) {
		int t;
		ans += (t = n / V[i]);
		n -= t* V[i];
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	cout << solve(n) << endl;
	/*
	Test cases: 
	2: 2 coins (2 pennies)
  	4: 4 coins (4 pennies)
  	6: 2 coins (1 nickel, 1 penny)
  	16: 3 coins (1 dime, 1 nickel, and 1 penny)
  	33: 5 coins (1 quarter, 1 dime, and 3 pennies)
  	142: 9 coins (5 quarters, 1 dime, 1 nickel, 2 pennies)
	*/
	return 0;
}
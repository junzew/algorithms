#include <iostream>
#include <list>
#include <cstring>
using namespace std;
/*
Stable Matching Problem, Gale-Shapley

Compile:
g++ -std=c++11 stable_matching.cpp -o stable_matching

Input Format:
The first line contains a single number n, the total number of people.
It is followed by 2n lines of preference lists.
The first n lines are men's preference lists, 
and the next n lines are women's preference lists.

Sample Input: 
3      
2 0 1  
2 1 0  
1 0 2  
1 0 2  
0 1 2  
1 0 2 

Explanation of Input: 
3     <- n = 3
2 0 1 <- man 0's preference list
2 1 0 <- man 1's preference list
1 0 2 <- man 2's preference list
1 0 2 <- woman 0's preference list
0 1 2 <- woman 1's preference list
1 0 2 <- woman 2's preference list

Solution:
(m0, w0)
(m2, w1)
(m1, w2)

Note: 
Use 0-based indexing.
Men proposes in this implementation.
The sample instance above is adapted from part 1.2 in the solution handout.
http://blogs.ubc.ca/cpsc3202016w2/files/2017/01/2016-01-04-notes-smp-intro-sample-soln.pdf
*/
int main() {
	int n; // number of people 
	cin >> n;
	int ManPref[n][n]; // Manpref[m] is the preference list of man m
	int WomanPref[n][n]; // WomanPref[w] is the preference list of woman w
	int Ranking[n][n]; // Ranking[w][m] is position of m on w's preference list
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ManPref[i][j]; // read man preference lists
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> WomanPref[i][j]; // read man preference lists
			Ranking[i][WomanPref[i][j]] = j; // create inverse mapping
		}
	}
	int Current[n]; // Current[w] is w's current partner
	int Next[n]; // contains position of the next woman to propose for m
	for (int i = 0; i < n; i++) {
		Current[i] = -1; // initialize current partner to null for all women
	}
	for (int i = 0; i < n; i++) {
		Next[i] = 0; // initialize to 0 (first woman) for all men
	}
	list<int> Free; // list of free men
	for (int i = 0; i < n; i++) {
		Free.push_back(i); // All men are free at the begining
	}

	// Gale-Shapley Algorithm
	while(!Free.empty()) {
		// select a man m
		int m = Free.front(); Free.pop_front();
		// propose to the next woman on m's list and update Next
		int w = ManPref[m][Next[m]++];
		cout << "m" << m << " proposes to w" << w << endl;
		if (Current[w] == -1) {
			cout << "w" << w <<" is unengaged" << endl;
			cout << "engage m" << m << " to w" << w << endl;
			// if w is unengaged then engage m to w
			Current[w] = m;
		} else if (Ranking[w][m] < Ranking[w][Current[w]]) {
			// w preferes m to current partner
			cout << "w" << w << " prefers m" << m << " to m" <<Current[w] << endl;
			Free.push_back(Current[w]); // the current partner becomes free
			Current[w] = m;
		}
	}

	cout << "Solution: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "(m" << Current[i] << ", w" << i << ")" << endl;
	}

	return 0;
}
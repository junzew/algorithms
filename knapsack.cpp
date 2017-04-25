#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Knapsack Problem
// http://www.spoj.com/problems/KNAPSACK/
class Item {
public:
	int weight;
	double value;
	Item(int w, int v);
	~Item() {}
};
Item::Item(int w, int v) {
	weight = w;
	value = v;
}
double solve(int N, int W, vector<Item*> items) {
	double M[N+1][W+1];
	for (int j = 0; j <= W; j++) {
		M[0][j] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			int vi = items[i-1]->value;
			int wi = items[i-1]->weight;
			if (w - wi >= 0) {
				M[i][w] = max(M[i-1][w], vi+M[i-1][w - wi]);	
			} else {
				M[i][w] = M[i-1][w];
			}
		}
	}
	return M[N][W];
}
int main() {
	int N, W; // number of items, total weight of knapsack
	cin >> W >> N;
	vector<Item*> items(N);
	for (int i = 0; i < N; i++) {
		int w, v; // weight and value of item i
		cin >> w >> v;
		items[i] = new Item(w, v);
	}
	cout << solve(N, W, items) << endl;
	for (int i = 0; i < N; i++) {
		delete items[i];
	}
	return 0;
}
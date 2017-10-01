public class QuickUnion implements UnionFind {
	
	private int[] parent;
	private int count;

	public QuickUnion(int N) {
		parent = new int[N];
		count = N;
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
	}

	// p and q are in the same component iff they have the same root
	public boolean connected(int p, int q) {
		return find(p) == find(q);
	}

	// Union p and q
	public void union(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ) return;
		parent[rootP] = rootQ;
		count--;
	}

	// Returns the number of connected components
	public int count() {
		return count;
	}

	// Find root of p
	public int find(int p) {
		if (p == parent[p]) return p;
		return find(parent[p]);
		// Iterative version:
		// while(p != parent[p]) {
		// 	p = parent[p];
		// }
		// return p;
	}
}
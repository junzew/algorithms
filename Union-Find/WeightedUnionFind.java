public class WeightedUnionFind implements UnionFind {

	private int[] parent;
	private int[] size;
	private int count;
	public WeightedUnionFind(int N) {
		parent = new int[N];
		size = new int[N];
		count = N;
		// Initially each belongs to different components
		for (int i = 0; i < N; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	public boolean connected(int p, int q) {
		return find(p) == find(q);
	}

	/**
 	* Rather than arbitrarily connecting the second tree to the 
 	* first for union() in the quick-union algorithm, 
 	* we keep track of the size of each tree and always connect 
 	* the smaller tree to the larger.
	*/
	public void union(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ) return;
		if (size[rootP] > size[rootQ]) {
			parent[rootQ] = rootP;
			size[rootP] += size[rootQ];
		} else {
			parent[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}
		count--;
	}

	public int count() {
		return count;
	}

	public int find(int p) {
		while(p != parent[p]) {
			p = parent[p];
		}
		return p;
	}
}
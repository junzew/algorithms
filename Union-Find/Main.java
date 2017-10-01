public class Main {
	/**
	* Components
	* {1,2,7,8,9} {0,5,6} {3,4}
	*/
	public static void main(String[] args) {
		// UnionFind uf = new QuickUnion(10);
		// UnionFind uf = new QuickFind(10);
		UnionFind uf = new WeightedUnionFind(10);
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				assert !uf.connected(i, j);
			}
		}
		uf.union(1,2);
		uf.union(3,4);
		uf.union(5,6);
		assert uf.connected(1,2);
		assert uf.connected(3,4);
		assert uf.connected(5,6);
		assert !uf.connected(1,3);
		assert !uf.connected(2,6);
		uf.union(7,8);
		uf.union(7,9);
		assert uf.connected(7,9);
		uf.union(2,8);
		assert uf.connected(7,1);
		assert uf.connected(2,9);
		assert !uf.connected(5,3);
		assert !uf.connected(2,4);
		assert !uf.connected(7,0);
	}

}
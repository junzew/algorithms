public interface UnionFind {
	// Returns true if the p and q are connected
	boolean connected(int p, int q);
	// Union p and q
	void union(int p, int q);
	// Returns the number of connected components
	int count();
	// Find identifier of p
	int find(int p);
}
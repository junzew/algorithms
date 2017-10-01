public class QuickFind implements UnionFind {

	private int[] id;
	private int count;
	public QuickFind(int n) {
		id = new int[n];
		count = n;
		// Initially each belongs to different components
		for (int i = 0; i < n; i++) {
			id[i] = i;
		}
	}

	public boolean connected(int p, int q) {
		// Invariant: p and q are connected iff id[p] == id[q]
		return id[p] == id[q];
	}

	public void union(int p, int q) {
		// Connect p and q
		int pid = find(p);
		int qid = find(q);
		if (pid == qid) return; // already connected
		for (int i = 0; i < id.length; i++) {
			if (id[i] == pid) {
				id[i] = qid;
			}
		}
		count--;
	}

	public int count() {
		return count;
	}

	public int find(int p) {
		return id[p];
	}
}
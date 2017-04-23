// Author: Junze Wu
// Date: 2017.2.22
#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
/**
* Sample input:
6
0 5 2
1 7 4
6 8 4
3 9 7
8 10 2
8 11 1
*/
typedef struct {
	int s; // start time
	int f; // finish time
	int w; // weight
} request;

// comparator for sorting intervals by finish time
int cmp(const void* a, const void* b) {
	request* r1 = (request*) a;
	request* r2 = (request*) b;
	return r1->f - r2->f; // sort by increasing finish time
}

// compute p[j] for each interval j
void compute_p(request r[], int n, int p[]) {
	int i, j;
	for (j = 1; j <= n; j++) {
		for (i = j - 1; i > 0; i--) {
			if (r[i].f <= r[j].s) {
				p[j] = i;
				break;
			}
		}
	}
}

// Compute optimal max weight
int compute_opt(int j, request r[], int p[]) {
	if (j == 0) return 0;
	return max(r[j].w + compute_opt(p[j], r, p), compute_opt(j-1, r, p));
}

// Compute optimal max weight (memoization)
int m_compute_opt(int j, request r[], int p[], int M[]) {
	if (j == 0) return 0;
	if (M[j] != -1) return M[j];
	M[j] = max(r[j].w + m_compute_opt(p[j], r, p, M), m_compute_opt(j-1, r, p, M));
	return M[j];
}

// Find the optimal set of intervals
void find_solution(int j, request r[], int p[], int M[]) {
	if (j == 0) return;
	if (r[j].w + M[p[j]] >= M[j-1]) {
		printf("%d\n", j);
		find_solution(p[j], r, p, M);
	} else {
		find_solution(j-1, r, p , M);
	}
}

// Dynamic programming solution
void bottom_up_dp(int n, request r[], int p[], int M[]) {
	int j;
	for (j = 1; j <= n; j++) {
		M[j] = max(r[j].w + M[p[j]] ,M[j-1] );
	}
}

int main() {
	int n; // number of requests
	scanf("%d", &n);
	request r[n+1]; // requests (one-based indexing)
	r[0].s = 0; r[0].f = 0; r[0].w = 0;
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &(r[i].s), &(r[i].f), &(r[i].w));
	}
	// sort requests by finish time increasingly
	qsort(r, n+1, sizeof(request), cmp);
	for (i = 1; i <= n; i++) {
		printf("Index: %d s: %d f: %d w: %d\n", i, r[i].s, r[i].f, r[i].w);
	}
	// For interval j, p[j] is the largest index i < j such that intervals i and j are disjoint
	// i is the leftmost interval that ends before j begins. We define p(j) = 0 if no
	// request i < j is disjoint from j.
	int p[n]; 
	for (i = 1; i <= n; i++) {
		p[i] = 0;
	}
	compute_p(r, n, p);
	for (i = 1; i <= n; i++) {
		printf("p [%d] = %d\n",i ,p[i]);
	}
	int opt = compute_opt(n, r, p);
	printf("opt: %d\n", opt);

	printf("Memoization:\n");
	int M[n+1];
	for (i = 1; i <= n ;i++) {
		M[i] = -1;
	}
	opt = m_compute_opt(n, r, p, M);
	for (i = 1; i <= n ;i++) {
		printf("M[%d] = %d\n",i ,M[i]);
	}
	printf("m opt: %d\n", opt);	
	printf("Solution consists of intervals at indices:\n");
	find_solution(n, r, p, M);

	printf("bottom_up_dp\n");
	for (i = 1; i <= n ;i++) {
		M[i] = -1;
	}
	bottom_up_dp(n, r, p, M);
	printf("%d\n", M[n]);
	return 0;
}
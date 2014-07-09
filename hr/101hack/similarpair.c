#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#define MAXN 100000

struct edge {
	int p;
	int c;
};

int ecomp(const void* p1, const void* p2) {
	struct edge* e1 = (struct edge*)p1;
	struct edge* e2 = (struct edge*)p2;
	return e1->p - e2->p;
}

struct edge child[MAXN+1];
int lookup[MAXN+1];

int N, T;
int nonroot[MAXN+1];
int nchild[MAXN+1];
uint64_t ST[4*(MAXN+1)];

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void update(int n, int lb, int le, int idx, int inc) {
	if (lb > n || le < n) return;
	if (lb == le) {
		ST[idx] += inc;
		return;
	}

	int mid = (lb + le)/2;
	update(n, lb, mid, 2*idx, inc);
	update(n, mid+1, le, 2*idx+1, inc);

	ST[idx] = ST[2*idx] + ST[2*idx+1];
}

uint64_t qry(int lb, int le, int qb, int qe, int idx) {
	if (lb > qe || le < qb) return 0;
	if (lb <= qb && le >= qe) return ST[idx];
	int mid = (qe + qb)/2;
	return qry(lb, le, qb, mid, 2*idx) + qry(lb, le, mid+1, qe, 2*idx+1);
}

uint64_t sp(int nd) {
	int i, chld_start;
	int qb = max(1, nd - T);
	int qe = min(nd + T, N);
	uint64_t res = qry(qb, qe, 1, N, 1);

	update(nd, 1, N, 1, 1);

	chld_start = lookup[nd];
	for (int i = 0; i < nchild[nd]; ++i) {
		res += sp(child[chld_start+i].c);
	}
	update(nd, 1, N, 1, -1);

	return res;
}

int main() {
	int i, tmp;
	scanf("%d %d", &N, &T);

	for (i = 0; i < N-1; ++i) {
		int p, c;
		scanf("%d %d", &p, &c);
		nonroot[c] = 1;
		child[i].p = p;
		child[i].c = c;
		nchild[p]++;
	}

	qsort(child, N-1, sizeof(struct edge), ecomp);

	tmp = 0;
	for (i = 0; i < N; ++i) {
		if (tmp < child[i].p) {
			tmp = child[i].p;
			lookup[child[i].p] = i;
		}
	}

	for (i = 1; i < N; ++i) {
		if (!nonroot[i]) break;
	}
	printf("%" PRIu64 "\n", sp(i));

	return 0;
}

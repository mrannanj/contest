#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SWAP(a,b) do { \
	char swap_tmp[sizeof(a) == sizeof(b) ? (int)sizeof(a) : -1]; \
	memcpy(swap_tmp, &a, sizeof(a)); \
	memcpy(&a, &b, sizeof(a)); \
	memcpy(&b, swap_tmp, sizeof(a)); \
	} while(0)

#define HEAP_STRUCT(type, id) \
struct heap_##id { \
	type* A; \
	int size; \
	int cap; \
};

#define HEAP_CREATE(type, id) \
void heap_##id##_create(struct heap_ ## id* h, type* A, int cap) { \
	h->A = A; \
	h->cap = cap; \
	h->size = 0; \
}

#define HEAP_DESTROY(type, id) \
void heap_##id##_destroy(struct heap_ ## id* h) { \
	h->A = NULL; \
	h->cap = 0; \
	h->size = 0; \
}

#define HEAP_HEAPIFY(type, id, less) \
void heap_##id##_heapify(struct heap_ ## id* h, int i) { \
	int l = (i<<1) + 1; \
	int r = (i<<1) + 2; \
	int smallest = i; \
	if (l < h->size && less(h->A[l], h->A[smallest])) { \
		smallest = l; \
	} if (r < h->size && less(h->A[r], h->A[smallest])) { \
		smallest = r; \
	} if (smallest != i) { \
		SWAP(h->A[smallest], h->A[i]); \
		heap_##id##_heapify(h, smallest); \
	} \
}

#define HEAP_POP(type, id) \
type heap_##id##_pop(struct heap_ ## id* h) { \
	assert(h->size > 0); \
	type ret = h->A[0]; \
	h->size--; \
	h->A[0] = h->A[h->size]; \
	heap_##id##_heapify(h, 0); \
	return ret; \
}

#define HEAP_PEEK(type, id) \
type heap_##id##_peek(struct heap_ ## id* h) { \
	assert(h->size > 0); \
	return h->A[0]; \
}

#define HEAP_INSERT(type, id, less) \
void heap_##id##_insert(struct heap_ ## id* h, type val) { \
	int p, c; \
	assert(h->size + 1 <= h->cap); \
	c = h->size++; \
	memcpy(&h->A[c], &val, sizeof(val)); \
	for (p = c>>1; less(h->A[c], h->A[p]); c = p, p = c>>1) { \
		SWAP(h->A[p], h->A[c]); \
	} \
}

#define HEAP_DEFINITIONS(type, id, less) \
	HEAP_STRUCT(type, id) \
	HEAP_CREATE(type, id) \
	HEAP_DESTROY(type, id) \
	HEAP_HEAPIFY(type, id, less) \
	HEAP_POP(type, id) \
	HEAP_PEEK(type, id) \
	HEAP_INSERT(type, id, less)

struct edge {
	int64_t w;
	int a;
	int b;
};

#define EDGE_LESS(a, b) (a.w < b.w)

HEAP_DEFINITIONS(struct edge, edge, EDGE_LESS)

struct edge es[200002];
int64_t w[100002];
int ne[100002];
int lup[100002];
int prev[100002];
int st[100002];
int stn;

struct edge djh[200002];

int djikstra(int f, int t) {
	int i, p;
	struct heap_edge he;
	heap_edge_create(&he, djh, 200002);
	prev[f] = 0;
	w[f] = 0;

	p = lup[f];
	for (i = 0; i < ne[f]; ++i) {
		struct edge e = es[p+i];
		prev[e.b] = f;
		w[e.b] = e.w;
		heap_edge_insert(&he, es[p+i]);
	}

	while (he.size > 0) {
		struct edge u = heap_edge_pop(&he);
		if (u.a == t) return 1;
		p = lup[u.b];
		for (i = 0; i < ne[u.b]; ++i) {
			struct edge v = es[p+i];
			if (w[v.b] == -1 || w[u.b] + v.w < w[v.b]) {
				prev[v.b] = v.a;
				w[v.b] = w[v.a] + v.w;
				v.w = w[v.b];
				heap_edge_insert(&he, v);
			}
		}
	}
	return w[t] != -1;
}

int comp(const void* p1, const void* p2) {
	struct edge* e1 = (struct edge*)p1;
	struct edge* e2 = (struct edge*)p2;
	return e1->a - e2->a;
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	m <<= 1;
	for (i = 0; i < m; ++i) {
		int a, b, w; scanf("%d %d %d", &a, &b, &w);
		es[i].w = w;
		es[i].a = a;
		es[i++].b = b;
		ne[a]++;
		es[i].w = w;
		es[i].a = b;
		es[i].b = a;
		ne[b]++;
	}
	qsort(es, m, sizeof(es[0]), comp);
	j = es[0].a;
	lup[j] = 0;
	for (i = 1; i < m; ++i) {
		if (es[i].a > j) {
			j = es[i].a;
			lup[j] = i;
		}
	}
	for (i = 0; i <= n; ++i) w[i] = -1;
	if (djikstra(1, n)) {
		for (i = n; i != 0; i = prev[i]) {
			st[stn++] = i;
		}
		for (i = stn-1; i >= 0; --i) {
			printf("%d ", st[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
	return 0;
}

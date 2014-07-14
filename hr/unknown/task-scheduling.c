#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

struct task {
	int D;
	int M;
	int rank;
	int id;
};

struct task ts[100002];

int comp_task_dl(const void* p1, const void* p2) {
	struct task* t1 = (struct task*)p1;
	struct task* t2 = (struct task*)p2;
	return t1->D - t2->D;
}

int comp_task_id(const void* p1, const void* p2) {
	struct task* t1 = (struct task*)p1;
	struct task* t2 = (struct task*)p2;
	return t1->id - t2->id;
}

#define LSO(S) (S & (-S))

struct FT {
	int64_t N;
	int64_t* A;
};

void ft_create(struct FT* ft, int64_t sz) {
	assert(ft);
	ft->N = sz+1;
	ft->A = (int64_t*)calloc(ft->N, sizeof(int64_t));
}

void ft_destroy(struct FT* ft) {
	assert(ft);
	if (ft->A) free(ft->A);
	ft->A = 0;
	ft->N = 0;
}

int64_t ft_rsq1(struct FT* ft, int64_t b) {
	int64_t sum = 0;
	for (; b; b -= LSO(b)) sum += ft->A[b];
	return sum;
}

int64_t ft_rsq2(struct FT* ft, int64_t a, int64_t b) {
	return ft_rsq1(ft, b) - (a == 1 ? 0 : ft_rsq1(ft, a));
}

void ft_adjust(struct FT* ft, int64_t k, int64_t v) {
	assert(k > 0);
	for (; k <= ft->N; k += LSO(k)) {
		ft->A[k] += v;
	}
}

void ft_adjust2(struct FT* ft, int64_t k, int64_t v) {
	assert(k > 0);
	for (; k <= ft->N; k += LSO(k)) {
		ft->A[k] += v;
	}
}

#define ST_STRUCT_NAME(name) st_##name

#define ST_DEF_STRUCT(type, name) \
struct ST_STRUCT_NAME(name) { \
	int size; \
	struct type* tree; \
};

#define ST_DEF_INIT(type, name) \
void st_##name##_init(struct ST_STRUCT_NAME(name)* st, int size, \
		struct type* tree) { \
	assert(st); \
	st->size = size; \
	st->tree = tree; \
	memset(st->tree, 0, sizeof(tree[0]) * st->size); \
}

#define ST_DEF_UPDATE_R(type, name, split, merge, update) \
void st_##name##_update_r(struct ST_STRUCT_NAME(name)* st, \
		int qs, int qe, int ns, int ne, int i, int64_t x) { \
	struct type left, right; \
	int mid; \
	if (i >= st->size || qs == qe || ns == ne || ne <= qs || qe <= ns) { \
	} else if (qs <= ns && ne <= qe) { \
		update(st->tree[i], x); \
	} else { \
		mid = ns + ((ne-ns)>>1); \
		split(st->tree[i], st->tree[i<<1], st->tree[(i<<1)+1]); \
		st_##name##_update_r(st, qs, qe, ns, mid, i<<1, x); \
		st_##name##_update_r(st, qs, qe, mid, ne, (i<<1)+1, x); \
		merge(st->tree[i], st->tree[i<<1], st->tree[(i<<1)+1]); \
	} \
}

#define ST_DEF_UPDATE(type, name) \
void st_##name##_update(struct ST_STRUCT_NAME(name)* st, \
		int qs, int qe, int64_t x) { \
	st_##name##_update_r(st, qs, qe, 0, st->size>>1, 1, x); \
}

#define ST_DEF_QUERY_R(type, name, split, merge, identity) \
struct type st_##name##_query_r(struct ST_STRUCT_NAME(name)* st, \
		int qs, int qe, int ns, int ne, int i) \
{ \
	struct type left, right, ret; \
	int mid; \
	if (i >= st->size || qs == qe || ns == ne || ne <= qs || qe <= ns) { \
		return identity; \
	} else if (qs <= ns && ne <= qe) { \
		return st->tree[i]; \
	} else { \
		mid = ns + ((ne-ns)>>1); \
		split(st->tree[i], st->tree[i<<1], st->tree[(i<<1)+1]); \
		left = st_##name##_query_r(st, qs, qe, ns, mid, i<<1); \
		right = st_##name##_query_r(st, qs, qe, mid, ne, (i<<1)+1); \
		merge(st->tree[i], st->tree[i<<1], st->tree[(i<<1)+1]); \
		merge(ret, left, right); \
		return ret; \
	} \
}

#define ST_DEF_QUERY(type, name) \
struct type st_##name##_query(struct ST_STRUCT_NAME(name)* st, \
		int qs, int qe) { \
	return st_##name##_query_r(st, qs, qe, 0, st->size>>1, 1); \
}

#define ST_DEF_PRINT(type, name, print) \
void st_##name##_print(struct ST_STRUCT_NAME(name)* st) { \
	int i, lvl_cur = 0, lvl_max = 1; \
	for (i = 1; i < st->size; ++i) { \
		print(st->tree[i]); \
		lvl_cur += 1; \
		if (lvl_cur == lvl_max) { \
			lvl_max <<= 1; \
			lvl_cur = 0; \
			printf("\n"); \
		} \
	} \
	printf("\n"); \
}

#define ST_DEFINITIONS(type, name, split, merge, update, identity, print) \
	ST_DEF_STRUCT(type, name) \
	ST_DEF_INIT(type, name) \
	ST_DEF_UPDATE_R(type, name, split, merge, update) \
	ST_DEF_UPDATE(type, name) \
	ST_DEF_QUERY_R(type, name, split, merge, identity) \
	ST_DEF_QUERY(type, name) \
	ST_DEF_PRINT(type, name, print)

struct st_nmax {
	int64_t add;
	int64_t max;
};

struct st_nmax identity_max = { 0, (int64_t)-1e12 };

#define MERGE_MAX(root, left, right) do { \
	root.max = MAX(left.max, right.max); \
	root.add = 0; \
} while(0)

#define SPLIT_MAX(root, left, right) do { \
	left.add += root.add; \
	left.max += root.add; \
	right.add += root.add; \
	right.max += root.add; \
	root.add = 0; \
} while(0)

#define UPDATE_MAX(n, val) do { \
	n.max += val; \
	n.add += val; \
} while(0)

#define PRINT_MAX(n) do { \
	printf("(%ld, %ld) ", n.max, n.add); \
} while(0)

ST_DEFINITIONS(st_nmax, max, SPLIT_MAX, MERGE_MAX, UPDATE_MAX,
		identity_max, PRINT_MAX)

struct st_nmax A[1<<19];

int main() {
	int i, T;
	struct FT time_sums;
	ft_create(&time_sums, 100002);
	struct st_max st;
	st_max_init(&st, 1<<18, A);
	
	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		ts[i].id = i;
		scanf("%d %d", &ts[i].D, &ts[i].M);
	}
	qsort(ts, T, sizeof(struct task), comp_task_dl);
	for (i = 0; i < T; ++i) ts[i].rank = i+1;
	qsort(ts, T, sizeof(struct task), comp_task_id);
	st_max_update(&st, 0, 1<<18, -1e12);

	for (i = 0; i < T; ++i) {
		ft_adjust(&time_sums, ts[i].rank, ts[i].M);
		int64_t b = ft_rsq1(&time_sums, ts[i].rank) - ts[i].D;
		int64_t a = st_max_query(&st, ts[i].rank, ts[i].rank+1).max;
		st_max_update(&st, ts[i].rank, ts[i].rank+1, b - a);
		st_max_update(&st, ts[i].rank+1, 1<<18, ts[i].M);
		printf("%ld\n", MAX(0, st_max_query(&st, 0, 1<<18).max));
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[10001];
int rank_[10001];

int cmp(const void *a, const void *b) {
    Edge *x = (Edge *)a;
    Edge *y = (Edge *)b;
    return x->w - y->w;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (rank_[a] < rank_[b])
        parent[a] = b;
    else if (rank_[a] > rank_[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank_[a]++;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Edge *edges = (Edge *)malloc(M * sizeof(Edge));

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    qsort(edges, M, sizeof(Edge), cmp);

    long long mst = 0;

    for (int i = 0; i < M; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            mst += edges[i].w;
        }
    }

    printf("%lld\n", mst);

    free(edges);

    return 0;
}
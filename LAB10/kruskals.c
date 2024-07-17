#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p1, const void* p2)
{
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;

    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] != component) {
        parent[component] = findParent(parent, parent[component]);
    }
    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int n, int edges[][3], int e)
{
    qsort(edges, e, sizeof(edges[0]), comparator);

    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);

    int minCost = 0;

    printf("Following are the edges in the constructed MST\n");
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        int parent_u = findParent(parent, u);
        int parent_v = findParent(parent, v);

        if (parent_u != parent_v) {
            unionSet(parent_u, parent_v, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", u, v, wt);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main()
{
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int edges[e][3];
    printf("Enter the edges (u v wt):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskalAlgo(n, edges, e);

    return 0;
}

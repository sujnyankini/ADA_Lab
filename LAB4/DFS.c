#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int s[MAX_VERTICES] = {0};
int res[MAX_VERTICES];
int j = 0;

void DFS(int u, int n, int a[MAX_VERTICES][MAX_VERTICES]) {
    s[u] = 1;
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            DFS(v, n, a);
        }
    }
    res[j++] = u;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int u = 0; u < n; u++) {
        if (s[u] == 0) {
            DFS(u, n, a);
        }
    }

    printf("Topological order: ");
    for (int i = j - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}


#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int stack[10], top = -1;

void computeIndegree(int n, int a[][10]) {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }
}

void tps_SourceRemoval(int n, int a[][10]) {
    int i, v, k = 0;
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        v = stack[top--];
        t[k++] = v;
        for (i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    if (k != n) {
        printf("Graph has a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Sort (Source Removal): ");
        for (i = 0; i < n; i++) {
            printf("%d ", t[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    return 0;
}

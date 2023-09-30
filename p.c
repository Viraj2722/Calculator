#include<stdio.h>

int a[20][20], q[20], visited[20], n, f = -1, r = -1;

void bfs(int v) {
  int i;
  for (i = 0;i < n;i++) {
    if (a[v][i] != 0 && visited[i] == 0) {
      r = r + 1;
      q[r] = i;
      visited[i] = 1;
      printf("%d  ", i);
    }
  }
  f = f + 1;
  if (f <= r)
    bfs(q[f]);
}

void dfs(int v) {
  int i;
  for (i = 0;i < n;i++) {
    if (a[v][i] != 0 && visited[i] == 0) {
      visited[i] = 1;
      printf("%d  ", i);
      dfs(i);
    }
  }
}

int main() {
  int opt, v, i, j;;
  printf("**Menu**\n1)BFS\n2)DFS\n");
  scanf("%d", &opt);
  switch (opt) {
  case 1:
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for (i = 0;i < n;i++) {
      visited[i] = 0;
    }
    printf("\nEnter graph data in matrix form:\n");
    for (i = 0;i < n;i++)
      for (j = 0;j < n;j++)
        scanf("%d", &a[i][j]);
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    f = r = 0;
    q[r] = v;
    printf("\nBFS traversal is:\n");
    visited[v] = 1;
    printf("%d ", v);
    bfs(v);
    if (r != n - 1)
      printf("\nBFS is not possible");
    break;
  case 2:
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0;i < n;i++) {
      visited[i] = 0;
    }
    printf("\nEnter graph data in matrix form:\n");
    for (i = 0;i < n;i++)
      for (j = 0;j < n;j++)
        scanf("%d", &a[i][j]);
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    printf("\nDFS traversal is:\n");
    visited[v] = 1;
    printf("%d ", v);
    dfs(v);
  default:
    break;
  }
}
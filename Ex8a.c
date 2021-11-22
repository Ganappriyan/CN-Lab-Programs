/* Implementation of Link State Routing */

#include <stdio.h>

void main()
{
  int n, a[10][10], i, j, k;
  printf("Enter no of nodes: ");
  scanf("%d", &n);
  printf("Enter matrix elements: ");
  for (i = 0; i < n; i++)
  {
    printf("\nEnter distance for node: %d\n", i + 1);
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  }

  for (i = 0; i < n; i++)
  {
    printf("Link state packets for node: %d\n", i + 1);
    printf("Node\tDistance\n");
    for (j = 0; j < n; j++)
    {
      if (a[i][j] != 0 && a[i][j] != -1)
        printf("%d\t%d\n", j + 1, a[i][j]);
    }
    printf("\n\n");
  }
}
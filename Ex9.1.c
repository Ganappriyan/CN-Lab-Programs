/* Distance Vector Routing */

#include <stdio.h>

void main()
{
  int i, j, k, n, a[10][10], b[10][10], src, s, d;
  char ch;
  printf("Enter Number of Nodes: ");
  scanf("%d", &n);
  printf("Enter Distance between Hosts:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i == j)
        a[i][j] = 0;
      else
      {
        printf("%d and %d : ", i, j);
        scanf("%d", &a[i][j]);
      }
    }
  }
  printf("\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d\t", a[i][j]);
    printf("\n");
  }
  do
  {
    printf("\nEnter Node to Display Routing table: ");
    scanf("%d", &src);
    printf("\nThe Shortest Paths are:");
    for (j = 1; j <= n; j++)
    {
      if (src != j)
      {
        if (a[src][j] != 0)
          printf("\n%d to %d = %d", src, j, a[src][j]);
        else
          printf("\nNo path from %d to %d", src, j);
      }
    }
    printf("\nDo u want to continue(y/n) : ");
    scanf("%s", &ch);
  } while (ch != 'n');
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (a[i][j] > a[i][k] + a[k][j])
          a[i][j] = a[i][k] + a[k][j];
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d\t", a[i][j]);
    printf("\n");
  }
}

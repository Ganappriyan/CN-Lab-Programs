#include <stdio.h>

void main()
{
  int p[10][10], g[10][10], m[10][10], ht[10][10], y[10][10], s[10][10], pt[10][10];
  int c[10][10], h[10][10], e[10][10];
  int i, j, n, k, t, temp, a;
  printf("\nEnter the Values of n and k: ");
  scanf("%d%d", &n, &k);
  printf("\nEnter the Parity matrix\n");
  for (i = 0; i <= k - 1; i++)
  {
    for (j = 0; j <= n - k - 1; j++)
    {
      printf("p[%d][%d]=", i, j);
      scanf("%d", &p[i][j]);
    }
  }
  for (i = 0; i <= k - 1; i++)
  {
    for (j = 0; j <= n - k - 1; j++)
      g[i][j] = p[i][j];
    for (j = n - k; j <= n - 1; j++)
    {
      if (j - i == n - k)
        g[i][j] = 1;
      else
        g[i][j] = 0;
    }
  }

  /*The generator matrix*/
  for (i = 0; i <= k - 1; i++)
  {
    for (j = 0; j <= n - 1; j++)
      printf("%d\t", g[i][j]);
    printf("\n");
  }
  printf("\nEnter the Message Matrix:");
  for (i = 0; i < 1; i++)
  {
    for (j = 0; j <= k - 1; j++)
      scanf("%d\t", &m[i][j]);
  }
  scanf("%d", &temp);
  printf("\n\n");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= k - 1; j++)
      printf("%d\t", m[i][j]);
    printf("\n");
  }
  /*MAT MUL*/
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
    {
      c[i][j] = 0;
      for (t = 0; t <= n - 1; t++)
        c[i][j] = c[i][j] + (m[i][t] * g[t][j]);
    }
  }
  printf("\nThe possible codewords are");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
      printf("%d\t", c[i][j]);
    printf("\n");
  }
  printf("\n Enter the received word");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
      scanf("%d\t", &y[i][j]);
  }
  printf("\n\n");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
      printf("%d\t", y[i][j]);
    scanf("%d", &a);
    printf("\n");
  }
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
    {
      if (y[i][j] == c[i][j])
        e[i][j] = 0;
      else
        e[i][j] = 1;
    }
  }
  printf("\nThe error matrix");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
      printf("%d", e[i][j]);
    printf("\n");
  }
  for (i = 0; i <= k - 1; i++)
    for (j = 0; j <= n - k - 1; j++)
      pt[j][i] = p[i][j];
  for (i = 0; i <= n - k - 1; i++)
  {
    for (j = 0; j <= k - 1; j++)
      printf("%d\t", pt[i][j]);
    printf("\n");
  }
  for (i = 0; i <= n - k - 1; i++)
  {
    for (j = 0; j <= n - 1; j++)
    {
      if (j <= n - k - 1)
      {
        if (i == j)
          h[i][j] = 1;
        else
          h[i][j] = 0;
      }
      else
        h[i][j] = pt[i][j - n + k];
      printf("%d\t", h[i][j]);
    }
    printf("\n");
  }
  /*mattranspose(int h,int ht);*/
  for (i = 0; i <= n - k - 1; i++)
  {
    for (j = 0; j <= n - 1; j++)
      ht[j][i] = h[i][j];
    printf("\n");
  }
  printf("\n H-transpose\n\n");
  for (i = 0; i <= n - 1; i++)
  {
    for (j = 0; j <= n - k - 1; j++)
      printf("%d\t", ht[i][j]);
    printf("\n");
  }
  /*matmul(int y,int ht,int s); */
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - k - 1; j++)
    {
      s[i][j] = 0;
      for (t = 0; t <= n - k - 1; t++)
        s[i][j] = s[i][j] + (e[i][t] * ht[t][j]);
    }
  }
  printf("\n The syndrome matrix\n");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - k - 1; j++)
      printf("%d", s[i][j]);
  }
  int count = -1, flag = 0;
  for (i = 0; i <= n - 1; i++)
  {
    ++count;
    for (j = 0; j <= n - k - 1; j++)
    {
      if (s[0][j] == ht[i][j])
        flag = 1;
      else
        flag = 0;
    }
    if (flag == 1)
      break;
  }
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
    {
      if (j == count)
      {
        if (y[i][j] == 1)
          y[i][j] = 0;
        if (y[i][j] == 0)
          y[i][j] = 1;
      }
    }
  }
  printf("The error bit is %d", count);
  printf("\nThe corrected matrix\n");
  for (i = 0; i <= 0; i++)
  {
    for (j = 0; j <= n - 1; j++)
      printf("%d\t", y[i][j]);
  }
}
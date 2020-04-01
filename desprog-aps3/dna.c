#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t)
{
  if (fscanf(file, "%d", p) != 1)
  {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }

  char c;
  do
  {
    c = getc(file);
  } while (c != '\n');

  fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1])
{
  if (n == 0 || m == 0)
  {
    length[n][m] = 0;
    return 0;
  }
  if (length[n][m] != -1)
  {
    return length[n][m];
  }
  if (a[n - 1] == b[m - 1])
  {
    length[n][m] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
    return length[n][m];
  }
  else
  {
    int x = mlcs_w(a, n - 1, b, m, length);
    int y = mlcs_w(a, n, b, m - 1, length);

    length[n][m] = (x > y) ? x : y;
    return length[n][m];
  }
}

int mlcs(char a[], int n, char b[], int m)
{
  int length[MAX_SIZE + 1][MAX_SIZE + 1];
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      length[i][j] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m)
{
  int length[n + 1][m + 1];
  for (int i = 0; i < n + 1; i++)
  {
    length[i][0] = 0;
  }
  for (int j = 1; j < m + 1; j++)
  {
    length[0][j] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i] == b[j])
      {
        length[i + 1][j + 1] = length[i][j] + 1;
      }
      else
      {
        if (length[i][j + 1] > length[i + 1][j])
        {
          length[i + 1][j + 1] = length[i][j + 1];
        }
        else
        {
          length[i + 1][j + 1] = length[i + 1][j];
        }
      }
    }
  }
  return length[n][m];
}
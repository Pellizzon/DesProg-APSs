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
    return 0;
  }
  if (length[n - 1][m - 1] != -1)
  {
    return length[n - 1][m - 1];
  }
  if (a[n - 1] == b[m - 1])
  {
    length[n - 1][m - 1] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
    return length[n - 1][m - 1];
  }
  else
  {
    int x = mlcs_w(a, n - 1, b, m, length);
    int y = mlcs_w(a, n, b, m - 1, length);

    length[n - 1][m - 1] = (x > y) ? x : y;
    return length[n - 1][m - 1];
  }
}

int mlcs(char a[], int n, char b[], int m)
{
  int length[MAX_SIZE + 1][MAX_SIZE + 1];
  for (int i = 0; i < MAX_SIZE + 1; i++)
  {
    for (int j = 0; j < MAX_SIZE + 1; j++)
    {
      length[i][j] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m)
{
  int length[MAX_SIZE + 1][MAX_SIZE + 1];
  for (int i = 0; i < MAX_SIZE + 1; i++)
  {
    for (int j = 0; j < MAX_SIZE + 1; j++)
    {
      length[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 || j == 0)
      {
        length[i][j] = 0;
      }

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
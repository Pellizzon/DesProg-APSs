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
  int x = 0;
  int y = 0;
  if (n == 0 || m == 0)
  {
    length[n][m] = 0;
  }
  else if (a[n - 1] == b[m - 1])
  {
    length[n][m] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
  }
  else
  {
    x = mlcs_w(a, n - 1, b, m, length);
    y = mlcs_w(a, n, b, m - 1, length);
    if (x > y)
    {
      length[n][m] = x;
    }
    else
    {
      length[n][m] = y;
    }
  }
  return length[n][m];
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

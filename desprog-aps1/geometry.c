#include <math.h>

#include "geometry.h"

int inAresta(point p, point a, point b)
{
  double distAP = sqrt(pow((p.x - a.x), 2) + pow((p.y - a.y), 2));
  double distBP = sqrt(pow((p.x - b.x), 2) + pow((p.y - b.y), 2));
  double distAB = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));

  if (fabs(distAP + distBP - distAB) <= 0.000001)
  {
    return 1;
  }
  return 0;
}

int RelativePos(point p, point a, point b)
{
  //y = m*x + n
  double m;
  double Dx = a.x - b.x;
  double Dy = a.y - b.y;

  m = Dy / Dx;

  double n = a.y - m * a.x;

  double x_reta = (p.y - n) / m;

  if (x_reta >= p.x)
  {
    return 1;
  }
  return 0;
}

int verify(point p, point a, point b)
{
  if (inAresta(p, a, b))
  //verifica se a distância entre os segmentos AP e BP equivalem a AB
  {
    return 2;
  }
  else if ((a.y >= p.y && b.y >= p.y) || (a.y < p.y && b.y < p.y))
  //verifica casos em que a aresta está totalmente acima ou abaixo de P
  {
    return 0;
  }
  else if (a.x == b.x)
  //verifica casos em que a reta só é em y (|)
  {
    if (a.x >= p.x)
    //se o x de qualquer um dos pontos de AB for maior que p.x, o ray casting irá cruzar AB
    {
      return 1;
    }
  }
  else if ((p.y == a.y || p.y == b.y))
  //análise de casos em que o ponto está alinhado com um dos pontos A ou B
  {
    if (a.y == p.y)
    //Se estiver alinhado com A, avalia se o ponto está a direita ou esquerda, validando se irá cruzar ou não
    {
      if (a.x <= p.x)
      {
        return 0;
      }
    }
    else if (b.y == p.y)
    //Se estiver alinhado com B, avalia se o ponto está a direita ou esquerda, validando se irá cruzar ou não
    {
      if (b.x <= p.x)
      {
        return 0;
      }
    }
    return 1;
  }
  return RelativePos(p, a, b);
  //se o x da reta for maior que o x do ponto, significa que o ray casting irá cruzar AB
}

int inside(point p, point poly[], int n)
{
  int primeira = 1;
  int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (primeira)
    {
      count += verify(p, poly[i], poly[n - 1]);
      primeira = 0;
      if (verify(p, poly[i], poly[n - 1]) == 2)
      {
        return 1;
      }
    }
    count += verify(p, poly[i], poly[i + 1]);
    if (verify(p, poly[i], poly[i + 1]) == 2)
    {
      return 1;
    }
  }
  if (count % 2 == 1)
  {
    return 1;
  }
  return 0;
}
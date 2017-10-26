
#include <stdio.h>
float abs(int a)
{
  if(a < 0) return -a;
  else return a;
}

float equation(float x, int xKare, int xDuz, int sabit)
{
  return x*x*xKare+x*xDuz+sabit;
}

void fonksiyon(int xKare, int xDuz, int sabit, float dom1, float dom2)
{
  scanf("%d %d %d %f %f", &xKare, &xDuz, &sabit, &dom1, &dom2);

  printf("Entered equation: %dx^2 + %dx + %d \nDomain: %.0f %.0f\n", xKare, xDuz, sabit, dom1, dom2);
}

float bisection(int xKare, int xDuz, int sabit, float dom1, float dom2)
{
  float x;
  float root1, root2;
  int asalDom1, asalDom2;

  float tepenoktasi = (dom1 + dom2)/2;

  tepenoktasi = -(xDuz/2*xKare);

  while(abs(equation(tepenoktasi,xKare, xDuz, sabit)) > 0.001)
  {
    if(equation(dom1,xKare, xDuz, sabit)*equation(tepenoktasi,xKare, xDuz, sabit) < 0)
    {
      dom2 = tepenoktasi;
      tepenoktasi = (dom1 + dom2)/2;
    }
    else
    {
      dom1 = tepenoktasi;
      tepenoktasi = (dom1 + dom2)/2;
    }
  }

  return tepenoktasi;
}
void findRoots()
{
  int xKare, xDuz, sabit;
  float dom1, dom2, x;
  int asalDom1, asalDom2;
  float root1, root2;
  float tepenoktasi;

  asalDom1 = dom1;
  asalDom2 = dom2;

  tepenoktasi = bisection(xKare, xDuz, sabit, dom1, dom2);

  root1 = tepenoktasi;
  if(xKare != 0)root2 = (-xDuz/xKare)-tepenoktasi;

  if(asalDom1<root1 && root1<asalDom2 && asalDom1<root2 && root2<asalDom2 && xKare != 0)
  {
    printf("Roots: x=%.3f, x=%.3f\n", root1, root2);
  }
  else if(asalDom1<root1 && root1<asalDom2)
  {
    printf("Root: x=%.3f\n", root1);
  }
  else if(asalDom1<root2 && root2<asalDom2)
  {
    printf("Root: x=%.3f\n", root2);
  }
  else
  {
    printf("No roots found\n");
  }

}

int main(){
  int xKare, xDuz, sabit;
  float dom1, dom2, x;
  int i;
  float root1, root2;
  int asalDom1, asalDom2;

  fonksiyon(xKare, xDuz, sabit, dom1, dom2);

  float tepenoktasi = -(xDuz/2*xKare);

  if(xDuz*xDuz-4*xKare*sabit < 0)
  {
    printf("No roots found\n");
    return 0;
  }

  findRoots();

  return 0;
}

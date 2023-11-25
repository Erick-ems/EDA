#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A=B; B=t;}
#define cmpexch(A,B) if(less(A,B)) exch(A,B)

void bubblesort(Item *v,int l,int r)
{
  for(int i=l;i<r;i++)
    for(int j=l+1;j<=r;j++)
      cmpexch(v[j-1],v[j]);
}

int main(void)
{
  int t;
  int r;
  r=scanf("%d",&t);
  Item *v=(Item *)malloc(t*sizeof(Item));
  for(int i=0;i<t;i++)
    r=scanf("%d",&v[i]);

  bubblesort(v,0,t-1);

  for(int i=0;i<t;i++)
    r=printf("%d\n",v[i]);

  return 0;
}
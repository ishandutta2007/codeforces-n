#include<cstdio>
int n, s, t;


int main(){
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &t), s+=t;
  printf("%.20f\n", (double)s/n);

  return 0;
}
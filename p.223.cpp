#include <iostream>

int n;
int d[1001];

int main(){
  scanf("%d", &n);

  d[1]=1; d[2]=3;
  for(int i=3; i<=n; i++){
    d[i]=(d[i-1]+2*d[i-2])%796796;
  }

  printf("%d", d[n]);

  return 0;
}
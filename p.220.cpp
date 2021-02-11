#include <iostream>

int x;
int arr[30001];

int make_1(int target){
  int ret=INT_MAX;
  if(target==1 || arr[target]!=0){
    return arr[target];
  }
  if(target%5==0){
    if(ret>make_1(target/5)+1)
      ret=make_1(target/5)+1;
  }
  if(target%3==0){
    if(ret> make_1(target/3)+1)
      ret=make_1(target/3)+1;
  }
  if(target%2==0){
    if(ret>make_1(target/2)+1)
      ret=make_1(target/2)+1;
  }
  if(ret>make_1(target-1)+1)
    ret=make_1(target-1)+1;

  arr[target]=ret;

  return ret;
}

int main(){
  scanf("%d", &x);
  for(int i=1; i<=x; i++){
    arr[i]=0;
  }
  printf("%d",make_1(x));

  return 0;
}
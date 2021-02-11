#include <iostream>
#include <vector>
#include <algorithm>

int n,m;
int d[10001];
std::vector<int> arr;


int min_bill(int target){
  //bottomup으로 하려면 사용할 수 있는 값이 arr에 저장되어 있다는 점을 이용해야 함.
  //for문 중첩을 써서 각 값에서 어떤 화폐를 썼을 때 최소인지 비교하면서...
  
  if(d[target]==-1 || target<1){
    return -1;
  }
  if(d[target]!=INT_MAX){
    return d[target];
  }
  
  for(int i=0;i<n; i++){
    int temp=min_bill(target-arr[i]);
    if(temp==-1)
      continue;
    d[target]=std::min(d[target], temp+1);
  } 

  if(d[target]==INT_MAX)
    d[target]=-1;

  return d[target];
}
int main(){
  scanf("%d", &n);
  scanf("%d", &m);

  for(int i=1; i<=m; i++){
    d[i]=INT_MAX;
  }

  for(int i=0; i<n; i++){
    int temp;
    scanf("%d", &temp);
    arr.push_back(temp);
    d[temp]=1;//다이나믹으로 할 때 항상 초기값 지정했는지 확인할 것.
  }
  
  printf("%d\n", min_bill(m));
  return 0;
}
#include <iostream>
#include <algorithm>

int N, M;
int arr[20][20];

int main(){
  std::cin>>N>>M;
  int ret[20];
  for(int i=0; i<N; i++){
    ret[i]=0;
    for(int j=0; j<M; j++){
      int val;
      std::cin>>val;
      arr[i][j]=val;
    }
  }

  for(int i=0; i<M-1; i++){
    for(int j=0; j<N; j++){
      for(int k=j-1; k<=j+1; k++){
        if(k<0 || k>=N) continue;
        if(arr[j][i]+arr[k][i+1]>ret[k])
          ret[k]=arr[j][i]+arr[k][i+1];
      }
    }
    for(int j=0; j<N; j++)
      arr[j][i+1]=ret[j];
  }  
  
  printf("%d",*std::max_element(ret, ret+N));

  return 0;
}